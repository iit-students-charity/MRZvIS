#pragma once
class BinaryPair
{
private:
	size_t degree;
public:
	std::vector <bool> first;
	std::vector <bool> second;
	BinaryPair(std::vector <bool>, std::vector <bool>);
};
