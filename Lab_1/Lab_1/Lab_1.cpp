/*/////////////////////////////////////////////////////////////////////////////////////
	
	Laboratory work #1 in "Models of solving problems in intelligent systems"
	is done by student of BSUIR of grop #721703
	Antsypovich Pavel Valentinovich

	Main function
	
	v 1.1.0

	Ковригин Б.Н. Алгоритмы умножения/ Б.Н. Ковригин – М.:Московский инженерно-физический
	институт, кафедра "Компьютерные системы и технологии", 2007. – 40 с.
*/

#include "pch.h"
#include "PipelineProcessor.h"
#include "vector"

int main()
{
	vector <vector <vector <bool>>> all_vectors;
	all_vectors.push_back({ { 1, 0, 1, 1 }, { 1, 1, 0, 1 } });
	all_vectors.push_back({ { 1, 0, 0, 1 }, { 1, 0, 0, 1 } });
	all_vectors.push_back({ { 1, 0, 1, 1 }, { 1, 0, 0, 1 } });

	PipelineProcessor pp(all_vectors);
	pp.start();
}
