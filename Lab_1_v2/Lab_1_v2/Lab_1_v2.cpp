#include "pch.h"
#include <iostream>
#include <vector>
#include "BinaryPair.h"
#include "Pipeline.h"

using namespace std;

const size_t number_degree = 4;
size_t& translate(vector <bool>);
void printStartInfo(vector <BinaryPair>&);
void printStepInfo(size_t&, vector <BinaryPair>&, size_t&, size_t&);
void printFinishInfo(vector <BinaryPair>&);

int main()
{
	vector <BinaryPair> data;
	data.push_back(BinaryPair({ 1, 1, 0, 1 }, { 1, 0, 1, 1 }));
	data.push_back(BinaryPair({ 1, 0, 0, 0 }, { 1, 0, 1, 0 }));
	data.push_back(BinaryPair({ 0, 0, 0, 0 }, { 1, 1, 1, 1 }));

	Pipeline pipeline(number_degree);	

	printStartInfo(data);
	for (size_t step = 0; step < 12; step++)
	{
		size_t shift_index = step % data.size();
		if (step / data.size() + 1 <= number_degree)
		{
			data[shift_index].shifted =
				pipeline.shift(data[shift_index].first, data[shift_index].second[step/data.size()], step/data.size() + 1);
		}

		size_t add_index = (step + 1) % data.size();
		if (step/data.size() + 1 <= number_degree)
		{
			data[add_index].partial_summ =
				pipeline.add(data[add_index].shifted, data[add_index].partial_summ);
		}

		printStepInfo(step, data, shift_index, add_index);
	}
	printFinishInfo(data);
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

void printStartInfo(vector <BinaryPair>& data)
{
	for (size_t curr_pair_number = 0; curr_pair_number < data.size(); curr_pair_number++)
	{
		cout << "Pair " << curr_pair_number + 1 << endl;
		cout << '\t' << translate(data[curr_pair_number].first) << '\t';
		for (size_t curr_degree = 0; curr_degree < data[curr_pair_number].first.size(); curr_degree++)
		{
			if (curr_degree % 4 == 0)
			{
				cout << " ";
			}
			cout << data[curr_pair_number].first[curr_degree];
		}
		cout << endl;
		cout << '\t' << translate(data[curr_pair_number].second) << '\t';
		for (size_t curr_degree = 0; curr_degree < data[curr_pair_number].second.size(); curr_degree++)
		{
			if (curr_degree % 4 == 0)
			{
				cout << " ";
			}
			cout << data[curr_pair_number].second[curr_degree];
		}
		cout << endl;
	}
	cout << endl << endl;
}

void printStepInfo(size_t& step, vector <BinaryPair>& data, size_t& shift_index, size_t& add_index)
{
	cout << "================ STEP " << step + 1 << "================" << endl;
	cout << "-> Pair " << shift_index + 1 << "  ******* SHIFTER *******" << endl;
	cout << "           " << "shift result:";
	for (size_t curr_degree = 0; curr_degree < data[shift_index].shifted.size(); curr_degree++)
	{
		if (curr_degree % 4 == 0)
		{
			cout << " ";
		}
		cout << data[shift_index].shifted[curr_degree];
	}
	cout << endl;
	cout << "           " << "current digit: " << data[shift_index].second[step / data.size()] << endl;

	cout << "-> Pair " << add_index + 1 << "  ******** ADDER ********" << endl;
	cout << "           " << "partial summ:";
	if (true)
	{
		for (size_t curr_degree = 0; curr_degree < data[add_index].partial_summ.size(); curr_degree++)
		{
			if (curr_degree % 4 == 0)
			{
				cout << " ";
			}
			cout << data[add_index].partial_summ[curr_degree];
		}
	}
	cout << endl;
}

void printFinishInfo(vector <BinaryPair>& data)
{
	cout << endl << endl;
	for (size_t curr_pair_number = 0; curr_pair_number < data.size(); curr_pair_number++)
	{
		cout << "Pair " << curr_pair_number + 1 << endl;
		cout << '\t' << translate(data[curr_pair_number].partial_summ) << '\t';
		for (size_t curr_degree = 0; curr_degree < data[curr_pair_number].partial_summ.size(); curr_degree++)
		{
			if (curr_degree % 4 == 0)
			{
				cout << " ";
			}
			cout << data[curr_pair_number].partial_summ[curr_degree];
		}
		cout << endl;
	}
}