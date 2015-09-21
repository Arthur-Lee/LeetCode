//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
///// lower_bound, upper_bound ����ʹ��
///// ��̬����Ϊȫ�ֱ�����ֻ�������ж��壬��ʱû���ڴ�
///// ���������ⲿ���������������ڴ棡����������������������
//
///// vector ��������ʼ��֮��size��СΪ0�� ��ʱ����ֱ�ӣ�vector[0] =1;�����ᵼ�²ݹ�����λ�á�Ӧʹ��at����
///// ʹ��at����������insert������
//
///// sort ����Ҫ���ݺ���ָ������£�һ��ʹ�þ�̬��������ָ��
//
////// ��������������������������������������������������������������������������������������������������
///// ����Ч�ķ���������������ѹ��hashtabel�У��������Բ����ض�ֵʱ���ó���ʱ������Ƿ�õ�����ֵ
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