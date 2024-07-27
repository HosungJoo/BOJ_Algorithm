#include<iostream>

using namespace std;

int N, S;
int nums[20];
int ans;

//처음 시도 44ms
//한 칸씩 index를 밀어서 했던 조합 안하게 하기
//void dfs(int lv,int cnt,int idx,int sum) {
//	if (lv == cnt) {
//		if (sum == S) ans++;
//		return;
//	}
//	for (int i = idx; i < N; i++) {
//		dfs(lv + 1, cnt, i + 1, sum + nums[i]);
//	}
//}

//보고 배운 거 이게 더 좋은듯 4ms cnt는 원소 쓴 갯수 세기용
void dfs(int lv,int sum,int cnt) {
	if (lv == N) {
		if (S == sum && cnt > 0) ans++;
		return;
	}
	dfs(lv + 1, sum + nums[lv],cnt+1); //원소 넣기
	dfs(lv + 1, sum, cnt); //원소 빼기
}

int main()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	
	dfs(0, 0, 0);

	cout << ans;

	return 0;
}