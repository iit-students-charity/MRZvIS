/*/////////////////////////////////////////////////////////////////////////////////////

	Laboratory work #1 in "Models of solving problems in intelligent systems"
	is done by student of BSUIR of grop #721703
	Antsypovich Pavel Valentinovich

	BinaryPair class header

	v 2.1.0
/////////////////////////////////////////////////////////////////////////////////////*/

#pragma once
class BinaryPair
{
private:
	size_t degree;
public:
	std::vector <bool> first;
	std::vector <bool> second;
	std::vector <bool> shifted;
	std::vector <bool> partial_summa;
	BinaryPair(std::vector <bool>, std::vector <bool>);
	BinaryPair();
};
