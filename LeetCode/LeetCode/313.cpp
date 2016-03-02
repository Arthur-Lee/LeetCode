/// <summary>
/// Write a program to find the nth super ugly number. 
/*
Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]  is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
*/
/// </summary>


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;


//class Solution {
//public:
//	int nthSuperUglyNumber(int n, vector<int>& primes) {
//		vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
//		ugly[0] = 1;
//		for (int i = 1; i<n; i++)
//		{
//			for (int j = 0; j<primes.size(); j++)
//				ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);
//			for (int j = 0; j<primes.size(); j++)
//				index[j] += (ugly[i] == ugly[index[j]] * primes[j]);
//		}
//		return ugly[n - 1];
//	}
//};

typedef struct _item
{
	int index;
	int value;
	int factor;

	_item()
	{
		index = 0;
		value = 0;
		factor = 0;
	}


}item;

template<>
class greater<item>
{
public:
	bool operator()(item one, item two)
	{
		if (one.value > two.value)
			return true;
		else
			return false;
	}
};

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes)
	{
		if (n < 1)
			return -1;

		int* container = new int[1000000 + 1];
		memset(container, 0, sizeof(container)*sizeof(int));

		priority_queue<item, vector<item>, greater<item>> pri_queue;

		item* indexs = new item[100 + 1];
		for (int i = 1; i <= primes.size(); ++i)
		{
			indexs[i].index = 1;
			indexs[i].value = 1;
			indexs[i].factor = primes[i-1];   // primes start from 0!!
			pri_queue.push(indexs[i]);
		}

		for (int i = 1; i <= n; ++i)  // n ugly number
		{

			container[i] = pri_queue.top().value;

			while (pri_queue.top().value== container[i])
			{
				item temp = pri_queue.top();
				pri_queue.pop();
				temp.value = container[temp.index++] * temp.factor;

				pri_queue.push(temp);
			}
		}

		return container[n];
	}
};

//
//int main()
//{
//	Solution sln;
//	sln.nthSuperUglyNumber(5, vector<int>{2, 5, 8});
//	return 0;
//}