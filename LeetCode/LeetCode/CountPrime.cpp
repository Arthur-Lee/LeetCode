//Description:
//
//Count the number of prime numbers less than a non - negative number, n.
//
//Credits :
//		Special thanks to @mithmatt for adding this problem and creating all test cases.

/// min: 16
/// 尽量减少代码的编写，多使用指针
/// 初始化用 memset 更快

#include <iostream>

using namespace std;

class Solution {
public:

	int countPrimes(int n) {
		bool* isPrime = new bool[n+1];
		initial(isPrime, n + 1); // memset(isPrime,true,sizeof(bool)*n)
		if (n == 1)
		{

			delete[] isPrime;
			return 1;
		}

		CustomCal(isPrime,n+1);
		int nCount = 0;
		for (int i = 1; i < n + 1; ++i)
		{
			if (isPrime[i])
				++nCount;
		}

		delete[] isPrime;
		return nCount;
	}
	void CustomCal(bool* primes, int size)
	{
		for (int i = 2; i <sqrt(size); ++i)
		{
			if (primes[i])
			{
				for (int j = i+1; j < size; ++j)// set: primes[i * [2,...] = false;
				{
					if (primes[j]&& j%i == 0)
					{
						primes[j] = false;
					}
				}
			}
		}
	}
	void initial(bool* primes, int size)
	{
		for (int i = 0; i < size; ++i)
		{
			primes[i] = true;
		}

	}
};