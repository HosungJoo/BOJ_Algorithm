#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int num[10];
int visited[10];
vector<int>ans;

void dfs(int lv) {
	if (lv == M) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) continue;

		ans.push_back(num[i]);
		visited[i] = 1;
		dfs(lv + 1);
		ans.pop_back();
		visited[i] = 0;
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	
	sort(num, num + N);

	dfs(0);
	
	return 0;
}