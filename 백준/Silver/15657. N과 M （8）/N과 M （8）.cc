#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int M;
int cnt;
int ans[8];
vector<int>num;

void dfs(int lv) {
	if (lv == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (lv > 0 && num[i] < ans[lv - 1]) continue;
		ans[lv] = num[i];
		dfs(lv + 1);
	}
}

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		num.push_back(n);
	}

	sort(num.begin(), num.end());

	dfs(0);

	return 0;
}