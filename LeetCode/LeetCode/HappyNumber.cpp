//
//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process : Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.



#include <iostream>
#include <set>
#include <list>
using namespace std;

/// 20 min
/// set.find 函数使用
/// 注意边界：


class Solution {
public:
	set<int> posNums;
	bool isHappy(int n) {
		if (n <= 0)
			return false;
		posNums.clear();

		posNums.insert(n);  ///边界

		while (true)
		{
			if (n == 1)
				return true;

			n = toDigits(n);

			if (posNums.find(n) != posNums.end())
				return false;

			posNums.insert(n);
		}
	}

	int toDigits(int dig)
	{
		int sum = 0;
		while (true)
		{
			sum += pow(dig % 10, 2);
			dig = dig / 10;
			if (dig == 0)
				break;
		}
		return sum;
	}
};