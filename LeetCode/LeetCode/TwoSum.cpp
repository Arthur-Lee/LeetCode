//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
///// lower_bound, upper_bound 函数使用
///// 静态变量为全局变量，只能在类中定义，这时没有内存
///// 必须在类外部进行声明，分配内存！！！！！！！！！！！！
//
///// vector 容器，初始化之后size大小为0； 此时不能直接：vector[0] =1;这样会导致草果访问位置。应使用at函数
///// 使用at函数，或用insert函数，
//
///// sort 中需要传递函数指针情况下，一律使用静态函数传递指针
//
////// ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
///// 更高效的方法，将所有数据压入hashtabel中，这样可以查找特定值时利用常数时间计算是否得到查找值
//
//class Solution {
//public:
//	static vector<int> m_nums;
//	vector<int> twoSum(vector<int>& nums, int target)
//	{
//		Solution::m_nums = nums;
//		int* index = new int[nums.size()];
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			index[i] = i;
//		}
//		sort(index, index + nums.size(), predicate);
//		int index1, index2;
//		int first, end, mid;
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			index1 = i;
//			index2 = -1;
//			first = index1 + 1;
//			end = nums.size();
//
//			while (first<end)
//			{
//				mid = first + (end - first) / 2;
//				if (nums[index[mid]] > target - nums[index[i]])
//				{
//					end = mid;
//				}
//				else if (nums[index[mid]] < target - nums[index[i]])
//				{
//					first = mid + 1;
//				}
//				else
//				{
//					index2 = mid;
//					break;
//				}
//			}
//			if (index2 != -1)
//				break;
//		}
//		index1 = index[index1] + 1;
//		index2 = index[index2] + 1;
//		if (index1 > index2)
//		{
//			int temp = index1;
//			index1 = index2;
//			index2 = temp;
//		}
//		vector<int> result;
//		result.resize(2);
//		result[0] = index1;
//		result[1] = index2;
//		delete[] index;
//		return result;
//	}
//
//	static bool predicate(int a, int b)
//	{
//		return Solution::m_nums[a] <= Solution::m_nums[b];
//	}
//
//};
//
//vector<int> Solution::m_nums;
//
//
//
////int main()
////{
////	Solution sln;
////	vector<int> test;
////	test.resize(3);
////	test[0] = 3;
////	test[1] = 2;
////	test[2] = 4;
////	vector<int> res;
////
////	res = sln.twoSum(test, 6);
////	cout << res[0] << res[1];
////}