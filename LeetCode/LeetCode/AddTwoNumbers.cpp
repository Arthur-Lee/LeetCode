
#include <iostream>
#include <ctime>
using namespace std;

//Definition for singly - linked list.

/// ָ�����͵�ʹ�ã��� ������һ��ָ�����ͣ�û��ʹ��new���������ڴ棬��ô��ָ��Ϊ�գ�δ��ʼ�����ܽ��г�Ա�����Ķ�ȡ��

/// ��������� ����new ������ʾ�����ڴ档 �� ������ͨ�ڴ棬ջ�ڴ棬�����Զ�������ƥ��Ĺ��캯�����з����ڴ棡������

/// �Զ��幹�캯�����޲���Ĭ�Ϲ��캯���������ټ���ʹ�á�������������������


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode() :val(0), next(NULL){}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		struct ListNode* result;
		int size1 = 0;
		int size2 = 0;
		struct ListNode* temp1 = l1;
		struct ListNode* temp2 = l2;
		while (temp1 != NULL)
		{
			++size1;
			temp1 = temp1->next;
		}
		while (temp2 != NULL)
		{
			++size2;
			temp2 = temp2->next;
		}
		if (size1 < size2) // ��֤l1 ��С���� l2, ////////////// ͬʱҲҪ���������б�size�Ĵ�С��������������������
		{
			temp1 = l1;
			l1 = l2;
			l2 = temp1;
			int t = size1;
			size1 = size2;
			size2 = t;
		}
		result = l1;

		int in = 0;
		for (int i = 0; i < size2; ++i)
		{
			
			l1->val = l1->val + l2->val + in;

			if (l1->val > 9)
			{
				in = 1;
				l1->val = l1->val - 10;
			}
			else
				in = 0;
			if (i != size2 -1)
			{
				l1 = l1->next;
				l2 = l2->next;
			}
		}
		
		if (size1 > size2)
		{
			l1 = l1->next;
			for (int i = 0; i < size1 - size2; ++i)
			{
				l1->val = l1->val + in;

				if (l1->val > 9)
				{
					in = 1;
					l1->val = l1->val - 10;
				}
				else
					in = 0;
				if (l1->next != NULL)
				{
					l1 = l1->next;
				}
			}
		}
		
		if (in != 0)
		{
			struct ListNode* temp = new struct ListNode;// �����޲ι��캯��
			temp->val = in;
			l1->next = temp;
		}
		return result;
	}
};


//int main()
//{
//	double time_start = clock();
//	Solution sln;
//	struct ListNode* in1 = new struct ListNode;
//	in1->val = 9;
//	struct ListNode* tem=new struct ListNode;
//	tem->val = 9;
//	in1->next = tem;
//	struct ListNode* in2 = new struct ListNode;
//	in2->val = 1;
//	sln.addTwoNumbers(in1, in2);
//
//	cout << clock() - time_start;
//
//
//}