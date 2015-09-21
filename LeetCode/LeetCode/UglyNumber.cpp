//Write a program to check whether a given number is an ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//
//Note that 1 is typically treated as an ugly number.



#include <iostream>

using namespace std;

/// 6 min

/// 判断特定表达式是否成立时，需要包含所有全集！！！
/// 注意边界点的问题

class Solution {
public:

	bool isUgly(int num) {
		if (num == 1)
			return true;

		while (true)
		{
			if (num == 1)
				return true;
			if (num <= 0) // 注意边界
				return false;

			if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0)
				return false;

			if (num % 2 == 0)
				num = num / 2;
			if (num % 3 == 0)
				num = num / 3;
			if (num % 5 == 0)
				num = num / 5;
		}

	}
};