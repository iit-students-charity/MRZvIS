#pragma once
#include <vector>

using namespace std;

class Subprocessor
{
protected:
	vector <vector <bool>> input_values;
	vector <vector <bool>> output_values;
public:
	virtual void input(vector <vector <bool>>);
	virtual vector<vector <bool>> output();
};
