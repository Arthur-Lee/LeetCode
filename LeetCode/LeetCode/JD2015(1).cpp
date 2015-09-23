//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int Max_N = 100;
//
//class line
//{
//public:
//	int x;
//	int y;
//};
//
//class CusInc
//{
//public:
//	bool operator()(line& l1, line& l2)
//	{
//		return l1.x < l2.x;
//	}
//};
//
//int main()
//{
//	line* lines = new line[Max_N];
//	int m, n;
//	cin >> m >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> lines[i].x >> lines[i].y;
//	}
//	sort(lines, lines + n, CusInc());
//
//	int lights = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		lights += lines[i].y - lines[i].x + 1;
//		if (i > 0)
//		{
//			if (lines[i].x <= lines[i - 1].y)
//			{
//				lights -= lines[i - 1].y - lines[i].x + 1;
//
//				lines[i].x = lines[i - 1].x;
//			}
//		}
//	}
//
//	cout << m + 1 - lights;
//
//}