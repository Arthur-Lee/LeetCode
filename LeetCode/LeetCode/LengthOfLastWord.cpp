#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s)
	{
		if (s.size() == 0)
			return 0;

		for (int i = s.length() -1; i>=0; --i)
		{
			if (s[i] == ' ')
				s.erase(i);
			else
				break;
		}

		int index = s.find_last_of(' ');
		if (index == -1)
			return s.length();
		else
			return s.length() - index - 1;
	}
};



//int main()
//{
//	Solution sln;
//	sln.lengthOfLastWord("b    a     ");
//	return 0;
//
//}