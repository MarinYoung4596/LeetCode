/*
303. Range Sum Query - Immutable

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

*/


// First Solution: DP
/* 
 * Memory Limit Exceeded
 */

class NumArray {
public:
	// dp[i][j] 表示从i 到 j的和
	// 因此构建一个 n*n 的二维数组，调用sumRange时直接返回数组的元素就好了
    NumArray(vector<int> &nums) 
    {
        if (nums.empty()) return;
        int N = nums.size();
/*        
	dp = new int*[N];
        for (size_t i = 0; i < N; ++i)
        {
            dp[i] = new int[N];
        }
        memset(dp, 0, sizeof(dp));
*/
        vector<vector<int> > tmp(N, std::vector<int>(N, 0));
        dp = tmp;

        // 边界条件
        dp[0][0] = nums[0];
        for (size_t i = 1; i < N; ++i)
            dp[i][0] = dp[0][i] = (dp[i-1][0] + nums[i]);
        
        for (size_t i = 1; i < N; ++i)
        {
            for (size_t j = i; j < N; ++j)
            {
                if (i == j)
                    dp[i][j] = nums[i];
                else
                    dp[i][j] = dp[i][j-1] + nums[j];
            }
        }
    }

    int sumRange(int i, int j) {
        const int N = dp.size();
        if (i >= N || j >= N) return false;
        return dp[i][j];
    }
    
    ~NumArray()
    {
/*
        int N = sqrt(sizeof(dp)/sizeof(int));
        for (size_t i = 0; i < N; ++i)
            delete[] dp[i];
        delete[] dp;
*/ 
    }
    
private:
    //int **dp;
    //static int N;

    vector<vector<int> > dp;
};


// Second Solution: one dimension array
class NumArray {
public:
    NumArray(vector<int> &nums) 
   {
        res = nums;
        for (int i = 1; i < nums.size(); ++i)
            res[i] += res[i-1];
        
    }

    int sumRange(int i, int j) 
   {
        if (i >= res.size() || j >= res.size() || i > j)
            return 0;
        int nums_i = (i == 0 ? res[i] : res[i]-res[i-1]);
        return res[j]-res[i]+nums_i;
    }

private:
    vector<int> res;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);



int main()
{
    int arr[] = {1,2, 3};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(int));
    NumArray numArray(v);
    std::cout << numArray.sumRange(0, 1) << std::endl;
    std::cout << numArray.sumRange(1, 2) << std::endl;

    return 0;
}
