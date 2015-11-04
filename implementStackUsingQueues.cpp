/*
225.	Implement Stack using Queues
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, 
	peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate 
	a queue by using a list or deque (double-ended queue), as long as you use only 
	standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations 
	will be called on an empty stack).
Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack.
*/
#include <queue>

class Stack 
{
public:
	// Push element x onto stack.
	void push(int x)
	{
		if (q1_in_use)
			q1.push(x);
		else
			q2.push(x);
	}

	// Removes the element on top of the stack.
	void pop() 
	{
		if (q1_in_use)
		{
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
			q1_in_use = false;
		}
		else
		{
			// q2 in use
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
			q1_in_use = true;
		}
	}

	// Get the top element.
	int top()
	{
		return q1_in_use ? q1.back() : q2.back();
	}

	// Return whether the stack is empty.
	bool empty()
	{
		return q1_in_use ? q1.empty() : q2.empty();
	}

private:
	queue<int> q1, q2;
	bool q1_in_use = true;	// false means q2 in use
};