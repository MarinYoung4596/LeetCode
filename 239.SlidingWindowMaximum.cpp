/*
239. Sliding Window Maximum
Given an array nums, there is a sliding window of size k which is moving from the very left
of the array to the very right. You can only see the k numbers in the window. Each time the
sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7      3
1 [3  -1  -3] 5  3  6  7       3
1  3 [-1  -3  5] 3  6  7       5
1  3  -1 [-3  5  3] 6  7       5
1  3  -1  -3 [5  3  6] 7       6
1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
    You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
    Could you solve it in linear time?

Hint:
    How about using a data structure such as deque (double-ended queue)?
    The queue size need not be the same as the window’s size.
    Remove redundant elements and the queue should store only elements that need to be considered.
*/
#include <stack>
#include <vector>

#define Max(x, y) (x) > (y) ? (x) : (y)

// First Solution, using queue to represent sliding window.
// when sliding the window, pop front and push back
// adding the maximum element in the queue to the result list

// same as Min Stack
// see LeetCode No. 155
class MaxStack  {
public:
    void push(const int &x) {
        data.push(x);
        if (max_stack.size() == 0 || x > max_stack.top()) {
            max_stack.push(x);
        } else {
            max_stack.push(max_stack.top());
        }
    }

    void pop() {
        assert(data.size() > 0 && max_stack.size() > 0);

        data.pop();
        max_stack.pop();
    }

    int top() const {
        assert(data.size() > 0);
        return data.top();
    }

    int getMax() const {
        assert(max_stack.size() > 0);
        return max_stack.top();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

private:
    stack<int> data;
    stack<int> max_stack;
};


// implement queue using stacks
// see LeetCode No. 232
class MaxQueue {
public:
    // shift the two stacks
    void shiftStack(void) {
        if (_old.empty()) {
            while (!_new.empty()) {
                _old.push(_new.top());
                _new.pop();
            }
        }
    }

    // Push element x to the back of queue.
    void push(const int &x) {
        _new.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        shiftStack();
        _old.pop();
    }

    // Return whether the queue is empty.
    bool empty(void) const {
        return _new.empty() && _old.empty();
    }

    // get the size of queue
    size_t size() const {
        return _new.size() + _old.size();
    }

    // get maximum element in the queue
    int getMax() const {
        assert(_new.size() > 0 || _old.size() > 0);

        if (_new.empty()) {
            return _old.getMax();
        } else if (_old.empty()) {
            return _new.getMax();
        } else
            return Max(_new.getMax(), _old.getMax());
        }
    }

private:
    MaxStack _new;
    MaxStack _old;
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (k <= 0 || k > nums.size()) {
            return res;
        }
        if (k == 1) {
            return nums;
        }

        MaxQueue slidingWindow;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (slidingWindow.size() < k) {
                slidingWindow.push(nums[i]);
                continue;
            }

            res.push_back(slidingWindow.getMax());
            slidingWindow.pop();
            slidingWindow.push(nums[i]);
        }
        res.push_back(slidingWindow.getMax());
        return res;
    }
};


// Second Solution
// Same as first solution, while implement an queue that can get maximum element
// without using two stacks
// see http://www.cnblogs.com/remlostime/archive/2012/11/04/2754130.html
class MaxQueue_2 {
public:
    void push(const int &x) {
        data.push(x);
        while (!max_queue.empty()) {
            if (x > max_queue.back()) {
                max_queue.pop_back();
            } else {
                break;
            }
        }
        max_queue.push_back(x);
    }

    void pop() {
        int element = data.front();
        data.pop();
        if (element == max_queue.front()) {
            max_queue.pop_front();
        }
    }

    int getMax() const {
        return max_queue.front();
    }

private:
    queue<int> data;
    // 双端队列，队列里元素单调递增
    deque<int> max_queue; // make sure that max_queue is a non-monotonic increasing queue
};



// Third Solution
// to be continued...


int main() {
    /*
     * test case
     * 1. nums = [1,3,-1,-3,5,3,6,7]; k = 3; expected output: [3,3,5,5,6,7]
     * 2. nums = [7,2,4]; k = 2; expected output: [7, 4]
     */
    Solution _solution;
    vector<int> nums({ 7, 2, 4 });
    vector<int> res = _solution.maxSlidingWindow(nums, 2);
    for (auto i = res.begin(); i != res.end(); ++i) {
        cout << *i << '\t';
    }
    cout << endl;

    return 0;
}
