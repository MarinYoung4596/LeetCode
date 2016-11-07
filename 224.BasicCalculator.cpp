/*
224. Basic Calculator

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"5   "
"1 + 1"
" 2-1 + 2 "
"(1+(4+5+2)-3)+(6+8)"
"1-(2-(3-(4-5)))"
"3+2*2"
" 3/2 "
" 3+5 / 2 "
"1*2-3/4+5*6-7*8+9/10"
"1*2+3*4-5*6+7*8-9*10"
"282-1*2*13-30-2*2*2/2-95/5*2+55+804+3024"
"123-8*5-57/3+148+1*3/2*14*11*2*5/4*3/3/3+2283"
"415+21*3*3*2+7551/3-4*39*15/2/3-37705*2/3/2*4/24/2-204+4140"
*/

#include <iostream>
#include <fstream>
#include <string> // C++ 11, to_string
#include <stack>
#include <cassert> // assert

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);

using namespace std;


class Solution
{
public:

	int calculate(string s) const
	{
		string postfix = infix_to_postfix(s);
		return calculate_postfix(postfix);
	}

private:

	static int priority(char c)
	{
		return c == '+' || c == '-' ? 0 : 1;
	}

	static int calculate(char op, int lhs, int rhs)
	{
		switch (op)
		{
		case '+':
			return lhs + rhs;
		case '-':
			return lhs - rhs;
		case '*':
			return lhs * rhs;
		case '/':
			assert(rhs != 0);
			return lhs / rhs;
		default:
			return lhs;//ERROR
		}
	}

	string infix_to_postfix(const string &infix) const
	{
		stack<char> operation;
		string postfix;
		for (auto i = 0; i < infix.size(); ++i)
		{
			if (isspace(infix[i])) continue;
			if (isdigit(infix[i]))
			{
				if (i && !isdigit(infix[i-1])) // space between lhs and rhs
					postfix += " ";
				postfix += infix[i];
			}
			else // operator
			{
				if (operation.empty() || infix[i] == '(') // 为空，或当前位置为‘（’，直接入栈
				{
					operation.push(infix[i]);
				}
				else if (infix[i] == ')') //  将符号栈中的元素依次出栈并输出, 直到‘（’, “(“只出栈, 不输出
				{
					while (!operation.empty() && operation.top() != '(')
					{
						postfix += operation.top();
						operation.pop();
					}
					operation.pop(); // pop '('
				}
				else // + - * /，  将符号栈中的元素依次出栈并输出, 直到遇到比当前符号优先级更低的符号或者”(“
				{
					while (!operation.empty() && operation.top() != '(' &&
						priority(infix[i]) >= priority(operation.top()))
					{
						postfix += operation.top();
						operation.pop();
					}
					operation.push(infix[i]);//将当前符号入栈
				}
			}
		}
		while (!operation.empty())
		{
			postfix += operation.top();
			operation.pop();
		}
		return postfix;
	}

	int calculate_postfix(const string &postfix) const
	{
		stack<int> digits;
		for (auto i = 0; i < postfix.size(); ++i)
		{
			if (isspace(postfix[i]))
				continue;
			if (isdigit(postfix[i]))
			{
				int tmp = static_cast<int>(postfix[i] - '0');
				if (i && isdigit(postfix[i - 1]))
				{
					tmp += digits.top() * 10;
					digits.pop();
				}
				digits.push(tmp);
			}
			else
			{
				int curr = digits.top();
				digits.pop();
				int prev = digits.top();
				digits.pop();
				digits.push(calculate(postfix[i], prev, curr));
			}
		}
		return digits.top();
	}
};

int main()
{
	IN; OUT;

	Solution obj;
	string s;
	while (getline(cin, s))
	{
		//cout << obj.infix_to_postfix(s.substr(1, s.size() - 2)) << endl;
		cout << obj.calculate(s.substr(1, s.size()-2)) << endl;
	}

	return 0;
}
