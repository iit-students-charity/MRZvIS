#include "pch.h"
#include "Subprocessor.h"

void Subprocessor::input(vector <vector <bool>> input_values)
{
	output_values.clear();
	Subprocessor::input_values = input_values;
};

vector<vector <bool>> Subprocessor::output()
{
	return output_values;
}