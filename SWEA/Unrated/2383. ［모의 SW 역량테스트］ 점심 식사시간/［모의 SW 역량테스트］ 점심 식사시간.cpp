#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

struct info {
	int x;
	int y;
};

int N;
int map[10][10];
vector<info>people;
vector<info>stairs;
vector<int>st[2];
int ans = 21e8;

void init() {
	memset(map, 0, sizeof(map));
	for (int i = 0; i < 2; i++) st[i].clear();
	people.clear();
	stairs.clear();
	ans = 21e8;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {//사람 위치 받기
				people.push_back({ i,j });
			}
			else if (map[i][j] > 1) {//계단 위치 받기
				stairs.push_back({ i,j });
			}
		}
	}
}

int chkstair(int nm) {
	priority_queue<int, vector<int>, greater<>>pq;
	queue<int>q;
	for (int i = 0; i < st[nm].size(); i++) {
		pq.push(st[nm][i]);
	}

	int tm = 0;
	int dltm = map[stairs[nm].x][stairs[nm].y];

	if (!pq.empty()) tm = pq.top();
	else return tm;

	while (!pq.empty()) {

		if (tm >= ans) return tm;
		//계단 확인 및 사람빼기
		while (!q.empty()) {
			if (q.front() == tm) {
				q.pop();
			}
			else break;
		}
		//사람넣기
		if (q.size() < 3) {
			if (tm > pq.top()) {
				q.push(tm + dltm);
			}
			else {
				q.push(pq.top() + dltm + 1);
			}
			pq.pop();
		}
		else {
			tm = q.front();
		}
	}
	while (!q.empty()) {
		if (tm >= ans) return tm;
		tm = q.front();
		q.pop();
	}
	return tm;
}

void bcktr(int lv) {
	if (lv == people.size()) {

		int s1tm = chkstair(0);
		if (s1tm >= ans) return;
		int s2tm = chkstair(1);
		if (s2tm >= ans) return;
		ans = min(ans, max(s1tm, s2tm));
		return;
	}

	int px = people[lv].x;
	int py = people[lv].y;

	//1번계단에 들어감
	int stx = stairs[0].x;
	int sty = stairs[0].y;

	st[0].push_back(abs(px - stx) + abs(py - sty));
	bcktr(lv + 1);
	st[0].pop_back();

	//2번계단에 들어감
	stx = stairs[1].x;
	sty = stairs[1].y;

	st[1].push_back(abs(px - stx) + abs(py - sty));
	bcktr(lv + 1);
	st[1].pop_back();
}

void solve() {
	bcktr(0);
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();

		solve();

		cout << "#" << tc << " " << ans << "\n";
	}


	return 0;
}