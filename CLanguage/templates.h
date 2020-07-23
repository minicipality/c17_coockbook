#pragma once
// ����������� ������� ��� ������ � ������ 
#include <type_traits>
#include <vector>


/* ������������ ������� ����� �������������� � �������� ������� � ��� �� ������ */
/* ������� ���������� ���������� ������������ ����������� ������� ���, ������� ������������ �� ������� */
int max(int a, int b)
{
	return b < a ? a : b;
}

template<typename T>
T max(T a, T b)
{
	return b < a ? a : b;
}

/* ��� �������� ������ ����, ���� ����� ����� ���� �������� */
template<typename T1, typename T2>
auto maxPossible(T1 a, T2 b)
{
	return b < a ? b : a;
}

template<typename T1, typename T2>
auto maxDecltype(T1 a, T2 b) -> decltype(true ? a : b)
{
	return b < a ? b : a;
}

/*	-> typename std::decay<decltype(true?a:b)>::type
*	����������� ������������ ���
*	trailing return type
*/

/* ���� ������������ ��� ���������, ����� �������� ��� � ������� std::decay */
template<typename T1, typename T2>
auto maxAuto(T1 a, T2 b) -> typename std::decay<decltype(true ? a : b)>::type // C++14
//auto maxAuto(T1 a, T2 b) -> typename std::decay_t<decltype(true ? a : b)> // C++17
{
	return b < a ? b : a;
}

/* ������������ ��� ��� ����� ��� */
template<typename T1, typename T2>
typename std::common_type<T1, T2>::type maxCommon(T1 a, T2 b) // C++14
//std::common_type_t<T1, T2> maxCommon(T1 a, T2 b) // C++17
{
	return b < a ? b : a;
}

/* ��������� ������� �� ��������� */
template<typename T1, typename T2, typename RT = std::decay_t<decltype(true ? T1() : T2())>>
RT maxdefault(T1 a, T2 b)
{
	return b < a ? b : a;
}

template<typename Container, typename Index>
decltype(auto) getVecElem(Container &c, Index ind)
{
	return c[ind];
}