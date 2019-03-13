#pragma once

int main()
{
	queue <BinaryPair> queue;
	queue.push(BinaryPair({ 1, 0, 1, 1 }, { 1, 1, 0, 1 }));

	Pipeline pipeline(number_degree);

	while (!queue.empty())
	{
		for (size_t curr_degree = 0; curr_degree < number_degree; curr_degree++)
		{
			pipeline.shift(queue.front().first, queue.front().second[curr_degree]);
		}
	}
}
