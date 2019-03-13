#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include "BinaryPair.h"
#include "Pipeline.h"

using namespace std;

const size_t number_degree = 4;
void printShiftInfo(const std::vector <bool>&, const bool&);
void printAddInfo(std::vector <bool>&);

int main()
{
	queue <BinaryPair> queue;
	queue.push(BinaryPair({ 1, 0, 1, 1 }, { 1, 1, 0, 1 }));

	Pipeline pipeline(number_degree);

	while(!queue.empty())
	{
		for (size_t curr_degree = 0; curr_degree < number_degree; curr_degree++)
		{
			std::vector <bool> number = pipeline.shift(queue.front().first, queue.front().second[curr_degree]);
			printShiftInfo(number, queue.front().second[curr_degree]);
			number = pipeline.add(number);
			printAddInfo(number);
			pipeline.newStep();
		}
		queue.pop();
	}
}

void printShiftInfo(const std::vector <bool>& number, const bool& curr_digit)
{
	cout << "========== SHIFTER ===========" << endl;
	cout << "Current digit of 2nd number: " << curr_digit;
	cout << endl << "Shifted number: ";
	for (size_t curr_degree = 0; curr_degree < number.size(); curr_degree++)
	{
		cout << number[curr_degree];
	}
	cout << endl << "==============================" << endl;
}

void printAddInfo(vector <bool>& partial_summ)
{
	cout << "=========== ADDER ============" << endl;
	cout << "New partial summ: ";
	for (size_t curr_degree = 0; curr_degree < partial_summ.size(); curr_degree++)
	{
		cout << partial_summ[curr_degree];
	}
	cout << endl << "==============================" << endl;
}
