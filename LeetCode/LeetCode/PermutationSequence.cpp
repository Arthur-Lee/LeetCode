//The set[1, 2, 3, …, n] contains a total of n!unique permutations.
//
//By listing and labeling all of the permutations in order,
//We get the following sequence(ie, for n = 3) :
//
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
//Given n and k, return the kth permutation sequence.
//
//Note: Given n will be between 1 and 9 inclusive.


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

///  注意　algorithm中的 next_permutation 实现
/// 更好的方法： http://blog.csdn.net/doc_sgl/article/details/12840715
class Solution {
public:
	string getPermutation(int n, int k) {
		int* digits = new int[n];

		for (int i = 0; i < k; ++i)
		{
			next_permutation(digits, digits + n);
		}
		string result;
		result.resize(n);
		for (int i = 0; i < n; ++i)
		{
			result[i] = (char)(digits[i] - 0 + '0');
		}


		delete[] digits;
		return result;
	}
};