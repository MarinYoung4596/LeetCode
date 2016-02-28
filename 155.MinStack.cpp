/*
155. Min Stack My Submissions Question

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    void push(const int &x) 
	{
        data.push(x);
        if (min_stack.size() == 0 || x < min_stack.top())
            min_stack.push(x);
        else
            min_stack.push(min_stack.top());
    }

    void pop() 
	{
        assert(data.size() > 0 && min_stack.size() > 0);
        
        data.pop();
        min_stack.pop();
    }

    int top() 
	{
        assert(data.size() > 0);
        return data.top();
    }

    int getMin() const
	{
        assert(min_stack.size() > 0);
        return min_stack.top();
    }

private:
    stack<int> data;
    stack<int> min_stack;
};