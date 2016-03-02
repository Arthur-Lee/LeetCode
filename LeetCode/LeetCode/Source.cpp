//
////--------------------------------------【程序说明】-------------------------------------------
////		程序说明：
////		程序描述：
////		IDE版本：Visual Studio 2013
////		作者：[成员名字，或小组名字]
////------------------------------------------------------------------------------------------------  
//
////【1】头文件
//#include <fstream>
//#include <ctime>
//
//using namespace std;
//
//#define TIMER
////【2】函数声明
//
//
////【3】定义枚举体，在几种方法中切换
//enum Method
//{
//
//};
//
////【4】变量声明
//
//
//void main(){
//#ifdef TIMER
//	clock_t start = clock();
//#endif // TIMER
//	ifstream fin("in.txt");
//	if (fin.fail())
//		return;
//	ofstream fout("out.txt");
//	while (!fin.eof())
//	{
//
//	}
//	
//#ifdef TIMER
//	clock_t end = clock();
//	double duration = (double)(end - start);
//	fout << "runtime : " << duration << "ms" << endl;
//#endif // TIMER
//	fout.close();
//
//}
//
//
////【5】函数实现


//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//
//	while (true)
//	{
//
//	}
//}

#include <iostream>
#include <stdio.h>

using namespace std;
char fun(char x, char y)
{
	if (x)
		return (y);
}

//int main()
//{
//	int a = '0', b = '1', c = '2';
//	printf("%c\n", fun(fun(a, b), fun(b, c)));
//	//cout << fun(fun(a, b), fun(b, c));
//	return 0;
//}