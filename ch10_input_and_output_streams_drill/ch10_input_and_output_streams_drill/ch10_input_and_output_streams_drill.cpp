#include "pch.h"
#include <iostream>
#include <string>

#include "point.h"

void test_point()
{
	Point<int, int> o;	//default
	Point<int, int> p{ 1, 2 };	//arg
	Point<int, int> q{ p };	//copy
	Point<int, int> r = q;	//copy
	r = p;	//operator=
	std::cout << p << '\n';
}

void prompt_user()
{
	static char const BAR[] = { "-------------------------------------------------------------" };
	std::cout << BAR << '\n' << "Please enter a set of points in the format:\n"
		<< "first space second space first space second space...\n"
		<< "When complete send an end of file character.\n"
		<< BAR << '\n';
}

int main(int argc, char*argv[])
{
	test_point();
	prompt_user();
	Point<std::string, std::string> s;
	while (!std::cin.eof())
	{
		std::cin >> s;
		if (std::cin.good())
			std::cout << s << '\n';
		if (std::cin.bad())
			break;
		if (std::cin.fail()) {
			std::string trash;
			std::cin.clear();
			std::getline(std::cin, trash);
		}
	}
}