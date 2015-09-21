#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;

		if (matrix.size() == 0)
			return result;

		int rows = matrix.size();
		int columns = matrix[0].size();
		result.resize(rows*columns);

		int x = 0;
		int y = 0;
		int count = 0;
		for (y = 0; y < columns; ++y)
		{
			result[count++] = matrix[x][y];
		}
		y = columns - 1;    //// y 必须大于1，才有意义
		if (y > 0)
		{
			for (x = 1; x < rows; ++x)
			{
				result[count++] = matrix[x][y];
			}
		}

		x = rows - 1;
		if (x > 0)
		{
			for (y = columns - 2; y >= 0; --y)
			{
				result[count++] = matrix[x][y];
			}
		}

		y = 0;
		for (x = rows - 2; x >= 1; --x)
		{
			result[count++] = matrix[x][y];
		}
		if (rows <= 2 || columns <= 2)
			return result;

		vector<vector<int>> temp;
		temp.resize(rows - 2);
		for (int i = 0; i < rows - 2; ++i)
		{
			temp[i].resize(columns - 2);
			copy(matrix[i + 1].begin() + 1, matrix[i + 1].end() - 1, temp[i].begin());
		}
		vector<int> r = spiralOrder(temp);

		copy(r.begin(), r.end(), result.begin() + count);
		return result;

	}
};


int main()
{
	Solution sln;
	vector<vector<int>> test;
	test.resize(1);
	test[0].resize(2);
	test[0][0] = 3;
	test[0][1] = 2;


	sln.spiralOrder(test);

}