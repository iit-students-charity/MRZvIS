#pragma once
#include <vector>

class Pipeline
{
private:
	size_t number_degree;
public:
	Pipeline(const size_t&);
	std::vector <bool> shift(const std::vector <bool>&, const bool&, const size_t&);
	std::vector <bool> add(const std::vector <bool>&, std::vector <bool>&);
};
