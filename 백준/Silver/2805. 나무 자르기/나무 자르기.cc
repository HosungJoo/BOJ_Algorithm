#include<iostream>
#include<algorithm>

using namespace std;

int N, M; // N:나무 수, M: 필요 나무 높이
int woods[1000000]; //나무 arr
int ans;

void bs(int start, int end) {

	while (start <= end) {
		int mid = (start + end) / 2;
		long long sum = 0;

		//나무 패기
		for (int i = 0; i < N; i++) {
			int rest = woods[i] - mid;
			if (rest > 0) {
				sum += rest;
			}
		}

		//필요한 나무량과 절단한 나무량 비교
		if (sum >= M) {
			start = mid + 1;
			ans = max(ans, mid);
		}
		else {
			end = mid - 1;
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> woods[i];
	}
	
	//bs로 찾기 위한 sort
	sort(woods, woods + N);

	bs(0, woods[N - 1]);

	cout << ans;

	return 0;
}