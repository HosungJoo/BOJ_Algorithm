#include<iostream>

using namespace std;

int N, S;
int nums[20];
int ans;

//한 칸씩 index를 밀어서 했던 조합 안하게 하기
void dfs(int lv,int cnt,int idx,int sum) {
	if (lv == cnt) {
		if (sum == S) ans++;
		return;
	}
	for (int i = idx; i < N; i++) {
		dfs(lv + 1, cnt, i + 1, sum + nums[i]);
	}
}

int main()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	
	//조합 갯수 i
	for (int i = 1; i <= N; i++) {
		dfs(0, i, 0, 0);
	}

	cout << ans;

	return 0;
}