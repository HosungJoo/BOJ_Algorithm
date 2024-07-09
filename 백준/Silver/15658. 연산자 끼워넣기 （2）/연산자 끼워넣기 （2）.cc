#include <iostream>
#include <algorithm>

using namespace std;

int N;
int operators[4]; //+ - * /
int num[11];
int max_ans = -20e8;
int min_ans = 21e8;

void dfs(int lv, int sum) {
	if (lv == N) {
		max_ans = max(max_ans, sum);
		min_ans = min(min_ans, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (operators[i] == 0) continue;

		operators[i]--;

		if (i == 0) dfs(lv + 1, sum + num[lv]);
		else if (i == 1) dfs(lv + 1, sum - num[lv]);
		else if (i == 2) dfs(lv + 1, sum * num[lv]);
		else if (i == 3) dfs(lv + 1, sum / num[lv]);

		operators[i]++;
	}
}

int main() {

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	dfs(1, num[0]);

	cout << max_ans << "\n" << min_ans;

	return 0;
}