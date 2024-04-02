#include<iostream>
#include<cstring>

using namespace std;

int D, W, K;
bool film[20][20];
bool cpfilm[20][20];
int ans = 21e8;
int injection;


void init() {
	memset(film, 0, sizeof(film));
	memset(cpfilm, 0, sizeof(film));
	ans = 21e8;
	injection = 0;
}

void input() {
	cin >> D >> W >> K;

	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			cin >> film[i][j];
			cpfilm[i][j] = film[i][j];
		}
	}
}

bool chk() {
	for (int i = 0; i < W; i++) {

		bool base = cpfilm[0][i];
		int cnt = 0;
		bool pass = 0;
		for (int j = 0; j < D; j++) {
			if (base == cpfilm[j][i]) {
				cnt++;
				if (cnt == K) {
					pass = 1;
					break;
				}
			}
			else {
				base = cpfilm[j][i];
				cnt = 1;
			}
		}
		if (!pass) {
			return 0;
		}
	}
	return 1;
}

void dfs(int lv) {
	if (lv == D) {
		if (chk()) {
			ans = min(ans, injection);
		}
		return;
	}

	if (injection > ans) {
		return;
	}

	//주입 안함
	dfs(lv + 1);

	//A주입
	for (int i = 0; i < W; i++) {
		cpfilm[lv][i] = 0;
	}
	injection++;
	dfs(lv + 1);
	injection--;
	for (int i = 0; i < W; i++) {
		cpfilm[lv][i] = film[lv][i];
	}

	//B주입
	for (int i = 0; i < W; i++) {
		cpfilm[lv][i] = 1;
	}
	injection++;
	dfs(lv + 1);
	injection--;
	for (int i = 0; i < W; i++) {
		cpfilm[lv][i] = film[lv][i];
	}
}

void solve() {
	
	if (chk()) {
		ans = 0;
		return;
	}
	else {
		dfs(0);
	}

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