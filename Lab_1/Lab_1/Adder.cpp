#include "pch.h"
#include "Adder.h"

void Adder::process()
{
	if (input_values.size() > 1)
	{
		output_values.resize(1);
		while (input_values.size() != 1)
		{
			bool trans = false;

			vector <bool> res;

			for (size_t curr_term_digit = input_values[0].size(); curr_term_digit > 0; curr_term_digit--)
			{
				if (input_values[0][curr_term_digit - 1] == 0 && input_values[1][curr_term_digit - 1] == 0 && trans == false)
				{
					res.emplace(res.begin(), 0);
					trans = false;
				}
				else if (input_values[0][curr_term_digit - 1] == 0 && input_values[1][curr_term_digit - 1] == 0 && trans == true)
				{
					res.emplace(res.begin(), 1);
					trans = false;
				}
				else if (input_values[0][curr_term_digit - 1] == 1 && input_values[1][curr_term_digit - 1] == 0 && trans == false)
				{
					res.emplace(res.begin(), 1);
					trans = false;
				}
				else if (input_values[0][curr_term_digit - 1] == 1 && input_values[1][curr_term_digit - 1] == 0 && trans == true)
				{
					res.emplace(res.begin(), 0);
					trans = true;
				}
				else if (input_values[0][curr_term_digit - 1] == 0 && input_values[1][curr_term_digit - 1] == 1 && trans == false)
				{
					res.emplace(res.begin(), 1);
					trans = false;
				}
				else if (input_values[0][curr_term_digit - 1] == 0 && input_values[1][curr_term_digit - 1] == 1 && trans == true)
				{
					res.emplace(res.begin(), 0);
					trans = true;
				}
				else if (input_values[0][curr_term_digit - 1] == 1 && input_values[1][curr_term_digit - 1] == 1 && trans == false)
				{
					res.emplace(res.begin(), 0);
					trans = true;
				}
				else if (input_values[0][curr_term_digit - 1] == 1 && input_values[1][curr_term_digit - 1] == 1 && trans == true)
				{
					res.emplace(res.begin(), 1);
					trans = true;
				}
			}

			input_values[1] = res;
			input_values.erase(input_values.begin());
		}
		output_values = input_values;
	}
}
