#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int nums[8];
vector<int>vec;

void dfs(int lv,int idx) {
	if (lv == M) {
		for (int i = 0; i < M; i++) {
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < N; i++) {
		vec.push_back(nums[i]);
		dfs(lv + 1, i+1);
		vec.pop_back();
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	sort(nums, nums + N);

	dfs(0, 0);

	return 0;
}