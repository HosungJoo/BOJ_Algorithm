#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

struct location {
	int x;
	int y;
};

int T;
int N;
int visited[101][101];
int ans;
bool cusvisited[10];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
vector<location>customer;
location home;
location comp;

void init() {
	customer.clear();
	memset(visited, 0, sizeof(visited));
	ans = 2134567890;
}

void input() {
	cin >> N;
	cin >> comp.x >> comp.y;
	cin >> home.x >> home.y;
	for (int i = 0; i < N; i++) {
		int x;
		int y;
		cin >> x >> y;
		customer.push_back({ x,y });
	}
}

int caldist(location start, location dest) {
	int distx = start.x > dest.x ? (start.x - dest.x) : (dest.x - start.x);
	int disty = start.y > dest.y ? (start.y - dest.y) : (dest.y - start.y);
	return distx + disty;
}

void dfs(location start, int node, int arrive, int dist) {
	if (arrive == N) {
		int lasttmp = caldist(customer[node], home);
		lasttmp += dist;
		if (lasttmp < ans) ans = lasttmp;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (cusvisited[i]) continue;
		cusvisited[i] = 1;
		int tmpdist = caldist(start, customer[i]);
		dfs(customer[i], i, arrive + 1, dist + tmpdist);
		cusvisited[i] = 0;
	}
}

void solve() {
		dfs(comp, 0, 0, 0);
}

int main() {

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}