/*
150. Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        if (tokens.size() < 2) return atoi(tokens[0].c_str());
        
        stack<int> digits;
        for (auto it = tokens.begin(); it != tokens.end(); ++it)
        {
            if (it->size() < 2 && !isdigit((*it)[0])) // ["3", "-4", "+"]
            {
                auto curr = digits.top();
                digits.pop();
                auto prev = digits.top();
                digits.pop();
                digits.push(calculate((*it)[0], prev, curr));
            }
            else
            {
                digits.push(static_cast<int>(atoi(it->c_str())));
            }
        }
        return digits.top();
    }
    
private:
    static int calculate(char op, int lhs, int rhs)
	{
	    assert(op == '+' || op == '-' || op == '*' || op == '/');
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
};