#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
/// vector<int>::reverse_iterator 为反向迭代器， vector<int>.rbegin(),rend() 分别返回反向迭代器，可以逆序遍历容器！！！！！！！

/// 反向迭代器可以这样初始化： vector<int>::reverse_iterator riter(v.end())  表示反向迭代的第一个元素

/// erase函数只接受iterator类型， 可以利用 反向迭代器中的base()函数取出正向迭代器


/// lower_bound 返回第一个大于或等于val的位置；
/// upper_bound 返回大于val的第一个数的位置！！！！！！！！！！！

using namespace std;


class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int zeroCount = 0;
		int size = nums.size();

		//for (int i = size - 1; i >= 0; --i)
		//{
		//	if (nums[i] == 0)
		//	{
		//		nums.erase(nums.begin() + i);
		//		++zeroCount;
		//	}
		//}


		///// 错误！！！！ 除去某个迭代器时，影响了nums.rend()的求值
		//vector<int>::reverse_iterator end = nums.rend();
		//for (vector<int>::reverse_iterator iter = nums.rbegin(); iter != end; ++iter)
		//{
		//	if ((*iter) == 0)
		//	{
		//		nums.erase(iter.base());
		//		++zeroCount;
		//	}
		//}

		int* index = new int[nums.size()];
		memset(index, 0, sizeof(int)*nums.size());
		for (int i = 0; i < size; ++i)
		{
			if (nums[i] != 0)
			{
				index[i] = 0 + zeroCount;

			}
			else
			{
				index[i] = 0; // 使其满足升序！！！！！！！
				++zeroCount;
			}
		}

		int start, end;
		int i = 0;
		for (int j = 1; j <= zeroCount; ++j)
		{
			cout << i;

			/// i为测试基数，若i>size 则搜索完毕。跳出循环
			while (index[i] < j&&i < size)			{ ++i; }    /// 可能输入为[0,0,1] --> [0,0,2] 输入0相连，没有1！！
			
			if (i != size)   ///找到匹配数据
			{
				j = index[i];
			}

			start = i;
			while (i < size&&index[++i] == j){}    /// 注意循环退出时间！！！！！！！！！！！
			end = i;
			if (start != end)
				copy(nums.begin() + start, nums.begin() + end, nums.begin() + start - j);  //以j为跳跃基准
		}

		if (zeroCount > 0)
		{
			fill_n(nums.end() - zeroCount, zeroCount, 0);   //// 一定要考虑所有的可能性！！！！！若zeroCount=0时；num.end()没有意义，会产生Runtime error
		}


		//while (zeroCount>0)
		//{
		//	nums.push_back(0);
		//	--zeroCount;
		//}
	}
};


int main()
{
	double time_start = clock();
	Solution sln;
	vector<int> in;
	in.push_back(0);

	sln.moveZeroes(in);

	cout << clock() - time_start;


}