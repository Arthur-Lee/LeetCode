#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <ctime>
#include <hash_map>

using namespace std;


 //��ʱ

/// ���������з���ֵʱ�����뱣֤�з���ֵ����д����ʱ��д����ֵ
/// ѭ�����帴��ʱ������ʮ��ע�������ֵ������������������������

/// MS sort���õ�����ν�ġ� strict weak ordering����Ҳ����˵�����a==b���򷵻ص�Ӧ����false��������ص���true����������Ĵ�
/// predicate ��֤ a =b ����false������������������������

/// ���ѭ����֮��Ϊ�ۼӹ�ϵʱ�����һ��ָ��ֵӦ�ñ�֤���ܳ�������ķ�Χ������������������
/// ����Ĵ�С����ֱ�ӷ��������в�ֵ������Ҫ -1����������������������

/// map ��ͬ�� hashmap �ڲ�ʵ��Ϊ �����������Ҳ�������ʱ��
/// unordered_map �� unordered_set �ڲ�ʵ�־�Ϊ hashmap,Ч�ʱȽϸߡ�(ע�ⲻ��unsorted_map)
/// unoedered_map ����ֵ����


//// ��ʱ�����Ӷ�Ϊ n2 logn
//class Solution {
//public:
//	static vector<int> m_nums;
//	vector<vector<int>> result;
//	vector<vector<int>> threeSum(vector<int>& nums)
//	{
//		Solution::m_nums = nums;
//		result.clear();
//		int nCount = 0;
//
//		int* index = new int[nums.size()];
//
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			index[i] = i;
//		}
//
//		sort(index, index + nums.size(), predicate);// ����index
//
//		int index1, index2, index3;
//
//		int first, end, mid;
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			index1 = i;
//
//			for (int j = i + 1; j < nums.size(); ++j)
//			{
//				index2 = j;
//				index3 = -1;
//				// ��ǰ�ų�һЩ���,���������������֮��㲻���г����Ŀ���
//				if (nums.size() == j + 1)
//					break;
//
//				if (nums[index[i]] + nums[index[j]] + nums[index[j + 1]]>0)
//				{
//					break;   /// break Ϊ��������ѭ�����ų�֮�����е� j �Ŀ����ԣ�������
//				}
//				if (nums[index[i]] + nums[index[j]] + nums[index[nums.size()-1]] < 0)
//				{
//					continue;  /// �������Ϊ��j ȷ����֮�����к;�С��0����������������������
//				}
//					
//
//				first = index2 + 1;
//				end = nums.size();
//				while (first<end)
//				{
//					mid = first + (end - first) / 2;
//					if (nums[index[mid]] >  -nums[index[i]] - nums[index[j]])
//					{
//						end = mid;
//					}
//					else if (nums[index[mid]] < -nums[index[i]] - nums[index[j]])
//					{
//						first = mid + 1;
//					}
//					else
//					{
//						index3 = mid;
//						vector<int> temp;
//						temp.resize(3);
//						temp[0] = nums[index[index1]];
//						temp[1] = nums[index[index2]];
//						temp[2] = nums[index[index3]];
//						if (!isInResult(temp))
//							result.push_back(temp);
//						break;    //note�� ֮ǰѰ��ֵû��break�������һ����ѭ������������
//
//					}
//				}
//
//			}
//		}
//		delete[] index;
//		return result;
//	}
//
//	static bool predicate(int a, int b)
//	{
//		return Solution::m_nums[a] < Solution::m_nums[b];
//	}
//
//	bool isInResult(vector<int> in)
//	{
//		bool r = false;
//		int i = 0;
//		for (vector<vector<int>>::iterator iter = result.begin(); iter != result.end(); ++iter)
//		{
//			for (i = 0; i < in.size(); ++i)
//			{
//				if ((*iter)[i] != in[i])
//					break;
//			}
//			if (i == in.size())
//			{
//				r = true;
//				break;
//			}
//		}
//		return r;
//	}
//
//};
//
//vector<int> Solution::m_nums;

//
//class Solution {
//
//public:
//	vector<vector<int>> result;
//	unordered_map<int, int> digitToIndex;
//	vector<vector<int>> threeSum(vector<int>& nums)
//	{
//		
//		digitToIndex.clear();
//		convertToCount(nums);
//
//
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			double time_start = clock();
//
//			--digitToIndex[nums[i]];
//			for (int j = i+1; j < nums.size(); ++j)
//			{
//				--digitToIndex[nums[j]];
//
//				/// ����ȷ����Ԫ�ش��ڣ�֮��֤�����ݽڵ��������0
//				if (digitToIndex.find(-nums[i] - nums[j]) != digitToIndex.end() && digitToIndex[-nums[i] - nums[j]]>0)
//				{
//					vector<int> temp;
//					temp.resize(3);
//					temp[0] = nums[i];
//					temp[1] = nums[j];
//					temp[2] = -nums[i] - nums[j];
//					sort(temp.begin(), temp.end());
//
//					if (!isInResult(temp))
//						result.push_back(temp);
//				}
//				++digitToIndex[nums[j]];
//			}
//			++digitToIndex[nums[i]];
//
//			cout << clock() - time_start<<"\n";
//		}
//		return result;
//	}
//
//	bool isInResult(vector<int> in)    //// �ٶ����Ļ����Խ��˴�����hashmap �ӿ�����ٶ�
//	{
//		bool r = false;
//		int i = 0;
//		for (vector<vector<int>>::iterator iter = result.begin(); iter != result.end(); ++iter)
//		{
//			for (i = 0; i < in.size(); ++i)
//			{
//				if ((*iter)[i] != in[i])
//					break;
//			}
//			if (i == in.size())
//			{
//				r = true;
//				break;
//			}
//		}
//		return r;
//	}
//
//	void convertToCount(vector<int> in)
//	{
//		for (vector<int>::iterator iter = in.begin(); iter != in.end(); ++iter)
//		{
//			++digitToIndex[*iter];
//		}
//	}
//};

/// �����߳��������Ӷ�Ϊ n 2

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		// Start typing your C/C++ solution below  
		// DO NOT write int main() function  
		vector<vector<int> > output;
		if (num.size()<3) return output;

		sort(num.begin(), num.end());

		int i = 0, j, k, n;
		n = num.size();
		while (i<n){
			if (num[i] > 0){//no solution  
				break;
			}
			int temp = 0 - num[i];
			j = i + 1;
			k = n - 1;
			while (j<k){
				int sum2 = num[j] + num[k];
				if (sum2 == temp){//found one triplet  
					vector<int> triplet;
					triplet.push_back(num[i]);
					triplet.push_back(num[j]);
					triplet.push_back(num[k]);
					output.push_back(triplet);
					//Be careful, we want to skip all the duplicate numbers,   
					//so that no duplicate triplets are recorded  
					j++;
					while (j<k && num[j - 1] == num[j]) j++;
					k--;
					while (k>j && num[k + 1] == num[k]) k--;
				}
				else if (sum2 > temp){
					k--;
					while (k>j && num[k + 1] == num[k]) k--;
				}
				else{
					j++;
					while (j<k && num[j - 1] == num[j]) j++;
				}
			}
			i++;
			while (i<n && num[i - 1] == num[i]) i++;
		}
		return output;
	}
};

//int main()
//{
//	double time_start = clock();
//	Solution sln;
//	int t[] = { -10, 5, -11, -15, 7, -7, -10, -8, -3, 13, 9, -14, 4, 3, 5, -7, 13, 1, -4, -11, 5, 9, -11, -4, 14, 0, 3, -10, -3, -7, 10, -5, 13, 14, -5, 6, 14, 0, 5, -12, -10, -1, -11, 9, 9, 1, -13, 0, -13, -1, 4, 0, -7, 8, 3, 14, -15, -9, -10, -3, 0, -15, -1, -2, 6, 9, 11, 6, -14, 1, 1, -9, -14, 6, 7, 10, 14, 2, -13, -13, 8, 6, -6, 8, -9, 12, 7, -9, -11, 4, -4, -4, 4, 10, 1, -12, -3, -2, 1, -10, 6, -13, -3, -1, 0, 11, -5, 0, -2, -11, -6, -9, 11, 3, 14, -13, 0, 7, -14, -4, -4, -11, -1, 8, 6, 8, 3 };
//	vector<int> test;
//	test.resize(127);
//	for (int i = 0; i < 127; ++i)
//	{
//		test.push_back(t[i]);
//	}
//	
//	vector<vector<int>> res;
//
//	res = sln.threeSum(test);
//
//	cout << clock() - time_start;
//	test.clear();
//
//}