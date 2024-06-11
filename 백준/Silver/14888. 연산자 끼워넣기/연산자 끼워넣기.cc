#include <iostream>
#include <algorithm>
using namespace std;

int N;

int operators[4];//더하기 빼기 곱하기 나누기
int ports[11];
int max_ans = -21e8;
int min_ans = 21e8;

void dfs(int lv, int sum) {
	if (lv == N) {
		//최소 최대 갱신
		max_ans = max(sum, max_ans);
		min_ans = min(sum, min_ans);
		return;
	}
	for (int i = 0; i < 4; i++) {
		//연산자가 없으면 못씀
		if (operators[i] == 0) continue;

		//사용한 연산자 체크
		operators[i] -= 1;

		//연산자에 따른 계산
		if (i == 0) dfs(lv + 1, sum + ports[lv]);
		else if(i==1) dfs(lv + 1, sum - ports[lv]);
		else if (i == 2) dfs(lv + 1, sum * ports[lv]);
		else dfs(lv + 1, sum / ports[lv]);

		//사용한 연산자 복구
		operators[i] += 1;
	}
}

int main() {

	cin >> N;

	//항 입력
	for (int i = 0; i < N; i++) {
		cin >> ports[i];
	}

	//연산자 갯수 입력
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	dfs(1, ports[0]);

	cout << max_ans << "\n" << min_ans;

	return 0;
}