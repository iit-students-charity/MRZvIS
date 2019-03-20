/*/////////////////////////////////////////////////////////////////////////////////////

	Laboratory work #1 in "Models of solving problems in intelligent systems"
	is done by student of BSUIR of grop #721703
	Antsypovich Pavel Valentinovich

	Main function & out functions

	v 2.1.0
/////////////////////////////////////////////////////////////////////////////////////*/


#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include "BinaryPair.h"
#include "Pipeline.h"

using namespace std;

const size_t number_degree = 4;
size_t& translate(vector <bool>);
void printStartInfo(queue <BinaryPair>);
void printStepInfo(size_t&, vector <BinaryPair>&);
void printFinishInfo(vector <BinaryPair>&);

int main()
{
	queue <BinaryPair> input_data;
	input_data.push(BinaryPair({ 1, 1, 0, 1 }, { 1, 0, 1, 1 }));
	input_data.push(BinaryPair({ 1, 0, 0, 0 }, { 1, 0, 1, 0 }));
	input_data.push(BinaryPair({ 0, 0, 0, 0 }, { 1, 1, 1, 1 }));

	Pipeline pipeline(number_degree);	

	vector <BinaryPair> pipeline_register(2*number_degree, BinaryPair());
	printStartInfo(input_data);
	for (size_t step = 0; step < 2*number_degree + 2; step++)
	{
		if (!input_data.empty())
		{
			pipeline_register.insert(pipeline_register.begin(), input_data.front());
			input_data.pop();
		}
		else
		{
			pipeline_register.insert(pipeline_register.begin(), BinaryPair());
		}
		pipeline_register.erase(pipeline_register.end() - 1);

		for (int curr_process_index = pipeline_register.size() - 1; curr_process_index >= 0; curr_process_index--)
		{
			if (curr_process_index%2 == 0 && pipeline_register[curr_process_index].first[0] != NULL)
			{
				pipeline_register[curr_process_index].shifted = 
					pipeline.shift
					(
						pipeline_register[curr_process_index].first,
						pipeline_register[curr_process_index].second[curr_process_index/2], 
						curr_process_index/2 + 1
					);
			}

			if (curr_process_index % 2 == 1 && pipeline_register[curr_process_index].first[0] != NULL)
			{
				pipeline_register[curr_process_index].partial_summa =
					pipeline.add
					(
						pipeline_register[curr_process_index].shifted,
						pipeline_register[curr_process_index].partial_summa
					);
			}
		}
		printStepInfo(step, pipeline_register);
		system("pause");
 	}
	//printFinishInfo(data);
}

void printStartInfo(queue <BinaryPair> input_data)
{
	vector <vector <bool>> seconds;
	for (size_t curr_pair_number = 0; curr_pair_number < input_data.size(); curr_pair_number++)
	{
		cout << "Pair " << curr_pair_number + 1 << ": " << '\t' << "\t" << "|";
	}
	cout << endl;
	for (size_t curr_pair_number = 0; !input_data.empty(); curr_pair_number++)
	{
		cout <<  '\t' << translate(input_data.front().first) << '\t';
		for (size_t curr_degree = 0; curr_degree < input_data.front().first.size(); curr_degree++)
		{
			cout << input_data.front().first[curr_degree];
		}
		cout << '\t' << '|';
		seconds.push_back(input_data.front().second);
		input_data.pop();
	}
	cout << endl;
	for (size_t curr_pair_number = 0; curr_pair_number < seconds.size(); curr_pair_number++)
	{
		cout << '\t' << translate(seconds[curr_pair_number]) << '\t';
		for (size_t curr_degree = 0; curr_degree < seconds[curr_pair_number].size(); curr_degree++)
		{
			cout << seconds[curr_pair_number][curr_degree];
		}
		cout << '\t' << '|';
	}
	cout << endl;
	cout << "==============================================================" <<
		"=================================================================" <<
		"=================================================================" << endl << endl;
}

void printStepInfo(size_t& step, vector <BinaryPair>& pipeline_register) 
{
	cout << "****************************************************************************************** " <<
		"STEP " << step + 1 << " ***************************************************" <<
		"*******************************************" << endl << endl;
	for (size_t curr_proc_number = 0; curr_proc_number < pipeline_register.size(); curr_proc_number++)
	{
		cout << '|' << "Pair ";
		cout << step + curr_proc_number + 1;
		if (curr_proc_number % 2 == 0)
		{
			cout << " SHIFTER #" << curr_proc_number / 2 + 1 << '\t';
		}
		if (curr_proc_number % 2 == 1)
		{
			cout << " ADDER #" << curr_proc_number/2 + 1 << '\t';
		}
	}
	cout << endl;
	for (size_t curr_proc_number = 0; curr_proc_number < pipeline_register.size(); curr_proc_number++)
	{
		cout << '|';
		if (curr_proc_number % 2 == 0 && pipeline_register[curr_proc_number].shifted.size() != 0)
		{
			cout << "shift. res.: "; 
			for (size_t curr_digit = 0; curr_digit < pipeline_register[curr_proc_number].shifted.size(); curr_digit++)
			{
				cout << pipeline_register[curr_proc_number].shifted[curr_digit];
			}
			cout << '\t';
		}
		if ((curr_proc_number % 2 == 0 && pipeline_register[curr_proc_number].shifted.size() == 0) || 
			(curr_proc_number % 2 == 1 && pipeline_register[curr_proc_number].partial_summa.size() == 0))
		{
			if (curr_proc_number != pipeline_register.size() - 1)
			{
				cout << '\t' << '\t' << '\t';
			}
			else
			{
				cout << endl;
			}
		}
		if (curr_proc_number % 2 == 1 && pipeline_register[curr_proc_number].partial_summa.size() != 0)
		{
			cout << "partial sum.: ";
			for (size_t curr_digit = 0; curr_digit < pipeline_register[curr_proc_number].partial_summa.size(); curr_digit++)
			{
				cout << pipeline_register[curr_proc_number].partial_summa[curr_digit];
			}
			if (curr_proc_number != pipeline_register.size() - 1)
			{
				cout << '\t';
			}
			else
			{
				cout << endl;
			}
		}
	}
	for (size_t curr_proc_number = 0; curr_proc_number < pipeline_register.size(); curr_proc_number++)
	{
		cout << '|';
		if (curr_proc_number % 2 == 0 && pipeline_register[curr_proc_number].shifted.size() != 0)
		{
			cout << "current digit: " << pipeline_register[curr_proc_number].second[curr_proc_number/2] << '\t';
		}
		else
		{
			if (curr_proc_number != pipeline_register.size() - 1)
			{
				if (curr_proc_number != pipeline_register.size() - 1)
				{
					cout << '\t' << '\t' << '\t';
				}
				else
				{
					cout << endl;
				}
			}
			else
			{
				cout << endl;
			}
		}
	}
}

size_t& translate(vector <bool> bin_number)
{
	size_t res = 0;
	size_t degree = bin_number.size();
	for (size_t curr_degree = 0; curr_degree < bin_number.size(); curr_degree++)
	{
		res += bin_number[curr_degree] * pow(2, degree - 1);
		degree--;
	}
	return res;
}