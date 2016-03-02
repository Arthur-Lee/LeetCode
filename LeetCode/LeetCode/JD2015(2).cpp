
#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 50;
int boxs[50][50];
int m, n, k;
int model = 1000000007;

int getBoxs(int i, int j, int nBoxs, int max)
{
	int result = 0;

	if (nBoxs == k)
	{
		int t = (n - i - 1)*(m - j - 1);

		//// 对结果取余！！！！！！！！！！
		return (int)pow(2, t) % model;
	}

	// 两者满足一个便返回！！！！
	if (i == n - 1 || j == m - 1)
	{
		return 0;
	}

	if (i + 1 < n)
	{
		if (boxs[i + 1][j] > max)
		{
			result = (result + getBoxs(i + 1, j, nBoxs, max)) % model;
			int temp = boxs[i + 1][j];
			result = (result + getBoxs(i + 1, j, nBoxs + 1, temp)) % model;
		}
		else
		{
			result = (result + getBoxs(i + 1, j, nBoxs, max)) % model;
		}

	}

	if (j + 1 < m)
	{
		if (boxs[i][j + 1] > max)
		{
			result = (result + getBoxs(i, j + 1, nBoxs, max)) % model;
			int temp = boxs[i][j + 1];
			result = (result + getBoxs(i, j + 1, nBoxs + 1, temp)) % model;
		}
		else
		{
			result = (result + getBoxs(i, j + 1, nBoxs, max)) % model;
		}

	}
	return result;

}


//int main()
//{
//
//
//	cin >> n >> m >> k;
//	for (int i = 0; i < n; ++i)
//		for (int j = 0; j < m; ++j)
//		{
//			cin >> boxs[i][j];
//		}
//
//	int out2 = getBoxs(0, 0, 1, boxs[0][0]);
//	int out1 = getBoxs(0, 0, 0, -1);
//	cout << out1 + out2;
//	return 0;
//}