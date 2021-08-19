using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

int strToInt(string str)
{
	if (str == "")
		return -1;
	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[0] == '-' && (str[1] >= '0' && str[1] <= '9')));
		else
			return -1;
	}
	return stoi(str);
}

int findElement(vector<int> num)
{
	int max = num.front(), element = numeric_limits<int>::max(), flag = 0;
	for (int i = 1; i < (num.size() - 1);)
	{
		if (num[i] > max && i < (num.size() - 1))
		{
			flag = 1;
			max = num[i];
			element = num[i];
			i++;
			while (num[i] > element && i < (num.size() - 1))
			{
				if (num[i] > max)
				{
					max = num[i];
				}
				i++;
			}
		}
		else
		{
			flag = 0;
			i++;
		}
	}
	if (element < num.back() && flag == 1)
	{
		return element;
	}
	else
	{
		return -1;
	}
}

int main(void)
{
	fstream p2_input;
	p2_input.open("p2_input.txt", ios::in);
	vector<int> num;
	if (!p2_input)
		cout << "No such file";
	else
	{
		string line; int validity = 1;
		while (getline(p2_input, line))
		{
			int number = strToInt(line);
			num.push_back(number);
			if (number < 0)
			{
				validity = 0;
			}
		}
		for (int i = 0; i < num.size(); i++)
		{
			cout << num[i] << "\t";
		}
		cout << "\n\n";
		if (validity)
		{
			if (num.size() <= 2)
			{
				cout << "\tNumber of elements is low, Return value : -1";
				return 0;
			}
			int result = findElement(num);
			if (result == -1)
			{
				cout << "\tNo such elements, Return value : -1";
			}
			else
			{
				cout << "\tElement : " << result;
			}
		}
		else
		{
			cout << "\tInvalid input file, Return value : -1";
		}
		p2_input.close();
	}
}