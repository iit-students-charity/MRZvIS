#include "pch.h"
#include "Multiplicator.h"

void Multiplicator::process()
{
	if (input_values.size() == 2)
	{
		for (size_t curr_digit_b = 0; curr_digit_b < input_values[1].size(); curr_digit_b++)
		{
			vector <bool> temp;

			if (input_values[1][curr_digit_b])
			{
				temp = input_values[0];
			}
			else
			{
				temp = { 0,0,0,0 };
			}
			output_values.push_back(temp);
		}
	}
}
