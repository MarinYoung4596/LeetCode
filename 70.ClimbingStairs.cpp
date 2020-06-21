/*
70. Climbing Stairs.
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
// First Solution: 尾递归
// f(n): f(n-1) + 1 step or f(n-2) + 2 step
// f(n) = f(n-1) + f(n-2)
int fibonacci_tail(int n, int f1, int f2) {
	if (n < 2) {
		return f1;
    }
    return fibonacci_tail(n - 1, f2, f1 + f2);
}

int climbStairs(int n) {
	return fibonacci_tail(n, 1, 2);
}

// Second Solution: 迭代法
int climbStairs2(int n) {
	int prev = 0;
	int	curr = 1;
	for (int i = 0; i < n; i++) {
		int tmp = curr;
		curr += prev;
		prev = tmp;
	}
	return curr;
}
