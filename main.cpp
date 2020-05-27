#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <stdio.h>
#include <math.h>

class Task
{
public:
    Task(int val, bool sentinel = false)
    {
        m_val = val;
        Sent = sentinel;
    }

    int m_val;
    int Sent;
};

// Loads the queue with Tasks, and marks the last Task as a sentinel
void source_thread_func(BlockingQueue &bq, int num_ints)
{
	for (int i = 0; i < num_ints; i++)
	{
		std::unique_ptr<Task> task(new Task(i, i == num_ints-1));
		bq.push(std::move(task));
	}
}

// Processes all Tasks on the queue, breaking when it reaches the sentinel
void SinkThreadFunction(BlockingQueue &bq, std::vector<int> vec, int threshold)
{
	int nt = vec.size();

	while(true)
	{
		std::unique_ptr<Task> t = bq.pop();
		Task *task = t.release();

		vec.push_back(task->m_val >= threshold ? task->m_val : 0);

		if (task->Sent)
		{
			break;
		}
	}
}

int main(int argc, char **argv)
{
	// End sum with these values should be 105
	int num_ints = 30;
	int threshold = 5;
	int r;

	BlockingQueue q;   // TODO
	std::vector<int> t;

	std::thread source_thread(source_thread_func, std::ref(q), num_ints);
	std::thread sinkthread(SinkThreadFunction, std::ref(q), t, threshold);

	// TODO: get_multiples should return a vector of the values in t that are integer multiples of threshold
	std::vector<int> m;// = get_multiples(t, threshold);

	int sum = 0;
	for (int i = 0; i < m.size(); i++)
	{
		sum += m[i];
	}

	std::cout << "Sum of multiples greater than or equal to threshold: " << sum << std::endl;
}
