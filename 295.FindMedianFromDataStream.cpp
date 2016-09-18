/*
295. Find Median from Data Stream

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
Examples: 

[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5 

Design a data structure that supports the following two operations: 
•void addNum(int num) - Add a integer number from the data stream to the data structure.
•double findMedian() - Return the median of all elements so far.

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
#include <functional> // greater<int>


class MedianFinder {
public:
    // Adds a number into the data structure.
	void addNum(int num)
	{
		if (MaxHeap.empty() || num < MaxHeap[0]) // num < MaxHeap[0] < MinHeap[0]
			MaxHeapPush(num);
		else if (MinHeap.empty() || MinHeap[0] < num) // MaxHeap[0] < MinHeap[0] < num
			MinHeapPush(num);
		else // MaxHeap[0] <= num <= MinHeap[0]
		{
			if (MaxHeap.size() > MinHeap.size())
				MinHeapPush(num);
			else
				MaxHeapPush(num);
		}
		HeapAdjust();
	}

    // Returns the median of current data stream
    double findMedian() 
    {
        if (MaxHeap.size() == MinHeap.size())
            return static_cast<double>(MaxHeap[0] + MinHeap[0]) / 2;
        return static_cast<double>(MaxHeap.size() > MinHeap.size() ? MaxHeap[0] : MinHeap[0]);
    }
    
private:
    vector<int> MaxHeap; // smaller numbers
    vector<int> MinHeap; // larger numbers
    
    void HeapAdjust()
    {
        if (MaxHeap.size() == MinHeap.size()) return;
        
        while (MaxHeap.size() > MinHeap.size() + 1)
        {
            auto x = MaxHeapPop();
            MinHeapPush(x);
        }
        while (MinHeap.size() > MaxHeap.size() + 1)
        {
            auto x = MinHeapPop();
            MaxHeapPush(x);
        }
    }
    
    void MaxHeapPush(int val)
    {
        MaxHeap.push_back(val);
        push_heap(MaxHeap.begin(), MaxHeap.end());
    }
    
    int MaxHeapPop()
    {
        pop_heap(MaxHeap.begin(), MaxHeap.end());
        auto res = MaxHeap.back();
        MaxHeap.pop_back();
        return res;
    }
    
    void MinHeapPush(int val)
    {
        MinHeap.push_back(val);
        push_heap(MinHeap.begin(), MinHeap.end(), greater<int>());
    }
    
    int MinHeapPop()
    {
        pop_heap(MinHeap.begin(), MinHeap.end(), greater<int>());
        auto res = MinHeap.back();
        MinHeap.pop_back();
        return res;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();