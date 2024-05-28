#include <iostream>

using namespace std;

int N;
int nbb[1001];

int main() {

	cin >> N;

	for (int i = 123; i <= 987; i++) nbb[i] = 1;

	for (int i = 0; i < N; i++) {

		int tar, strk, b;
		cin >> tar >> strk >> b;

		int digit_1 = tar % 10;
		int digit_2 = (tar % 100 - digit_1) / 10;
		int digit_3 = tar / 100;

		for (int j = 123; j <= 987; j++) {

			if (nbb[j] == 0) continue;

			int tm_1 = j % 10;
			int tm_2 = (j % 100 - tm_1) / 10;
			int tm_3 = j / 100;
			int tm_st = 0;
			int tm_b = 0;

			if (tm_1 == 0 || tm_2 == 0) {
				nbb[j] = 0;
				continue;
			}
			if (tm_1 == tm_3 || tm_1 == tm_2 || tm_2 == tm_3) {
				nbb[j] = 0;
				continue;
			}

			if (tm_1 == digit_1) tm_st++;
			if (digit_1 == tm_2 || digit_1 == tm_3) tm_b++;

			if (tm_2 == digit_2) tm_st++;
			if (digit_2 == tm_1 || digit_2 == tm_3) tm_b++;
			
			if (tm_3 == digit_3) tm_st++;
			if (digit_3 == tm_1 || digit_3 == tm_2) tm_b++;
			

			if (tm_st != strk || tm_b != b) nbb[j] = 0;
		}
	}

	int ans = 0;

	for (int i = 123; i <= 987; i++) {
		if (nbb[i] == 1) ans++;
	}

	cout << ans;


	return 0;
}