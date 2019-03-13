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
}
