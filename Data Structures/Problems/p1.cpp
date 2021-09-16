using namespace std;
#include <iostream>
#include <string>
#include <deque>
#include <limits.h>
#include <stack>

int isValidInput(deque<char> *expression)
{
    char firstChar = expression->front();
    char lastChar = expression->back();
    if (firstChar == '*' || firstChar == '/' || firstChar == '%' ||
        lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/' || lastChar == '%')
    {
        return 0;
    }

    auto itr = (*expression).begin();
    int operCount = 0;
    while (itr != (*expression).end())
    {
        if (*itr == '+' || *itr == '-' || *itr == '*' || *itr == '/' || *itr == '%')
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
    return 1;
}

int getNumber(deque<char>::iterator &itr)
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

int evaluate(deque<char> *expression, deque<char>::iterator itr)
{
    int result = 0, number = 0;
    result = getNumber(itr);
    while (itr != expression->end())
    {
        switch (*itr)
        {
        case '+':
            result += getNumber(++itr);
            break;
        case '-':
            result -= getNumber(++itr);
            break;
        case '*':
            result *= getNumber(++itr);
            break;
        case '/':
            result /= getNumber(++itr);
            break;
        case '%':
            result %= getNumber(++itr);
            break;
        default:
            if (isdigit(*itr))
            {
                ++itr;
            }
            else
            {
                cout << "\n\n\tInvalid Input";
                return 0;
            }
        }
    }
    return result;
}

int main(void)
{
    string str;
    cout << "\tOnly valid characters are : {'0 - 9', '+', '-', '*', '/', '%'}\n\n\tEnter Expression : ";
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
    int validity = isValidInput(&expression);
    if (!validity)
    {
        cout << "\n\n\tInvalid expression";
        return 0;
    }
    deque<char>::iterator itr = expression.begin();
    int result = evaluate(&expression, itr);
    cout << "\n\n\tThe result of " << str << " is\t\t: " << result;
}
