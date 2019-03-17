#pragma once
class BinaryPair
{
private:
	size_t degree;
public:
	std::vector <bool> first;
	std::vector <bool> second;
	std::vector <bool> shifted;
	std::vector <bool> partial_summ;
	BinaryPair(std::vector <bool>, std::vector <bool>);
};
