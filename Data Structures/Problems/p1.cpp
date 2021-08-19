using namespace std;
#include <iostream>
#include <deque>
#include <stack>

int isValidBraces(string braces)
{
	stack<char> s;
	for (int i = 0; i < braces.size(); i++)
	{
		if (braces[i] == '(')
			s.push('(');
		else if (braces[i] == ')')
		{
			if (!s.empty())
			{
				s.pop();
			}
			else
				return 0;
		}
		else
			return 0;
	}
	return 1;
}

int isValid(deque<char>* expression)
{
	auto itr = (*expression).begin();
	int operCount = 0;
	string braces;
	while (itr != (*expression).end())
	{
		if (*itr == '(' || *itr == ')')
		{
			braces.push_back(*itr);
			operCount = 0;
		}
		else if (*itr == '+' || *itr == '-' || *itr == '*' || *itr == '/' || *itr == '%')
		{
			operCount++;
			if (operCount > 1)
			{
				return 0;
			}
		}
		else if (*itr >= '0' && *itr <= '9')
		{
			operCount = 0;
		}
		else
		{
			return 0;
		}
		itr++;
	}
	char firstChar = expression->front();
	char lastChar = expression->back();
	if (firstChar == '*' || firstChar == '/' || firstChar == '%' ||
		lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/' || lastChar == '%')
	{
		return 0;
	}

	if (isValidBraces(braces) == 0)
	{
		return 0;
	}
	return 1;
}

int getNumber(deque<char>::iterator itr)
{
	int number = 0;
	while (*itr >= '0' && *itr <= '9')
	{
		number *= 10;
		number += (*itr - 48);
		itr++;
	}
	return number;
}

int evaluate(deque<char>* expression, deque<char>::iterator itr)
{
	int result = 0, number = 0;
	result = getNumber(itr);
	while (itr != expression->end())
	{
		if (*itr == ')')
		{
			*itr = '#';
			return result;
		}
		else if (*itr == '+')
		{
			if (*(itr + 1) == '(')
			{
				*itr = *(itr + 1) = '#';
				itr += 2;
				result += evaluate(expression, itr);
			}
			else
			{
				*itr = '#';
				itr++;
				result += getNumber(itr);
			}
		}
		else if (*itr == '-')
		{
			if (*(itr + 1) == '(')
			{
				*itr = *(itr + 1) = '#';
				itr += 2;
				result -= evaluate(expression, itr);
			}
			else
			{
				*itr = '#';
				itr++;
				result -= getNumber(itr);
			}
		}
		else if (*itr == '*')
		{
			if (*(itr + 1) == '(')
			{
				*itr = *(itr + 1) = '#';
				itr += 2;
				result *= evaluate(expression, itr);
			}
			else
			{
				*itr = '#';
				itr++;
				result *= getNumber(itr);
			}
		}
		else if (*itr == '/')
		{
			if (*(itr + 1) == '(')
			{
				*itr = *(itr + 1) = '#';
				itr += 2;
				result /= evaluate(expression, itr);
			}
			else
			{
				*itr = '#';
				itr++;
				result /= getNumber(itr);
			}
		}
		else if (*itr == '%')
		{
			if (*(itr + 1) == '(')
			{
				*itr = *(itr + 1) = '#';
				itr += 2;
				result %= evaluate(expression, itr);
			}
			else
			{
				*itr = '#';
				itr++;
				result %= getNumber(itr);
			}
		}
		else if (*itr >= '0' && *itr <= '9')
		{
			*itr = '#';
			itr++;
		}
		else if (*itr == '#')
		{
			itr++;
		}
	}
	return result;
}

int main(void)
{
	string str;
	getline(cin, str);
	deque<char> expression;
	for (int i = 0; i < str.size(); i++)
	{
		// here spaces are not stored in deque
		if (str[i] != ' ')
		{
			expression.push_back(str[i]);
		}
	}
	int validity = isValid(&expression);
	//cout << expression.size() << "\t" << expression.front() << "\t" << expression.back() << "\n\n";
	if (validity == 0)
	{
		cout << "Invalid expression";
		return 0;
	}
	deque<char>::iterator itr = expression.begin();
	int result = evaluate(&expression, itr);
	cout << "\n\n\tThe result of " << str << " is\t\t: " << result;
}
