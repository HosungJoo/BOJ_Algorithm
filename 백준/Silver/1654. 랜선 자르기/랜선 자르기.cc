#include<iostream>
#include<algorithm>

using namespace std;

int K, N;//K:초기 랜선 개수, N:필요한 랜선 개수
int lan[10001]; //LAN arr
long long ans;
int maximum;

void bs() {
	long long start = 1;
	long long end = maximum;

	while (start <= end) {
		long long mid = (start + end) / 2;
		int cnt = 0;

		//랜선 갯수 합
		for (int i = 0; i < K; ++i) {
			if (lan[i] / mid > 0) {
				cnt += (lan[i] / mid);
			}
		}

		//개수 비교
		if (cnt >= N) {
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
	cin >> K >> N;

	for (int i = 0; i < K; ++i) {
		cin >> lan[i];
		maximum = max(maximum, lan[i]);
	}
	
	bs();

	cout << ans;

	return 0;
}