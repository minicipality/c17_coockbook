#include <iostream>
#include <tuple>
#include <chrono>
#include <vector>
#include <map>
#include <mutex>
#include <memory>

#include "templates.h"
#include "conteiners_STL.h"
//#include <execution>
//#include <filesystem>

//#include <experimental/>

//using namespace std::experimental;

std::pair<int, int> divide_reminder(int dividend, int divisor) 
{
	return std::pair<int, int>();
}

std::tuple<int, int> divide_reminder_tuple(int dividend, int divisor)
{
	return std::tuple<int, int>();
} 

// ������� ����� ���� �������
template <typename T1, typename T2, typename T3>
class my_wrapper
{
	T1 t1; 
	T2 t2;
	T3 t3;
public:
	explicit my_wrapper(T1 _t1, T2 _t2, T3 _t3)
		: t1{ _t1 }, t2{ _t2 }, t3{ _t3 }
	{

	}
};

// ��������� ���������� ���������� ���������� � ��������� � ������� ��������� �������
template <typename T>
struct summer {
	T value;
	template <typename ... Ts>
	summer(Ts&& ... values) : value{ (values + ...) } {};
};

// ����� �������� ����
template <typename ... Ts>
summer(Ts&& ... ts)->summer<std::common_type_t<Ts... >> ;

// ����� ���������� �++17
void newFunctionalInC17()
{
	// ---------------------------------------------------------------------------------------------------
	// 1. ���������� ����������������� �������� (������������) ��� ���������� ������ ������������ ��������

	// 1.1 for std::pair : C++14
	const auto result(divide_reminder(16, 3));
	std::cout << "16 / 3 is " << result.first << "..." << result.second << "\n";

	auto[fraction, reminder] = divide_reminder(16, 3);
	std::cout << "16 / 3 is " << fraction << "..." << reminder << "\n";

	// 1.2 for std::tuple
	//std::tuple<std::string, std::chrono::system_clock::time_point, unsigned> stock_info(const std::string &name);
	const auto[fraction2, reminder2] = divide_reminder_tuple(16, 3); // stock_info("INIC");

	// 1.3 ���������������� ���������
	struct employee {
		unsigned id;
		std::string name;
		std::string role;
		unsigned salary;
	};

	std::vector<employee> employees{};
	for(auto &[id, name, role, salary] : employees)
	{
		//std::cout << name;
	}

	std::map<std::string, size_t> animals{};
	for (auto &[species, count] : animals)
	{
		//std::cout << name;
	}

	int reminder3;
	std::tie(std::ignore, reminder3) = divide_reminder_tuple(16, 3);

	// ---------------------------------------------------------------------------------------------------
	// 2. ������������ ������� ��������� ���������� � if � switch
#if 0
	employee  c;
	if (auto itr(std::find(employees.begin(), employees.end(), c)); itr != employees.end())
	{

	}
	else {}

	switch (char c(getchar()); c) {
	//case 'a': move_left(); break;
	}
#endif

	// ������������ ������� ��������� ����������� ������
	std::mutex my_mutex;
	if (std::lock_guard<std::mutex> lg(my_mutex); true) // �����-�� �������
	{
		// ������ ���-��
	}
	
	// ������� ��������� ������ ����������
	std::shared_ptr<int> shared_pointer;
	std::weak_ptr<int> weak_pointer;
	if (auto shared_pointer(weak_pointer.lock()); shared_pointer != nullptr)
	{
		// ��, ����� ������ ��� ����������
	}
	else {
		// � ��������� shared_pointer ����� �������� ������, �� �� �������� �������
	} // � shared_pointer ������ ������ �������� ������


	// ---------------------------------------------------------------------------------------------------
	// 3. ����� ������� ������������� ��������� ��������

	auto n{123};

	// auto m{ 1, 2 }; - ������������ - ��������� ��� ����������������
	auto m = {1, 2, 3}; // initializer_list<int>

	int i(1.2); // ���������� ������� ��������������
	// int i_1{1.3}; - �� ��������������, ��������� ������ ����� ��������������� ���� ������������ (��� �������� ��������������)

	// ---------------------------------------------------------------------------------------------------
	// 4. ��������� ������������ ������������� �������� ���������� ��� ������ �������
	my_wrapper wrap{123, 1.23, "marina"};

	my_wrapper<int, double, std::string> wrap_old{ 123, 1.23, "marina" }; // C++11/14

	//
	summer s{1u, 2.0, 3, 4.f};
	summer string_sum{ std::string{"abs"}, std::string{"fed"} };

	std::cout << s.value;// << '\n' << string_sum.value << '\n';
	//std::cout << string_sum.value;
}

//static void useConstexpr();
//static void useSvertka();
class Temporary
{
public:
	Temporary(const char &_data) {
		memcmp(data, &_data, 1024);
	};
	~Temporary() {};

private:
	char data[1024];
};
int main(int argv, char* argc[])
{

	//useConstexpr();
	//useSvertka();
	//erase_remove();
	//use_quick_remove();
	//sort_vector();
	//insert_to_map();
	//new_hint_map();
	//change_key_map();
	//use_unordered_map();
	//filter_set();
	//rpn_calculate();
	//use_filter_punctuation();
	//use_filter_sentence();
	//use_priority_queue();

	system("pause");

	return 0;
}