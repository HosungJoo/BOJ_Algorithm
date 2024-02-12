#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int N, M;
bool dat[9];
vector<int> num;

void recur(int node) {
	if (node == M+1) {
		for (int i = 0; i < num.size(); i++) cout << num[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (dat[i]) continue;
		dat[i] = 1;
		num.push_back(i);
		recur(node + 1);
		dat[i] = 0;
		num.pop_back();
	}
}

int main() {

	cin >> N >> M;
	
	recur(1);

	return 0;
}