#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Priority_queue
{
private:
	std::vector<std::pair<T, int> > heap;

public:

	int get_left(int parent)
	{
		return parent * 2 + 1;
	}

	int get_right(int parent)
	{
		return parent * 2 + 2;
	}

	int get_parent(int child)
	{
		return (child - 1) / 2;
	}

	void enqueue(T val, int priority)
	{
		heap.push_back(std::pair<T, int>(val, priority));
		int child = length() - 1;
		int parent = get_parent(child);

		while (parent >= 0)
		{
			if (heap[parent].second < heap[child].second)
			{
				std::swap(heap[parent], heap[child]);
				child = parent;
				parent = get_parent(child);
			}
			else
			{
				return;
			}
		}
	}

	void heapify(int parent)
	{
		int left = get_left(parent);
		int right = get_right(parent);
		int max = parent;

		if (left < length() && heap[max].second < heap[left].second)
		{
			max = left;
		}

		if (right < length() && heap[max].second < heap[right].second)
		{
			max = right;
		}

		if (max != parent)
		{
			std::swap(heap[max], heap[parent]);
			heapify(max);
		}
	}

	T dequeue()
	{
		T val = heap[0].first;

		if (length() == 2)
		{
			heap[0] = heap[1];
			heap.pop_back();
			return val;
		}

		if (length() == 1)
		{
			heap.pop_back();
			return val;
		}

		heap[0] = heap[length() - 1];
		heap.pop_back();
		heapify(0);

		return val;
	}

	int length()
	{
		return heap.size();
	}

	bool empty()
	{
		return !heap.size();
	}

	void print()
	{
		for (int i = 0; i < length(); ++i)
		{
			std::cout << heap[i].first << " ";
		}
	}
};

int main()
{
	Priority_queue<int> pq;
	pq.enqueue(1, 1);
	pq.enqueue(1, 1);
	pq.enqueue(2, 2);
	pq.enqueue(3, 3);
	pq.enqueue(1, 1);
	pq.enqueue(1, 1);
	pq.enqueue(2, 2);
	pq.enqueue(3, 3);
	pq.enqueue(1, 1);
	pq.enqueue(4, 4);

	while (!pq.empty())
	{
		std::cout << pq.dequeue() << " ";
	}

	return 0;
}