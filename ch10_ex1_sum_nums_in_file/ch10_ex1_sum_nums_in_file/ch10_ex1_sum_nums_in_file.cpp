
#include "pch.h"
#include <fstream>
#include <iostream>

void generate_file(char const * const file_name)
{
	std::ofstream ofs{ file_name };
	const unsigned max = 10000000;
	for (unsigned i = 0; i < max; ++i)
	{
		ofs << i << ' ';
		if (!(i % 10))
			ofs << '\n';
	}
}

unsigned long long accumulate_file(char const * const file_name)
{
	std::ifstream ifs{ file_name };
	unsigned long long sum = 0;
	for (unsigned long long val; !ifs.eof();)
	{
		ifs >> val;
		if (sum > sum + val)
			std::cout << "OVERFLOW\n";
		sum += val;
	}
	return sum;
}

int main()
{
	char const * const fname = "numbers.txt";
	generate_file(fname);
	unsigned long long sum = accumulate_file(fname);
	std::cout << sum << '\n';
}