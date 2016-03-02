/// <summary>
/// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i]. 
/// </summary>

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//// TLE
//class Solution {
//public:
//	static vector<int> Vectors;
//	vector<int> countSmaller(vector<int>& nums)
//	{
//		if (nums.size() == 0)
//			return vector<int>();
//
//		Vectors = nums;
//		int nCount = nums.size();
//		vector<int> result;
//		result.resize(nCount);
//
//		int* index = new int[nCount];
//		for (int i = 0; i < nCount; i++)
//		{
//			index[i] = i;
//		}
//
//		sort(index, index + nCount, Pred);
//
//		int* with_index = new int[nCount];
//
//		for (int i = 0;i < nCount;++i)
//		{
//			with_index[index[i]] = i;
//		}
//
//		for (int i = nCount - 1; i >= 0; --i)
//		{
//			int j = i + 1;
//			int n = 0;
//
//			for (; j < nCount; j++)
//			{
//				if (with_index[i] < with_index[j] && nums[i]>nums[j])  // number is not equal!
//					++n;
//
//				if (with_index[i] == with_index[j] - 1 || nums[i] == nums[j])
//					break;
//
//			}
//
//			if (j != nCount)
//			{
//				result[i] = n + result[j];
//			}
//			else
//				result[i] = n;
//
//		}
//
//		delete[] index;
//		delete[] with_index;
//
//		return result;
//	}
//
//	static bool Pred(int a, int b)
//	{
//		if ((Vectors[a] > Vectors[b]) || (Vectors[a] == Vectors[b] && a < b))
//			return true;
//		else
//			return false;
//	}
//
//};
//
//vector<int> Solution::Vectors;


//class Solution {
//public:
//	vector<int> countSmaller(vector<int>& nums) {
//		vector<int> ans;
//		if (!nums.size())
//			return ans;
//		vector<int> tmp = nums;
//		int n = nums.size();
//		sort(tmp.begin(), tmp.end());
//		int cnt = 1;
//		for (int i = 0; i < tmp.size(); ++i) 
//		{
//			if (dict.find(tmp[i]) == dict.end())
//				dict[tmp[i]] = cnt++;
//		}
//		ans.resize(nums.size());
//		bittree.resize(nums.size() + 1);
//		for (int i = nums.size() - 1; i >= 0; --i) {
//			ans[i] = add(dict[nums[i]] - 1, n);
//			update(1, dict[nums[i]], n);
//		}
//		return ans;
//	}
//private:
//	//所以返回值为0，表示x=0  返回值为1，表示x为奇数   返回值为其他数，表示x为x与2 ^ 64的最大公约数
//
//	int lowbit(int x)
//	{
//		return x&-x;
//	}
//
//	int add(int sta, int bnd) {
//		int res = 0;
//		for (int i = sta; i > 0; i -= lowbit(i))
//			res += bittree[i];
//		return res;
//	}
//
//	void update(int val, int sta, int bnd) {
//		for (int i = sta; i <= bnd; i += lowbit(i))
//			bittree[i] += val;
//	}
//private:
//	unordered_map<int, int> dict;
//	vector<int> bittree;
//
//
//
//};


//class Solution {
//private:
//	typedef vector<int> vec;
//public:
//	vec countSmaller(vec& nums) {
//		vec ans;
//		int n = 0;
//		if (!(n = nums.size())) return ans;
//		ans.resize(n, 0);
//		ret = new P[n + 10];
//		for (int i = 1; i <= n; i++) ret[i] = P(nums[i - 1], i);
//		sort(ret + 1, ret + n + 1);
//		seg = new int[(n + 10) << 2];
//		memset(seg, 0, sizeof(int)* ((n + 10) << 2));
//		for (int i = 1; i <= n; i++) {
//			int v = query(1, 1, n, ret[i].id, n);
//			insert(1, 1, n, ret[i].id);
//			ans[ret[i].id - 1] = v;
//		}
//		delete[]seg; delete[]ret;
//		return ans;
//	}
//private:
//	struct P {
//		int v, id;
//		P(int _i_ = 0, int _j_ = 0) :v(_i_), id(_j_) {}
//		friend bool operator<(const P &a, const P &b) {
//			return a.v == b.v ? a.id < b.id : a.v < b.v;
//		}
//	}*ret;
//	int *seg;
//	inline void insert(int root, int l, int r, int p) {
//		if (p > r || p < l) return;
//		if (p <= l && p >= r) { seg[root]++; return; }
//		int mid = (l + r) >> 1;
//		insert(root << 1, l, mid, p);
//		insert(root << 1 | 1, mid + 1, r, p);
//		seg[root] = seg[root << 1] + seg[root << 1 | 1];
//	}
//	inline int query(int root, int l, int r, int x, int y) {
//		if (x > r || y < l) return 0;
//		if (x <= l && y >= r) return seg[root];
//		int ret = 0;
//		int mid = (l + r) >> 1;
//		ret += query(root << 1, l, mid, x, y);
//		ret += query(root << 1 | 1, mid + 1, r, x, y);
//		return ret;
//	}
//};


/// use merge 

//class Solution {
//public:
//
//	// nums[left[i]] is the real value ,left array stores only index
//	vector<int> mergerArray(vector<int> left, vector<int> right, vector<int>& nums, vector<int> &res) {
//
//		int lsz = left.size();
//		int rsz = right.size();
//
//		vector<int> re;
//
//
//		int i = 0, j = 0;
//		int cnt = 0;
//
//		while (i < lsz && j < rsz)
//		{
//			if (nums[left[i]] <= nums[right[j]]) {
//				re.push_back(left[i]);
//				res[left[i++]] += cnt;
//			}
//			else {
//				re.push_back(right[j++]);
//				cnt++;
//			}
//		}
//		while (i < lsz) 
//		{
//			re.push_back(left[i]);
//			res[left[i++]] += cnt;
//		}
//		while (j < rsz) 
//		{
//			re.push_back(right[j++]);
//		}
//		return re;
//	}
//
//	void sortArray(vector<int>& re, vector<int>& nums, vector<int>& res) {
//		int sz = re.size();
//		if (sz < 2) return;
//		vector<int> left, right;
//		left.assign(re.begin(), re.begin() + sz / 2);
//		right.assign(re.begin() + sz / 2, re.end());
//		sortArray(left, nums, res);
//		sortArray(right, nums, res);    // left right will change!!
//		re = mergerArray(left, right, nums, res);
//		return;
//	}
//
//	vector<int> countSmaller(vector<int>& nums) {
//		int sz = nums.size();
//		vector<int> res(sz, 0);
//		vector<int> re;
//		for (int i = 0;i < sz;i++)
//		{
//			re.push_back(i);
//		}
//
//		sortArray(re, nums, res);
//		return res;
//	}
//};


//int main()
//{
//	Solution sln;
//	vector<int> input = { 5, 2, 6, 1 };
//	sln.countSmaller(input);
//	return 0;
//}