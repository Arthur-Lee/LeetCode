/// <summary>
/// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent. 

//Find the maximum coins you can collect by bursting the balloons wisely.

/// </summary>


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//class Solution
//{
//public:
//	// dp solution
//
//	// i to j must have a ballon that burst lastF!!!
//	// dp[i][j] = max(dp[i][j], dp[i][x-1] + nums[i-1]*nums[x]*nums[j+1] + dp[x+1][j]; // x from i to j
//	int maxCoins(vector<int>& nums)
//	{
//		int n = nums.size();
//		nums.insert(nums.begin(), 1);
//		nums.insert(nums.end(), 1);
//
//		vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));
//
//		// k indetify the the body length for dp[i, j]
//		// travel all the possibility for body length for 1 to n    
//		for (int k = 1; k <= n; k++) 
//		{
//			// [i, j] body length from 1 to n
//			for (int i = 1; i <= n - k + 1; ++i) 
//			{
//				int j = i + k - 1;
//				// x between [i, j]                    
//				for (int x = i; x <= j; ++x)
//				{
//					int temp = dp[i][x - 1] + nums[i - 1] * nums[x] * nums[j + 1] + dp[x + 1][j];
//					if (temp > dp[i][j]) dp[i][j] = temp;
//				}
//			}
//		}
//
//		return dp[1][n];
//	}
//
//	// divide and conquer
//	int maxCoins1(vector<int>& nums)
//	{
//		int n = nums.size();
//		nums.insert(nums.begin(), 1);
//		nums.insert(nums.end(), 1);
//		vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));
//		return DP(1, n, nums, dp);
//	}
//
//	// remember search
//	int DP(int i, int j, const vector<int> &nums, vector<vector<int>> &dp) {
//		if (dp[i][j] > 0) return dp[i][j];
//		for (int x = i; x <= j; ++x) {
//			int temp = DP(i, x - 1, nums, dp) + nums[i - 1] * nums[x] * nums[j + 1] + DP(x + 1, j, nums, dp);
//			if (temp > dp[i][j]) dp[i][j] = temp;
//		}
//		return dp[i][j];
//	}
//};

//class Solution {
//public:
//	int maxCoins(vector<int>& nums)
//	{
//		int size = nums.size();
//		nums.insert(nums.begin(), 1);
//		nums.insert(nums.end(), 1);
//
//		int** dp = new int*[size + 2];
//		for (int i = 0; i < size + 2; ++i)
//		{
//			dp[i] = new int[size + 2];
//			memset(dp[i], 0, (size+2)*sizeof(int));
//		}
//
//		for (int len = 1; len <= size; ++len)  // len indicate the length of the segment
//		{
//			for (int i = 1; i <= size - len + 1; ++i)
//			{
//				int j = i + len - 1;
//				for (int x = i; x <= j; ++x)
//				{
//					int temp = dp[i][x - 1] + dp[x + 1][j] + nums[x] * nums[i - 1] * nums[j + 1];
//					dp[i][j] = max(dp[i][j], temp);
//				}
//			}
//		}
//		int result = dp[1][size];
//
//		for (int i = 0; i < size + 2; ++i)
//		{
//			delete[] dp[i];
//		}
//		delete[] dp;
//		return result;
//
//	}
//};

class Solution {
public:
	int maxCoins(vector<int>& nums)
	{

		int size = nums.size();
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);
		dp = new int*[size + 2];
		for (int i = 0; i < size + 2; ++i)
		{
			dp[i] = new int[size + 2];
			memset(dp[i], -1, (size + 2)*sizeof(int));
		}


		int result = 0;

		result = divide(1, size, nums);

		for (int i = 0; i < size + 2; ++i)
		{
			delete[] dp[i];
		}
		delete[] dp;

		return result;
	}
	int divide(int i, int j, vector<int>& nums)
	{
		if (dp[i][j] >= 0)
			return dp[i][j];
		
		int result = 0;
		for (int x = i; x <= j; ++x)
		{
			int temp = nums[x] * nums[i - 1] * nums[j + 1] + divide(i, x - 1, nums) + divide(x + 1, j, nums);  // use memery!!!!!
			result = max(result, temp);
		}
		dp[i][j] = result;
		return result;
	}
	static int** dp;
};

int** Solution::dp;

//int main()
//{
//	Solution sln;
//	sln.maxCoins(vector<int>{2, 7, 9, 10});
//
//	int a[9];
//	int* b = new int[9];
//	cout << sizeof(a) << "     " << sizeof(b);
//	return 0;
//}