//
////--------------------------------------������˵����-------------------------------------------
////		����˵����
////		����������
////		IDE�汾��Visual Studio 2013
////		���ߣ�[��Ա���֣���С������]
////------------------------------------------------------------------------------------------------  
//
////��1��ͷ�ļ�
//#include <fstream>
//#include <ctime>
//
//using namespace std;
//
//#define TIMER
////��2����������
//
//
////��3������ö���壬�ڼ��ַ������л�
//enum Method
//{
//
//};
//
////��4����������
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
////��5������ʵ��


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