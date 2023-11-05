/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
    [2,3,4] , the median is 3
    [2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:
    void addNum(int num) - Add a integer number from the data stream to the data structure.
    double findMedian() - Return the median of all elements so far.

For example:
    add(1)
    add(2)
    findMedian() -> 1.5
    add(3)
    findMedian() -> 2

*/

#include <iostream>
#include <algorithm>  // push_heap, pop_heap
#include <vector>
#include <queue> // priority_queue
#include <functional> // greater<int>


class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (MaxHeap.empty() || num < MaxHeap[0]) { // num < MaxHeap[0] < MinHeap[0]
            MaxHeapPush(num);
        } else if (MinHeap.empty() || MinHeap[0] < num) {// MaxHeap[0] < MinHeap[0] < num
            MinHeapPush(num);
        } else {// MaxHeap[0] <= num <= MinHeap[0]
            if (MaxHeap.size() > MinHeap.size()) {
                MinHeapPush(num);
            } else {
                MaxHeapPush(num);
            }
        }
        HeapAdjust();
    }

    // Returns the median of current data stream
    double findMedian() {
        if (MaxHeap.size() == MinHeap.size()) {
            return static_cast<double>(MaxHeap[0] + MinHeap[0]) / 2;
        }
        return static_cast<double>(MaxHeap.size() > MinHeap.size() ? MaxHeap[0] : MinHeap[0]);
    }

private:
    void HeapAdjust() {
        if (MaxHeap.size() == MinHeap.size()) return;

        while (MaxHeap.size() > MinHeap.size() + 1) {
            auto x = MaxHeapPop();
            MinHeapPush(x);
        }
        while (MinHeap.size() > MaxHeap.size() + 1) {
            auto x = MinHeapPop();
            MaxHeapPush(x);
        }
    }

    void MaxHeapPush(int val) {
        MaxHeap.push_back(val);
        std::push_heap(MaxHeap.begin(), MaxHeap.end());
    }

    int MaxHeapPop() {
        std::pop_heap(MaxHeap.begin(), MaxHeap.end());
        auto res = MaxHeap.back();
        MaxHeap.pop_back();
        return res;
    }

    void MinHeapPush(int val) {
        MinHeap.push_back(val);
        std::push_heap(MinHeap.begin(), MinHeap.end(), greater<int>());
    }

    int MinHeapPop() {
        std::pop_heap(MinHeap.begin(), MinHeap.end(), greater<int>());
        auto res = MinHeap.back();
        MinHeap.pop_back();
        return res;
    }

private:
    std::vector<int> MaxHeap; // smaller numbers
    std::vector<int> MinHeap; // larger numbers
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();


/// Second Solution: priority_queue
class MedianFinder2 {
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (max_arr.empty() || num < max_arr.top()) {
            max_arr.push(num);
        } else if (min_arr.empty() || num > min_arr.top()) {
            min_arr.push(num);
        } else {
            if (max_arr.size() > min_arr.size()) {
                min_arr.push(num);
            } else {
                max_arr.push(num);
            }
        }
        enbalance();
    }

    double findMedian() {
        if (min_arr.empty() && max_arr.empty()) {
            return -0.0;
        } else {
            if ((max_arr.size() + min_arr.size()) % 2 == 1) {
                return max_arr.size() > min_arr.size() ? max_arr.top() : min_arr.top();
            } else {
                return static_cast<double>(min_arr.top() + max_arr.top()) / 2.0;
            }
        }
    }

private:
    void enbalance() {
        int max_size = max_arr.size();
        int min_size = min_arr.size();
        if (std::abs(max_size - min_size) < 2) {
            return;
        }
        if (max_arr.size() > min_arr.size()) {
            while (max_arr.size() > min_arr.size() + 1) {
                auto top = max_arr.top();
                max_arr.pop();
                min_arr.push(top);
            }
        } else {
            while (min_arr.size() > max_arr.size() + 1) {
                auto top = min_arr.top();
                min_arr.pop();
                max_arr.push(top);
            }
        }
    }

private:
    // ??? ???? ????? ?????
    std::priority_queue<int, std::vector<int>, std::less<int>> max_arr;
    // ??? ????????? ?????
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_arr;
};
