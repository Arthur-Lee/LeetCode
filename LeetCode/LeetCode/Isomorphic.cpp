//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters.No two characters may map to the same character but a character may map to itself.
//
//For example,
//Given "egg", "add", return true.
//
//Given "foo", "bar", return false.
//
//Given "paper", "title", return true.
//
//Note:
//You may assume both s and t have the same length.


#include <iostream>
#include <string>
#include <set>
#include <map>	
#include <algorithm>
using namespace std;

/// 56 min

/// 判断Map 中某个 key值是否对应为空！！ 利用find 函数
/// 判断两组之间的对应关系，需要两队 map

class Solution {
public:

	map<char, char> StoDRelation;
	map<char, char> DtoSRelation;

	map<char, int> ScharCount;
	map<char, int> DcharCount;

	bool isIsomorphic(string s, string t) {
		initial();

		if (s.size() != t.size())
		{
			return false;
		}
		for (int i = 0; i < s.size(); ++i)
		{
			++ScharCount[s[i]];
			++DcharCount[t[i]];
		}
		if (!isDicEqual())
			return false;


		for (int i = 0; i < t.size(); ++i)
		{
			if (StoDRelation.find(s[i]) == StoDRelation.end()) //未找到对应字符
			{
				StoDRelation[s[i]] = t[i];
			}
			else
			{
				if (StoDRelation[s[i]] != t[i])
					return false;
			}

			if (DtoSRelation.find(t[i]) == DtoSRelation.end()) //未找到对应字符
			{
				DtoSRelation[t[i]] = s[i];
			}
			else
			{
				if (DtoSRelation[t[i]] != s[i])
					return false;
			}

		}
		return true;
	}

	void initial()
	{
		for (char c = 'a'; c <= 'z'; ++c)
		{
			ScharCount[c] = 0;
			DcharCount[c] = 0;
		}
		for (char c = 'A'; c <= 'Z'; ++c)
		{
			ScharCount[c] = 0;
			DcharCount[c] = 0;
		}
		StoDRelation.clear();
		DtoSRelation.clear();
	}
	bool isDicEqual()
	{
		int srcCount[52];
		int dstCount[52];
		for (char c = 'a'; c <= 'z'; ++c)
		{
			srcCount[c - 'a'] = ScharCount.count(c);
			dstCount[c - 'a'] = DcharCount.count(c);
		}
		for (char c = 'A'; c <= 'Z'; ++c)
		{
			srcCount[26+c - 'A'] = ScharCount.count(c);
			dstCount[26+c - 'A'] = DcharCount.count(c);
		}

		sort(srcCount, srcCount + 52);
		sort(dstCount, dstCount + 52);
		
		for (int i = 0; i < 52; ++i)
		{
			if (srcCount[i] != dstCount[i])
				return false;
		}

		return true;
	}
};

