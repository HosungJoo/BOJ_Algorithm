#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int T;
int  V, E;
int node1, node2;
int anstop;
int cnt;
int parent[10001];
vector<int>tree[10001];
int visited[10001];
bool ansvisited[10001];

void init() {
	memset(visited, 0, sizeof(visited));
	memset(ansvisited, 0, sizeof(ansvisited));
	memset(parent, 0, sizeof(parent));
	for (int i = 0; i < 10001; i++) tree[i].clear();
	anstop = 0;
	cnt = 0;
}

void input() {
	cin >> V >> E >> node1 >> node2;
	for (int i = 0; i < E; i++) {
		int from, to;
		cin >> from >> to;
		parent[to] = from;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}
}


void dfs(int node) {
	cnt++;
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (parent[anstop] == next) continue;
		if (ansvisited[next]) continue;
		ansvisited[next] = 1;
		dfs(next);
	}
}

void parentfind1(int node) {
	if (node == 1) {
		visited[node] = 1;
		return;
	}
	visited[node] = 1;
	parentfind1(parent[node]);
}

void parentfind2(int node) {
	if (visited[node]) {
		anstop = node;
		return;
	}
	visited[node] = 1;
	parentfind2(parent[node]);
	return;
}

void solve() {
	parentfind1(node1);
	parentfind2(node2);

	ansvisited[anstop]=1;
	dfs(anstop);
}

int main() {

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();

		cout << "#" << tc << " " << anstop << " " << cnt << "\n";
	}

	return 0;
}