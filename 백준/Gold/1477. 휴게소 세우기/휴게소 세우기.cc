#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N; //현재 휴게소
int M; //추가 휴게소
int L; //고속도로 길이
vector<int>spot; //휴게소 지점
vector<int>dist;
int ans = 9999;

void bs() {
	int start = 1;
	int end = L - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 0;
		for (int i = 0; i < dist.size(); ++i) {
			cnt += (dist[i] / mid);
			if (dist[i] % mid == 0) {
				cnt--;
			}
		}

		if (cnt > M) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
			ans = min(ans, mid);
		}
	}
}

int main()
{
	cin >> N >> M >> L;

	spot.push_back(0);
	for (int i = 0; i < N; ++i) {
		int posi;
		cin >> posi;
		spot.push_back(posi);
	}
	spot.push_back(L);

	sort(spot.begin(), spot.end());

	for (int i = 0; i < spot.size() - 1; ++i) {
		dist.push_back(spot[i + 1] - spot[i]);
	}

	bs();

	cout << ans;

	return 0;
}