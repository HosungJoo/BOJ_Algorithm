#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int>kb[101];
int N, M;

int bfs(int num)
{
	queue<int>q;
	q.push(num);
	int visited[101] = { 0, };
	visited[num] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < kb[now].size(); i++)
		{
			int next = kb[now][i];
			if (visited[next] != 0) continue;
			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}
	
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i == num) continue;
		sum += (visited[i] - 1);
	}
	return sum;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		kb[from].push_back(to);
		kb[to].push_back(from);
	}

	int dist = 21e8;
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		int ret = bfs(i);
		if (ret < dist)
		{
			dist = ret;
			ans = i;
		}
	}

	cout << ans;

	return 0;
}