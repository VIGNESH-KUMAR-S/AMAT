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
}