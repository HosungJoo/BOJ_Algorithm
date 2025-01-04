#include <iostream>

using namespace std;


int main() {

	int N, K;
	int ans = 0;

	cin >> N >> K;

	while (1) {
		int cnt = 0;
		int tmp = N;

		while (tmp) { //물병 개수를 이진수로 표현하면 최종적인 물병 개수가 나옴 => 규칙 참고
			if (tmp & 1) { //물병 개수 세기
				cnt++;
			}
			tmp >>= 1;
		}

		if (cnt <= K) break; //K개를 넘기면 물병 추가
		ans++;
		N++;
	}

	cout << ans;

	return 0;
}