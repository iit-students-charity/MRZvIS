/*/////////////////////////////////////////////////////////////////////////////////////

	Laboratory work #1 in "Models of solving problems in intelligent systems"
	is done by student of BSUIR of grop #721703
	Antsypovich Pavel Valentinovich

	BinaryPair class source code

	v 2.1.0
/////////////////////////////////////////////////////////////////////////////////////*/
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
	for (size_t curr_degree = 0; curr_degree < 8; curr_degree++)
	{
		partial_summa.push_back(0);
	}
	shifted = { NULL };
}

BinaryPair::BinaryPair()
{
	BinaryPair::first = { NULL };
	BinaryPair::second = { NULL };
	degree = 0;
}