using namespace std;
#include <iostream>
#include <array>

int main(void)
{
	array <int, 5> a = { 11,22,33,44,55 };

	// empty() used to check array is empty or not
	// size() returns number of elements in an array (In array it returns maximum size of an array) 
	for (int i = 0; i < a.size(); i++)
	{
		// at() - used to get value at index, if index is wrong then it returns out_f_range exception
		cout << "\nArray element at index " << i << " is : " << a.at(i);
	}

	// [] operator
	cout << "\n\n [] operator used for index 2: " << a[2];

	// front() returns the first element in the array
	cout << "\n\n First element in the array is : " << a.front();

	// back() returns last element in the array
	cout << "\n\n Last element in the array is : " << a.back();

	// fill() used to fill the given value to all elements in an array
	a.fill(99);
	cout << "\n\nfill() used with value 99\nArray 'a' elements : ";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a.at(i) << "\t";
	}

	// swap() swaps the content of two arrays of same type and same size.
	array <int, 5> b = { -1,-2,-3,-4,-5 };
	a.swap(b);
	cout << "\n\nAfter swap()\nArray 'a' elements : ";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a.at(i) << "\t";
	}
	cout << "\nArray 'b' elements : ";
	for (int i = 0; i < b.size(); i++)
	{
		cout << b.at(i) << "\t";
	}

	// max_size() gives maximum size of the array
	// Arrays are fixed size in nature so that the max_size() is always equals to size() in array
	// Arrays cannot grow or shrink
	array <int, 9> c;
	c[0] = 1, c[1] = 2, c[2] = 3, c[3] = 4;
	cout << "\n\nsize() of Array 'c' is : " << c.size();
	cout << "\nmax_size() of Array 'c' is : " << c.max_size();

	// begin() returns starting address of given array
	// data() returns pointer to the first element in given array
	cout << "\n\nbegin() and data() used in Array 'a' : " << a.data() << "\t" << a.begin();

	// end() returns an address after last element's address
	// returns next address of last element'th address
	cout << "\n\nend() used in Array 'a' : " << a.end();

	// rend() returns a reverse iterator pointing to the theoretical element right before the first element in the array container.

	// rbegin() returns a reverse iterator pointing to the last element in the container.

	// cend() returns a const_iterator pointing to the theoretical element after the last element in an array.

	// cbegin() returns a const_iterator pointing to the first element in the array.

	// crend() returns a constant reverse iterator pointing to the theoretical element right before the first element in the array container.

	// crbegin() returns a constant reverse iterator pointing to the last element in the container.

}