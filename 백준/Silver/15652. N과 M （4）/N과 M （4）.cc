#include <iostream>

using namespace std;

int N, M;
int num[10];

void dfs(int lv, int idx) {
	if (lv == M) {
		for (int i = 0; i < M; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i <= N; i++) {
		if (lv != 0 && (num[lv - 1] > i)) continue;
		num[lv] = i;
		dfs(lv + 1, idx);
	}
}

int main() {

	cin >> N >> M;
	dfs(0, 1);
	
	return 0;
}