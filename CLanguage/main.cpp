#include <iostream>
#include <tuple>
#include <chrono>
#include <vector>
#include <map>
#include <mutex>
#include <memory>

#include "templates.h"
#include "conteiners_STL.h"
#include "lambda.h"
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

#define SQ(X) X*X

void use_conteiner_STL() 
{
	// 1. ������ erase-remove ��� ���������� std::vector
	//erase_remove();

	// 2.������� �������� �� ������������������ ������� ������ std::vector �(1)
	//use_quick_remove();

	// 4. ��������� ���������� ����������� ������ stD::vector
	//sort_vector();

	// 5. ��������� �������� � ��������� std::map ���������� � � ������������ � ���������
	//insert_to_map();

	// 6. ��������� ����� ��������� ��������� ��� ������� ��������� � ������� ������ std::map::insert
	//new_hint_map();

	// 7. ���������� �������� ����� ��������� std::map
	//change_key_map();

	// 8. ��������� ��������� std::unordered_map ��� ���������������� �����
	//use_unordered_map();

	// 9. ��������� ������������� ����� �� ����������������� ����� � ������� �� �� ����� � ���������� ������� � ������� ���������� std::set
	//filter_set();

	// 10. ������� opn-����������� � ������������� ���������� std::stack
	//rpn_calculate();

	// 11. ������������ ������� ������������� ���� � ����������� ���������� std::map
	//use_filter_punctuation();

	// 12. �������������� �������������� �������� ��� ������ ������� ����������� � ������� � ������� std::multimap
	//use_filter_sentence();

	// 13. ������ ������ ������� ��� � ������� std::priority_queue
	//use_priority_queue();	
}

void use_lambda() 
{
	// 1. ������������� ������ ��������� �� �++11
	//use_lambda_befor_11();

	// 2. ������������� ������ ��������� ����� �++11
	//use_lambda_after_11();

	// 3. ������������ ���������� ������� � ������� ������-���������
	dinamic_defenition_lambda();
}

int main(int argv, char* argc[])
{
	//useConstexpr();
	//useSvertka();

	use_conteiner_STL();
	use_lambda();


	system("pause");

	return 0;
}