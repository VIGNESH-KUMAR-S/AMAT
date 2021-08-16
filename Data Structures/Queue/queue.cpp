using namespace std;
#include <iostream>
#include <queue>

int main(void)
{
	queue <int> q;
	q.push(11);	q.push(22);	q.push(33);	q.push(44);

	// front()
	cout << "First pushed element : " << q.front() << endl;

	// back()
	cout << "Last pushed element : " << q.back() << endl;

	cout << "\nQueue elements : ";
	while (!q.empty())
	{
		cout << q.front() << "\t";
		q.pop();
	}

	// All other functions like swap(), emplace() are worked same like stack.

	// PRIORITY QUEUE
	priority_queue<int> pq;
	pq.push(12);	pq.push(23);	pq.push(9);		pq.push(99);	pq.push(6);
	// Here though we give multiple unordered values it'll be automatically sorted in descending order.

	cout << "\n\nPRIORITY QUEUE\nElements : ";
	while (!pq.empty())
	{
		cout << pq.top() << "\t";
		pq.pop();
	}
}