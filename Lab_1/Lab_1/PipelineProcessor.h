#pragma once
#include <queue>
#include <vector>
#include "Subprocessor.h"
#include "Multiplicator.h"
#include "Shifter.h"
#include "Adder.h"

using namespace std;

class PipelineProcessor
{
private:
	queue <vector <vector <bool>>> queue;
	Multiplicator multiplicator;
	Shifter shifter;
	Adder adder;
	size_t steps;
	vector <vector <bool>> prev_multiplicator_out;
	vector <vector <bool>> prev_shifter_out;
	vector <vector <bool>> prev_adder_out;
	vector <vector <bool>> out;

	void printStartInfo();
	void printStepInfo();
	void printOutInfo();
public:
	PipelineProcessor(vector <vector <vector <bool>>>);
	void start();
};
