#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct info {
	int num;
	int dist;
};

vector<int>friends[501];

int N, M;
int ans;

void bfs() {
	int visited[501] = { 0, };
	queue<info>q;
	q.push({ 1,0 });
	visited[1] = 1;

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		if (now.dist >= 2) continue;

		for (int i = 0; i < friends[now.num].size(); i++) {
			if (visited[friends[now.num][i]] == 1) continue;
			visited[friends[now.num][i]] = 1;
			q.push({ friends[now.num][i], now.dist + 1 });
			ans++;
		}
	}
}

int main() {
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;

		friends[from].push_back(to);
		friends[to].push_back(from);
	}

	bfs();

	cout << ans;

	return 0;
}