#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int T;
string num;
int change;
int siZe;
int ans;

void init() {
	ans = 0;
}

void input() {
	cin >> num;
	siZe = num.length();
	cin >> change;
}

int chageint(int digit) {
	int tmp = 0;
	for (int i = 0; i < siZe; i++) {
		int ten = 1;
		for (int j = 1; j < digit; j++) {
			ten *= 10;
		}
		tmp += ((num[i] - '0') * ten);
		digit--;
	}
	return tmp;
}

void dfs(int node, int swapcnt) {
	if (swapcnt == change) {
		int tmp = 0;
		tmp = chageint(siZe);
		ans = max(ans, tmp);
		return;
	}
	for (int i = node; i < siZe; i++) {
		for (int j = i + 1; j < siZe; j++) {
			if (num[i] <= num[j]) {
				swap(num[i], num[j]);
				dfs(i,swapcnt + 1);
				swap(num[i], num[j]);
			}
			if (i == siZe - 2 && j == siZe-1) {
				swap(num[i], num[j]);
				dfs(i,swapcnt + 1);
				swap(num[i], num[j]);
			}
		}
	}
}

void solve() {
	dfs(0, 0);
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