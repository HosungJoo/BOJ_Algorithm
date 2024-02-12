#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int N;
int chess[15];
int cnt;

bool chkqueen(int node, int idx) {
	for (int i = 0; i < node; i++) {
		int dx = node - i;
		int dy = chess[node] > chess[i] ? (chess[node] - chess[i]) : (chess[i] - chess[node]);
		if (chess[i] == chess[node]) return 1;
		if (dx == dy) return 1;
	}
	return 0;
}

void queen(int node) {
	if (node == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		
		chess[node] = i;
		bool check = chkqueen(node, i);
		if (check) continue;
		queen(node + 1);
	}
}

int main() {

	cin >> N;

	queen(0);

	cout << cnt;

	return 0;
}