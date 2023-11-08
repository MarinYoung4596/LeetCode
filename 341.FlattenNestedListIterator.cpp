/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    341.FlattenNestedListIterator_tmp.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/25 23:43:46
*   @brief:

You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the NestedIterator class:

    NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
    int next() Returns the next integer in the nested list.
    boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.

Your code will be tested with the following pseudo-code:

    initialize iterator with nestedList
    res = []
    while iterator.hasNext()
        append iterator.next() to the end of res
    return res

If res matches the expected flattened list, then your code will be judged as correct.


Example 1:
    Input: nestedList = [[1,1],2,[1,1]]
    Output: [1,1,2,1,1]
    Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
    Input: nestedList = [1,[4,[6]]]
    Output: [1,4,6]
    Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

Constraints:
    1 <= nestedList.length <= 500
    The values of the integers in the nested list is in the range [-10^6, 10^6].

*****************************************************************/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */


class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        items = std::deque<NestedInteger>(nestedList.begin(), nestedList.end());
    }

    int next() {
        auto value = items.front().getInteger();
        items.pop_front();
        return value;
    }

    bool hasNext() {
        while (!items.empty() && !items.front().isInteger()) {
            vector<NestedInteger> first = items.front().getList();
            items.pop_front();
            for (int i = first.size() - 1; i >= 0; --i) {
                items.push_front(first[i]);
            }
        }
        return !items.empty();
    }

private:
    std::deque<NestedInteger> items;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */