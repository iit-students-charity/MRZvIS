#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include "PipelineProcessor.h"

using namespace std;

PipelineProcessor::PipelineProcessor(vector <vector <vector <bool>>> input)
{
	for (size_t curr_pair = 0; curr_pair < input.size(); curr_pair++)
	{
		queue.push(input[curr_pair]);
	}
	printStartInfo();
 	prev_multiplicator_out = { {0, 0, 0, 0} };
	prev_shifter_out = { {0, 0, 0, 0} };
	prev_adder_out = { {0, 0, 0, 0} };
}

void PipelineProcessor::start()
{
	vector <bool> null = { 0, 0, 0, 0 };
	while (steps < 5)
	{
		steps++;

		if (!queue.empty())
		{
			multiplicator.input(queue.front());
			queue.pop();
		}
		else
		{
			multiplicator.input({ {0, 0, 0, 0} });
		}
		shifter.input(prev_multiplicator_out);
		adder.input(prev_shifter_out);

		multiplicator.process();
		shifter.process();
		adder.process();

		prev_multiplicator_out = multiplicator.output();
		prev_shifter_out = shifter.output();
		prev_adder_out = adder.output();
		if (prev_adder_out.size() > 0)
		{
			out.push_back(prev_adder_out[0]);
		}

		printStepInfo();
	}
	printOutInfo();
}

void PipelineProcessor::printStartInfo()
{
	std::queue <vector <vector <bool>>> q_temp = queue;
	int size = q_temp.size();
	std::cout << "======================== INPUT ======================" << endl;
	for (size_t curr_pair_number = 0; q_temp.size() != 0; curr_pair_number++)
	{
		std::cout << "=== Pair " << curr_pair_number + 1 << " ===" << endl;
		for (size_t curr_pair_element = 0; curr_pair_element < q_temp.front().size(); curr_pair_element++)
		{
			size_t i_temp = 0;
			size_t degree = q_temp.front()[curr_pair_element].size();
			for (size_t curr_pair_element_digit = 0; curr_pair_element_digit < q_temp.front()[curr_pair_element].size(); curr_pair_element_digit++)
			{
				i_temp += q_temp.front()[curr_pair_element][curr_pair_element_digit] * pow(2, degree - 1);
				degree--;
			}
			std::cout << i_temp << endl;
		}
		std::cout << endl;
		q_temp.pop();
	}
	std::cout << "======================================================" << endl;
}

void PipelineProcessor::printStepInfo()
{
	std::cout << "====================== STEP " << steps << " =====================" << endl;
	std::cout << "Multiplicator Output.";
	if (steps > 0 && steps < prev_multiplicator_out.size() + 1)
	{
		std::cout << " Pair " << steps << endl;
	}
	else
	{
		std::cout << endl;
	}
	int counter = 0;
	for (size_t curr_vector = 0; curr_vector < prev_multiplicator_out.size(); curr_vector++)
	{
		for (size_t curr_digit = 0; curr_digit < prev_multiplicator_out[curr_vector].size(); curr_digit++)
		{
			counter++;
			std::cout << prev_multiplicator_out[curr_vector][curr_digit];
			if (counter == 4)
			{
				counter = 0;
				std::cout << " ";
			}
		}
		std::cout << endl;
	}
	std::cout << endl << endl;
	std::cout << "Shifter Output.";
	if (steps - 1 > 0 && steps - 1 < prev_shifter_out.size() + 1)
	{
		std::cout << " Pair " << steps - 1 << endl;
	}
	else
	{
		std::cout << endl;
	}
	counter = 0;
	for (size_t curr_vector = 0; curr_vector < prev_shifter_out.size(); curr_vector++)
	{
		for (size_t curr_digit = 0; curr_digit < prev_shifter_out[curr_vector].size(); curr_digit++)
		{
			counter++;
			std::cout << prev_shifter_out[curr_vector][curr_digit];
			if (counter == 4)
			{
				counter = 0;
				std::cout << " ";
			}
		}
		std::cout << endl;
	}
	std::cout << endl << endl;
	std::cout << "Adder Output.";
	if (steps - 2 > 0 && prev_adder_out.size() == 1)
	{
		std::cout << " Pair " << steps - 2 << endl;
	}
	else
	{
		std::cout << endl;
	}
	counter = 0;
	for (size_t curr_vector = 0; curr_vector < prev_adder_out.size(); curr_vector++)
	{
		for (size_t curr_digit = 0; curr_digit < prev_adder_out[curr_vector].size(); curr_digit++)
		{
			counter++;
			std::cout << prev_adder_out[curr_vector][curr_digit];
			if (counter == 4)
			{
				counter = 0;
				std::cout << " ";
			}
		}
		std::cout << endl;
	}
	std::cout << endl << "================== THE END OF STEP ==================" << endl << endl;
	std::system("pause");
}

void PipelineProcessor::printOutInfo()
{
	std::cout << "======================== OUTPUT ======================" << endl;
	for (size_t curr_vector_number = 0; curr_vector_number < out.size(); curr_vector_number++)
	{
		size_t i_temp = 0;
		std::cout << "=== Pair " << curr_vector_number + 1 << " Multiplication Result ===" << endl;
		size_t degree = out[curr_vector_number].size();
		for (size_t curr_digit_number = 0; curr_digit_number < out[curr_vector_number].size(); curr_digit_number++)
		{
			i_temp += out[curr_vector_number][curr_digit_number] * pow(2, degree - 1);
			degree--;
		}
		std::cout << i_temp << endl << endl;
	}
	std::cout << "======================================================" << endl;
}