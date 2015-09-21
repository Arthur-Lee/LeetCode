
#include <iostream>

using namespace std;
/// 7 min
class Solution {
public:
	int addDigits(int num) {
		if (num < 0)
			return -1;
		int sum = 0;
		while (true)
		{
			if (num < 10)
				return num;

			sum = 0;
			while (true)
			{
				sum += num % 10;
				num = num / 10;
				if (num == 0)
					break;
			}
			num = sum;
		}	
	}
};