#include <iostream>

using namespace std;

int N, M;
int parent[201];
int travel[1000];

int find(int tar) {
	if (tar == parent[tar]) return tar;
	return parent[tar] = find(parent[tar]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	parent[t2] = t1;
}


int main() {

	cin >> N >> M;

	for (int i = 1; i <= 200; i++) parent[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int connect;
			cin >> connect;
			if (connect) {
				setUnion(i, j);
			}
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> travel[i];
	}

	bool is_pos = true;

	for (int i = 1; i < M; i++) {
		if (find(travel[i - 1]) != find(travel[i])) {
			is_pos = false;
			break;
		}
	}

	if (!is_pos) cout << "NO";
	else cout << "YES";

	return 0;
}