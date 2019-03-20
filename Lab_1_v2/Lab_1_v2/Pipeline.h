/*/////////////////////////////////////////////////////////////////////////////////////

	Laboratory work #1 in "Models of solving problems in intelligent systems"
	is done by student of BSUIR of grop #721703
	Antsypovich Pavel Valentinovich

	Pipeline class header

	v 2.1.0
/////////////////////////////////////////////////////////////////////////////////////*/
#pragma once
#include <vector>

class Pipeline
{
private:
	size_t number_degree;
public:
	Pipeline(const size_t&);
	std::vector <bool> shift(const std::vector <bool>&, const bool&, const size_t&);
	std::vector <bool> add(const std::vector <bool>&, const std::vector <bool>&);
};
