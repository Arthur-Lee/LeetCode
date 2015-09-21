#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ctime>
using namespace std;

//// 千万不要写到兴致，少写了函数调用！！！！！！！！！！！！！
class Solution {
public:
	unordered_map<int, int> digitToIndex;

	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());

		convertToCount(nums);
		int nSize = nums.size();
		if (nSize < 4)
			return result;
		int firstSum, secondSum;

		for (int j = 0; j < nSize - 3;)
		{
			for (int k = j + 1; k < nSize - 2;)
			{
				firstSum = nums[j] + nums[k];
				secondSum = target - firstSum;

				for (int m = k + 1; m < nSize - 1;)
				{

					if (nums[m] + nums[m+1]>secondSum)
					{
						break;
					}

					if (nums[m] + nums[nSize - 1] < secondSum)  //continue 之后，跳过了之后的index累加，造成死循环！！！！！！！！！！
						goto label;


					--digitToIndex[nums[j]];
					--digitToIndex[nums[k]];

					--digitToIndex[nums[m]];

					if (digitToIndex.find(secondSum - nums[m]) != digitToIndex.end() && digitToIndex[secondSum - nums[m]]>0)
					{
						vector<int> temp;
						temp.push_back(nums[j]);
						temp.push_back(nums[k]);
						temp.push_back(nums[m]);
						temp.push_back(secondSum - nums[m]);

						result.push_back(temp);

					}
					++digitToIndex[nums[j]];
					++digitToIndex[nums[k]];

					++digitToIndex[nums[m]];

				label:
					while (m < nSize - 1 && nums[m] == nums[++m]){}
				}
				while (k < nSize - 2 && nums[k] == nums[++k]){}
			}
			while (j < nSize - 3 && nums[j] == nums[++j]){}
		}
		return result;

	}

	void convertToCount(vector<int> in)
	{
		for (vector<int>::iterator iter = in.begin(); iter != in.end(); ++iter)
		{
			++digitToIndex[*iter];
		}
	}
};


//int main()
//{
//	double time_start = clock();
//	Solution sln;
//	int t[] = { 0,0,0,0 };
//	vector<int> test;
//	test.resize(4);
//	for (int i = 0; i < 4; ++i)
//	{
//		test.push_back(t[i]);
//	}
//	
//	vector<vector<int>> res;
//
//	res = sln.fourSum(test,0);
//
//	cout << clock() - time_start;
//	test.clear();
//
//}