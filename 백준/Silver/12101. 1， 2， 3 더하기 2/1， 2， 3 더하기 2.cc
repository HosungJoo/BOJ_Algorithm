#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int n, k;
int cnt;
vector<int>num;

void recur(int sum) {
	if (sum == n) {
		cnt++;
		if (cnt == k) {
			for (int i = 0; i < num.size(); i++) {
				if (i != num.size() - 1) cout << num[i] << "+";
				else cout << num[i];
			}
		}
		return;
	}
	for (int i = 1; i <= 3; i++) {
		sum += i;
		if (sum > n) {
			sum -= i;
			return;
		}
		num.push_back(i);
		recur(sum);
		sum -= i;
		num.pop_back();
	}
}

int main() {

	cin >> n >> k;

	recur(0);
	if (cnt < k)
		cout << -1;

	return 0;
}