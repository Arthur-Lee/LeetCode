#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
/// vector<int>::reverse_iterator Ϊ����������� vector<int>.rbegin(),rend() �ֱ𷵻ط���������������������������������������

/// �������������������ʼ���� vector<int>::reverse_iterator riter(v.end())  ��ʾ��������ĵ�һ��Ԫ��

/// erase����ֻ����iterator���ͣ� �������� ����������е�base()����ȡ�����������


/// lower_bound ���ص�һ�����ڻ����val��λ�ã�
/// upper_bound ���ش���val�ĵ�һ������λ�ã���������������������

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


		///// ���󣡣����� ��ȥĳ��������ʱ��Ӱ����nums.rend()����ֵ
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
				index[i] = 0; // ʹ���������򣡣�����������
				++zeroCount;
			}
		}

		int start, end;
		int i = 0;
		for (int j = 1; j <= zeroCount; ++j)
		{
			cout << i;

			/// iΪ���Ի�������i>size ��������ϡ�����ѭ��
			while (index[i] < j&&i < size)			{ ++i; }    /// ��������Ϊ[0,0,1] --> [0,0,2] ����0������û��1����
			
			if (i != size)   ///�ҵ�ƥ������
			{
				j = index[i];
			}

			start = i;
			while (i < size&&index[++i] == j){}    /// ע��ѭ���˳�ʱ�䣡��������������������
			end = i;
			if (start != end)
				copy(nums.begin() + start, nums.begin() + end, nums.begin() + start - j);  //��jΪ��Ծ��׼
		}

		if (zeroCount > 0)
		{
			fill_n(nums.end() - zeroCount, zeroCount, 0);   //// һ��Ҫ�������еĿ����ԣ�����������zeroCount=0ʱ��num.end()û�����壬�����Runtime error
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