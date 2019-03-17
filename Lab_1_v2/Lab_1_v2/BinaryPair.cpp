#include "pch.h"
#include <vector>
#include <iostream>
#include "BinaryPair.h"


BinaryPair::BinaryPair(std::vector <bool> first, std::vector <bool> second)
{
	try
	{
		if (first.size() != second.size())
		{
			throw "Words' size must be equal";
		}
	}
	catch (const char str[])
	{
		std::cout << str << std::endl;
	}

	BinaryPair::first = first;
	BinaryPair::second = second;
	degree = first.size();

	partial_summ.resize(degree * 2);
	shifted.resize(degree * 2);
	for (size_t curr_degree = 0; curr_degree < degree * 2; curr_degree++)
	{
		shifted[curr_degree] = partial_summ[curr_degree] = 0;
	}
}
