/*
232	Implement Queue using Stacks

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, 
	peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate 
	a stack by using a list or deque (double-ended queue), as long as you use only 
	standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations
	will be called on an empty queue).
*/
#include <stack>

class Queue {
public:
	// shift the two stacks
	void shiftStack(void)
	{
		if (_old.empty())
		{
			while (!_new.empty())
			{
				_old.push(_new.top());
				_new.pop();
			}
		}
	}

	// Push element x to the back of queue.
	void push(int x) 
	{
		_new.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) 
	{
		shiftStack();
		_old.pop();
	}

	// Get the front element.
	int peek(void)
	{
		shiftStack();
		return _old.top();
	}

	// Return whether the queue is empty.
	bool empty(void)
	{
		return _new.empty() && _old.empty();
	}

private:
	stack<int> _new, _old;
};