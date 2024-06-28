#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int nanro[100];
int num[100];
vector<int>prime;
int ans;

int main(int argc, char** argv)
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> nanro[i];
	}

	//소수 구하기
	for (int i = 2; i <= 100; i++) {
		num[i] = i;
	}

	for (int i = 2; i <= 10; i++) {
		if (num[i] == 0) continue;
		for (int j = 2 * i; j <= 100; j += i) {
			num[j] = 0;
		}
	}

	for (int i = 2; i <= 100; i++) {
		if (num[i] != 0) prime.push_back(num[i]);
	}

	for (int i = 0; i < prime.size(); i++) {
		int base = prime[i];
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (nanro[j] % base == 0) cnt++;
		}
		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}