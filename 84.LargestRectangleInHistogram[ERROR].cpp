/*

84. Largest Rectangle in Histogram

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
       6
     5| |
    | | |
    | | |  3
 2  | | |2| |
| |1| | | | | 
| | | | | | |
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
       6
     5| |
    |/|/|
    |/|/|  3
 2  |/|/|2| |
| |1|/|/| | | 
| | |/|/| | |
The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.

*/

// First Solution: Time Limit Exceeded, Memory Limit Exceeded
// 7.989s in Intel(R) Core(TM) i5-2450M CPU @ 2.50GHz, 4GB Memory


class Solution 
{ 
public:     
    int largestRectangleArea(vector<int>& heights) 
    { 
        if(heights.empty()) 
            return 0;
        
        const int len = heights.size();
        vector<vector<int> >  minMatrix(len, vector<int>(len, INT_MAX));
        getMinMatrix(minMatrix, heights);
        int res = 0;
        for (int i = 0; i < len; ++i)
        {             
            for (int j = i; j < len; ++j) 
            {
                int tmp = minMatrix[i][j]* (j-i+1); 
                res = max(res, tmp);
            } 
        }
        return res;
    }

private:
    int findMinumum(vector<int> &heights, int start, int end)
    {
        if (start == end) return heights[start];
        int res = heights[start];
        for (int i = start+1; i <= end; ++i)
        {
            if (heights[i] < res) res = heights[i];
        }
        return res;
    }

// »º´æ½á¹û
    void getMinMatrix(vector<vector<int> > &minMatrix, vector<int> &nums)
    {
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (i == j) minMatrix[i][j] = nums[i];
                else minMatrix[i][j] = min(nums[j], minMatrix[i][j-1]);
            }
        }
    }
};


// Second Solution
//to be continued...

int main()
{
    Solution     obj;
    int arr1[] = {2,1,6,5,3,2};

    vector<int> v(arr1, arr1 + sizeof(arr1)/sizeof(int));
    std::cout << v.size() << std::endl;
    std::cout<<obj.largestRectangleArea(v) << endl;

    return 0;
}
