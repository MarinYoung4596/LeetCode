/*
396. Rotate Function

Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
*/


// First Solution: TLE
class Solution {
public:
    int maxRotateFunction(vector<int>& A) 
    {
        if (A.empty()) return 0;
        
        const auto n = A.size();
        int maxf = INT_MIN;
        
        for (auto i = 0; i < n; ++i)
        {
            int tmp = 0;
            for (auto j = 0; j < n; ++j)
            {
                tmp += j * A[(i+j)%n];
            }
            maxf = max(maxf, tmp);
        }
        return maxf;
    }
};

// Second Solution: TLE
class Solution {
public:
    int maxRotateFunction(vector<int>& A) 
    {
        if (A.empty()) return 0;
        int result = INT_MIN;
        vector<int> v(A);
        for (auto i = 0; i < A.size(); ++i)
        {
            copy(A.begin(), A.end()-i, v.begin()+i);
            copy(A.end()-i, A.end(), v.begin());
            
            calculate(v, result);
        }
        return result;
    }
    
private:
    void calculate(vector<int> &v, int &max_result)
    {
        int tmp = 0;
        for (auto i = 0; i < v.size(); ++i)
        {
            tmp += i*v[i];
        }
        max_result = max(max_result, tmp);
    }
};

// Third Solution: O(N)
class Solution {
public:
    int maxRotateFunction(vector<int>& A) 
    {
        if (A.empty()) return 0;
        
        const int n = A.size();
        int start_result = 0, sum = 0;
        // F(0) = (0*A[0]) + (1*A[1]) + ... + ((n-1)*A[n-1])
        for (auto i = 0; i < n; ++i)
        {
            start_result += i*A[i];
            sum += A[i];
        }
        int max_result = start_result;
        // F(1) = 0*A[0]+1*A[1]+...+(n-1)*A[n-1] + (A[0]+A[1]+...+A[n-1]-n*A[n-1])     = 1*A[0]+2*A[1]+...+(n-1)*A[n-2] + (n*A[n-1]-n*A[n-1])
        // F(2) = 1*A[0]+...+(n-1)*A[n-2] + 0*A[n-1] + (A[0]+A[1]+...+A[n-1]-n*A[n-2]) = 2*A[0]+3*A[1]+...+(n-2)*A[n-3] + (0*A[n-2]+1*A[n-1])
        for (auto i = n-1; i >= 0; --i)
        {
            start_result += (sum - n*A[i]);
            max_result = max(max_result, start_result);
        }
        
        return max_result;
    }
};