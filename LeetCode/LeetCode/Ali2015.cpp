#include <iostream>
#include <algorithm>
using namespace std;

const int size23 = 2014;
double* cons = new double[size23] {-1};

double getResult(int i)
{
	if (i > 6)
	{
		if (cons[i - 1] > 0)
			return cons[i - 1];
		else
		{
			cons[i-1] = (getResult(i - 1) + getResult(i - 2) + getResult(i - 3) + getResult(i - 4) + getResult(i - 5) + getResult(i - 6)) / 6;
			return cons[i - 1];
		}
	}
	else if (i == 1)
	{
		cons[0]= 1.0 / 6;
		return cons[0];
	}
	else 
	{
		if (cons[i - 1] > 0)
			return cons[i - 1];
		else
		{
			double result = 1.0 / 6;
			for (int j = 1; j < i; j++)
			{
				result += getResult(j) / 6;
			}
		
			cons[i - 1] = result;
			return result;
		}



	}

}

//int main()
//{
//	
//	double alters[] = { 2.0 / 3, 1.0 / 2, 1.0 / 3, 2.0 / 7, 1.0 / 6, 1.0 / 7 };
//	double re = getResult(2014);
//
//	for (size_t i = 0; i < 6; i++)
//	{
//		alters[i] = abs(alters[i] - re);
//	}
//
//	int result = min_element(alters, alters + 6) - alters;
//
//	cout << result << endl;
//	return 0;
//}



int main(void)
{
http: //www.taobao.com
	cout << "welcome to taobao" << endl;

	return 0;


}