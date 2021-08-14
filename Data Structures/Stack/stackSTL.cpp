using namespace std;
#include <iostream>
#include <stack>

class A {
public:
	int a, b;
	A(int x = 0, int y = 0)
	{
		a = x;	b = y;
		cout << "\nConstructor Called : " << a << "  " << b;
	}
};

int main(void)
{
	stack <int> s1;
	// push()
	// pushes existing element into stack --> 11 is an existing integer right
	s1.push(11);	s1.push(22);	s1.push(33);	s1.push(44);	s1.push(55);
	// size()
	cout << "Size of the stack is : " << s1.size() << endl;
	// top()
	cout << "Top of the stack is : " << s1.top() << endl;
	// pop(), empty()
	cout << "Stack Elements : ";
	while (!s1.empty())
	{
		cout << s1.top() << "\t";
		s1.pop();
	}

	// swap()
	// Swap two seperate stacks.
	s1.push(11);	s1.push(22);	s1.push(33);	s1.push(44);	s1.push(55);
	stack <int> s2;
	s2.push(99);	s2.push(88);	s2.push(77);
	cout << "\n\nBefore swapping" << endl;
	cout << "Size of Stack 1 : " << s1.size() << endl;
	cout << "Size of Stack 2 : " << s2.size() << endl;

	s1.swap(s2);

	cout << "\nAfter swapping" << endl;
	cout << "Size of Stack 1 : " << s1.size() << endl;
	cout << "Stack 1 Elements : ";
	while (!s1.empty())
	{
		cout << s1.top() << "\t";
		s1.pop();
	}
	cout << endl << "Size of Stack 2 : " << s2.size() << endl;
	cout << "Stack 2 Elements : ";
	while (!s2.empty())
	{
		cout << s2.top() << "\t";
		s2.pop();
	}

	// emplace()
	// Create an element/object and after that pushed it on stack automatically
	cout << "\n\nemplace() with pre defined object";
	s1.push(101);	s1.emplace(202);	s1.push(303);	s1.emplace(404);	s1.emplace(505);
	cout << "\nSize of Stack : " << s1.size() << endl;
	cout << "Stack Elements : ";
	while (!s1.empty())
	{
		cout << s1.top() << "\t";
		s1.pop();
	}

	// emplace() in detail
	// We should use upto 2 arguments only in this emplace(), because the constructor used only 2 parameters
	cout << "\n\nemplace() with user defined object";
	stack <A> s3;
	s3.emplace(11, 12);
	A obj1(21, 22);
	s3.push(obj1);
	s3.emplace(31, 33);
	s3.emplace(41);
	s3.emplace();
	A obj2(51, 55);
	s3.push(obj2);
	cout << "\n\nSize of Stack : " << s3.size();
	cout << "\nStack elements" << endl;
	while (!s3.empty())
	{
		cout << s3.top().a << " " << s3.top().b << endl;
		s3.pop();
	}
}