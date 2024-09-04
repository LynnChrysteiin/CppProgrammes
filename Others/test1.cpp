#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
	vector<int> canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		vector<vector<int>> graph(numCourses);
		vector<int> indeg(numCourses);
		for (auto &x : prerequisites)
		{
			int u = x[1], v = x[0];
			graph[u].push_back(v);
			indeg[v]++;
		}
		queue<int> Q;
		for (int i = 0; i < numCourses; i++)
			if (indeg[i] == 0)
				Q.push(i);
		vector<int> ans;
		while (!Q.empty())
		{
			int node = Q.front();
			Q.pop();
			ans.push_back(node);
			for (auto x : graph[node])
			{
				if (--indeg[x] == 0)
					Q.push(x);
			}
		}
		return (ans.size() == numCourses) ? ans : vector<int>();
	}
};

int main()
{
	vector<vector<int>> prerequisites = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {0, 3}};
	Solution S;
	auto res = S.canFinish(4, prerequisites);
	for (auto x : res)
		cout << x << " ";
	return 0;
}
