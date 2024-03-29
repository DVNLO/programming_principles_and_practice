/* The following is an loose solution to chapter 10's drill. */

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
	std::vector<Point<std::string, std::string>> points;
	Point<std::string, std::string> s;
	while (!std::cin.eof())	// collect points from user
	{
		std::cin >> s;
		points.push_back(s);
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
	
	static const char FILENAME[] = "output.txt";

	std::ofstream ofs{ FILENAME };
	for (auto point : points)	// write points to disk
		ofs << point << '\n';
	ofs.close();	//we could let this fall out of scope to close, but we let
	// close it purposefully here to allow subsequent reads.

	std::ifstream ifs{ FILENAME };	
	for (Point<std::string, std::string> point; ifs >> point;) //read points
		std::cout << point << '\n';
	//allow ifs to fall out of scope and close by it's destructor.
}