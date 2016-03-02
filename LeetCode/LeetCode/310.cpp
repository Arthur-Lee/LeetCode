/// <summary>
/// For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels. 
/// </summary>

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

//
//vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
//	vector<vector<int> > adj_list(n);
//	vector<int> counters(n, 0);
//	for (auto &e : edges) {
//		adj_list[e.first].push_back(e.second);
//		adj_list[e.second].push_back(e.first);
//		++counters[e.first];
//		++counters[e.second];
//	}
//	queue<int> q;
//	for (int i = 0; i < n; ++i) {
//		if (counters[i] <= 1) {
//			q.push(i);
//		}
//	}
//	while (n > 2) 
//	{
//		int num_leafs = q.size();
//		n -= num_leafs;
//		for (int i = 0; i < num_leafs; ++i) {
//			int node = q.front();
//			q.pop();
//			for (auto neighbor : adj_list[node]) {
//				if (--counters[neighbor] == 1) {
//					q.push(neighbor);
//				}
//			}
//		}
//	}
//	vector<int> res;
//	while (!q.empty()) {
//		res.push_back(q.front());
//		q.pop();
//	}
//	return res;
//}


class Solution {
public:
	vector<vector<int>> graph;
	bool* isVisited;
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
	{
		graph.resize(n);
		for each (vector<int> g in graph)
		{
			g.reserve(n);
		}

		isVisited = new bool[n] {false};
		
		vector<pair<int, int>>::iterator iter;
		for each (auto p in edges)
		{
			int first = p.first;
			int second = p.second;
			graph[first].push_back(second);
			graph[second].push_back(first);
		}

		int* points1 = new int[n];
		int* points2 = new int[n];
		int* pre = new int[n];
		isVisited[0] = true;
		breadthFirstSearch(0, points1, pre);

		int u;
		int max_length = -1;

		for (int i = 0; i < n; ++i)
		{
			if (max_length < points1[i])
			{
				max_length = points1[i];
				u = i;
			}
		}
	
		delete[] isVisited;
		isVisited = new bool[n];
		isVisited[u] = true;

		breadthFirstSearch(u, points2, pre);
		max_length = -1;
		for (int i = 0; i < n; ++i)
		{
			if (max_length < points2[i])
			{
				max_length = points2[i];
				u = i;
			}
		}

		vector<int> path;
		path.push_back(u);
		while (pre[u] != -1)
		{
			path.push_back(pre[u]);
			u = pre[u];
		}

		if (path.size() % 2 == 0)
		{
			return vector<int>{path[path.size()/2-1], path[path.size() / 2]};
		}
		else
		{
			return vector<int>{path[path.size()/2]};
		}

	}

	void breadthFirstSearch(int start, int* p, int* prevs)
	{
		list<int> que;
		que.push_front(start);

		p[start] = 0;
		prevs[start] = -1;

		while (!que.empty())
		{
			int temp = que.front();
			que.pop_front();

			for each (int adj in graph[temp])
			{
				if (!isVisited[adj])
				{
					isVisited[adj] = true;
					p[adj] = p[temp] + 1;
					prevs[adj] = temp;
					que.push_back(adj);
				}
			}

		}
	}

};
