#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int N, S;
int per[20];
int ans = 21e8;

void init() {
	memset(per, 0, sizeof(per));
	ans = 21e8;
}

void input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> per[i];
	}
	//sort(per, per + N);
}

void bcktr(int lv, int sum) {
	if (sum >= S) {
		ans = min(ans, sum);
		return;
	}
	if (lv == N) return;
	for (int i = lv; i < N; i++) {
		bcktr(i + 1, sum + per[i]);
	}
}

void solve() {
	bcktr(0, 0);
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();

		cout << "#" << tc << " " << ans-S << "\n";
	}


	return 0;
}