#pragma once
#include <vector>

class Pipeline
{
private:
	size_t steps;
	size_t number_degree;
	std::vector <bool> partial_summ;
public:
	Pipeline(const size_t&);
	std::vector <bool> getPartialSumm();
	std::vector <bool> shift(const std::vector <bool>&, const bool&);
	std::vector <bool> add(const std::vector <bool>&);
	void newStep();
};
