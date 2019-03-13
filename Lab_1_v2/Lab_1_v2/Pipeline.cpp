#include "pch.h"
#include "Pipeline.h"


Pipeline::Pipeline(const size_t& number_degree)
{
	steps = 1;
	Pipeline::number_degree = number_degree;
	partial_summ.resize(number_degree * 2);
	for (size_t curr_degree = 0; curr_degree < number_degree * 2; curr_degree++)
	{
		partial_summ[curr_degree] = false;
	}
}

std::vector <bool> Pipeline::getPartialSumm()
{
	return partial_summ;
}

std::vector <bool> Pipeline::shift(const std::vector<bool>& first_number, const bool& digit)
{
	std::vector <bool> res(0);
	if (digit)
	{
		//front zeros
		for (size_t curr_degree = 0; curr_degree < steps; curr_degree++)
		{
			res.push_back(false);
		}
		//digits
		for (size_t curr_degree = steps; curr_degree < steps + number_degree; curr_degree++)
		{
			res.push_back(first_number[curr_degree - steps]);
		}
		//back zeros
		for (size_t curr_degree = steps+number_degree; curr_degree < number_degree * 2; curr_degree++)
		{
			res.push_back(false);
		}
	}
	else
	{
		for (size_t curr_degree = 0; curr_degree < number_degree * 2; curr_degree++)
		{
			res.push_back(false);
		}
	}
	return res;
}

std::vector <bool> Pipeline::add(const std::vector<bool>& shifted_number)
{
	std::vector <bool> res;
	bool trans = false;
	for (size_t i = shifted_number.size(); i > 0; i--)
	{
		if (shifted_number[i - 1] == 0 && partial_summ[i - 1] == 0 && trans == false)
		{
			res.emplace(res.begin(), 0);
			trans = false;
		}
		else if (shifted_number[i - 1] == 0 && partial_summ[i - 1] == 0 && trans == true)
		{
			res.emplace(res.begin(), 1);
			trans = false;
		}
		else if (shifted_number[i - 1] == 1 && partial_summ[i - 1] == 0 && trans == false)
		{
			res.emplace(res.begin(), 1);
			trans = false;
		}
		else if (shifted_number[i - 1] == 1 && partial_summ[i - 1] == 0 && trans == true)
		{
			res.emplace(res.begin(), 0);
			trans = true;
		}
		else if (shifted_number[i - 1] == 0 && partial_summ[i - 1] == 1 && trans == false)
		{
			res.emplace(res.begin(), 1);
			trans = false;
		}
		else if (shifted_number[i - 1] == 0 && partial_summ[i - 1] == 1 && trans == true)
		{
			res.emplace(res.begin(), 0);
			trans = true;
		}
		else if (shifted_number[i - 1] == 1 && partial_summ[i - 1] == 1 && trans == false)
		{
			res.emplace(res.begin(), 0);
			trans = true;
		}
		else if (shifted_number[i - 1] == 1 && partial_summ[i - 1] == 1 && trans == true)
		{
			res.emplace(res.begin(), 1);
			trans = true;
		}
	}
	partial_summ = res;
	return res;
}

void Pipeline::newStep()
{
	steps++;
}
