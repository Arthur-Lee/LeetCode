#include <iostream>
#include <vector>
using namespace std;


class Solution {

public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result;
		if (n < 0)
		{
			return result;
		}
		result.resize(n);
		for (int i = 0; i < n; ++i)
		{
			result[i].resize(n);
		}
		int i = 0;
		int j = 0;
		int count = 1;

		for (j = 0; j < n; ++j)
		{
			result[i][j] = count++;

		}
		j = n - 1;
		if (j > 0)
		{
			for (i = 1; i < n; ++i)
			{
				result[i][j] = count++;
			}
		}

		i = n - 1;
		if (i > 0)
		{
			for (j = n - 2; j >= 0; --j)
			{
				result[i][j] = count++;
			}
		}

		j = 0;
		for (i = n - 2; i >= 1; --i)
		{
			result[i][j] = count++;
		}
		if (n == 1 || n == 2)
			return result;

		vector<vector<int>> temp = generateMatrix(n - 2);

		for (i = 0; i < n - 2; ++i)
			for (j = 0; j < n - 2;++j)
		{
			temp[i][j] += 4 * n - 4;
		}

		for (i = 1; i < n - 1; ++i)
		{
			copy(temp[i - 1].begin(), temp[i - 1].end(), result[i].begin() + 1);
		}

		return result;
	}
};