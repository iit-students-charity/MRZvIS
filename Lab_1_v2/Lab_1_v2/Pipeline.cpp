#include "pch.h"
#include "Pipeline.h"


Pipeline::Pipeline(const size_t& number_degree)
{
	Pipeline::number_degree = number_degree;
}


std::vector <bool> Pipeline::shift(const std::vector<bool>& first_number, const bool& digit, const size_t& shift_lenth)
{
	std::vector <bool> res(0);
	if (digit)
	{
		//front zeros
		for (size_t curr_degree = 0; curr_degree < shift_lenth; curr_degree++)
		{
			res.push_back(false);
		}
		//digits
		for (size_t curr_degree = shift_lenth; curr_degree < shift_lenth + number_degree; curr_degree++)
		{
			res.push_back(first_number[curr_degree - shift_lenth]);
		}
		//back zeros
		for (size_t curr_degree = shift_lenth +number_degree; curr_degree < number_degree * 2; curr_degree++)
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

std::vector <bool> Pipeline::add(const std::vector<bool>& shifted_number, std::vector<bool>& partial_summ)
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
	return res;
}
