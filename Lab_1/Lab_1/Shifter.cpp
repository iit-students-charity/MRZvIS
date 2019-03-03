#include "pch.h"
#include "Shifter.h"

void Shifter::process()
{
	if (input_values.size() > 1)
	{
		for (size_t curr_value_number = 0; curr_value_number < input_values.size(); curr_value_number++)
		{
			//front zeros
			for (size_t degree = 0; degree < curr_value_number + 1; degree++)
			{
				input_values[curr_value_number].insert(input_values[curr_value_number].begin(), 0);
			}
			//back zeros
			for (size_t degree = 0; degree < input_values.size() - curr_value_number - 1; degree++)
			{
				input_values[curr_value_number].push_back(0);
			}
		}
		output_values = input_values;
	}
}
