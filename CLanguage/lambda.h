#pragma once

#include <iostream>
#include <string>

void use_lambda_befor_11()
{
	struct name_greeter {
		std::string name;
		void operator()() {
			std::cout << "Greeter " << name << std::endl;
		}
	};

	name_greeter greet_john{"John Doe"};
	greet_john();
}

void use_lambda_after_11()
{
	auto greet_john_doe([] {
		std::cout << "Hello, John Doe!" << std::endl;
	});

	greet_john_doe();
}

void dinamic_defenition_lambda()
{
	auto just_one([]() {return 1; });
	auto just_two([]   {return 2; });

	std::cout << just_one() << ", " << just_two() << std::endl;

	auto plus([](auto l, auto r) {return(l + r); });

	std::cout << plus(1, 2) << std::endl;
	std::cout << plus(std::string{"a"}, "b") << std::endl;

	std::cout << [](auto l, auto r) {return(l + r); }(1, 2) << std::endl;

	// ���������� mutable, ����� ��������� �������� ����������� ����������
	auto counter([count = 0] () mutable { return ++count; });

	for (size_t i{ 0 }; i < 5; ++i) {
		std::cout << counter() << ", ";
	}
	std::cout << std::endl;

	// ����� ����� ������������ ���������� � ��������� �� �� ������ (����� �� ��������� ����� �������� ��� ���������)
	int a{0};
	auto increment([&a] {++a; });
	increment();
	increment();
	increment();
	std::cout << "Value of 'a' after 3 increment() calls " << a << std::endl;

	// ������������ - ����� �������, ����������� ��������� ���������, � ����� ��������� �� � ������ ������� �������, ��������� ������ ����������
	auto plus_ten([=](int x) {return plus(10, x); });
	std::cout << plus_ten(5) << std::endl;
}