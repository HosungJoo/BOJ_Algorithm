#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int>num;
int ans[7];

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		ans[cnt] = num[i];
		dfs(cnt + 1);
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