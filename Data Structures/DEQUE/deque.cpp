using namespace std;
#include <iostream>
#include <deque>

int main(void)
{
	deque<int> d = { 1,2,3,4 };
	d.push_front(-1);
	d.push_back(99);

	// deque becomes {-1, 1, 2, 3, 4, 99}

	//1. Print deque elements without deleting 
	// begin() gives starting address of deque
	// here itr is the pointer pointing to first element
	deque<int> ::iterator itr = d.begin();

	// This is standard way
	// end() gives address after the last element in deque
	cout << "Print deque elements without deleting\n";
	while (itr != d.end())
	{
		//cout << *itr << "\t";
		//++itr;
		cout << *itr++ << "\t";
	}
	cout << "\nSize of DoubleEndedQUEue\t: " << d.size();

	//2. Print deque elements with pop()
	cout << "\n\nPrint deque elements with pop()\n";
	while (!d.empty())
	{
		cout << d.front() << "\t";
		d.pop_front();
	}
	cout << "\nSize of DoubleEndedQUEue\t: " << d.size();

	d = { -1,1,2,3,4,99 };
	itr = d.begin();
	//3. insert one or multiple elements into deque
	// insert(iterator i, element e) : Inserts element 34 at the position pointed by iterator i in the deque.
	d.insert(itr + 3, 34);
	cout << "\n\nInserts element 34 at the position pointed by iterator i in the deque.\n";
	while (itr != d.end())
		cout << *itr++ << "\t";

	// insert(iterator i, int count, element e);
	// Inserts element 333 for count number of times from the position pointed by iterator i.
	itr = d.begin();
	d.insert(itr + 3, 3, 333);
	cout << "\n\nInserts element 333 for count number of times from the position pointed by iterator i.\n";
	while (itr != d.end())
		cout << *itr++ << "\t";

	// insert(iterator i, iterator first, iterator last);
	// Inserts the element in the range [first,last] at the position pointed by iterator i in deque.
	// here second argument is inclusive and third is exclusive
	itr = d.begin();
	deque<int> temp = { 1,2,3,4 };
	d.insert(itr + 2, temp.begin(), temp.end());
	// here itr becomes (itr + Number of elements inserted) => itr = itr+4
	cout << "\n\nInserts the element in the range [first,last] at the position pointed by iterator i in deque.\n";
	cout << "Here after completion of insert, itr is changed to itr + number of elements inserted\n";
	itr = d.begin();
	while (itr != d.end())
		cout << *itr++ << "\t";

	//4. erase()
	// erase one element in deque
	d.erase(d.begin() + 3);		//element in d.begin()+3 will be deleted
	cout << "\n\nErase one element in deque.\n";
	itr = d.begin();
	while (itr != d.end())
		cout << *itr++ << "\t";

	// erase range of elements
	// here first argument is inclusive and second is exclusive
	d.erase(d.begin() + 2, d.begin() + 5);
	cout << "\n\nErase range of elements in deque.\n";
	itr = d.begin();
	while (itr != d.end())
		cout << *itr++ << "\t";

	//5. clear(): Used to delete all the elements in deque
	d.clear();
	cout << "\n\nSize of deque after clear().\n";
	cout << d.size();

	/*There are other functions also there but all that functions concept are same for this deque also.
		back, end, front, empty, begin, emplace_back, emplace_front,
		swap, size, max_size, push_front, push_back, pop_front, pop_back	etc,..*/
}