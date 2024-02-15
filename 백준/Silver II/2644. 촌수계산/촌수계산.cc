#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct calchon {
	int ch;
	int cnt;
};

int n;
int p1, p2;
int m;
int ans;
vector<int>chon[101];
bool visited[101];

void bfs(int node) {
	queue<calchon>q;
	q.push({ node,0 });
	visited[node] = 1;

	while (!q.empty()) {
		calchon now = q.front();
		q.pop();
		if (now.ch == p2) {
			ans = now.cnt;
			return;
		}

		for (int i = 0; i < chon[now.ch].size(); i++) {
			int next = chon[now.ch][i];
			if (visited[next]) continue;
			visited[next] = 1;
			q.push({ next,now.cnt + 1 });
		}
	}
}

int main() {

	cin >> n;

	cin >> p1 >> p2;

	cin >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;

		chon[from].push_back(to);
		chon[to].push_back(from);
	}

	bfs(p1);

	if (ans == 0) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}