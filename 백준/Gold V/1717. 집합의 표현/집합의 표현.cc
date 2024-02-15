#include<iostream>

using namespace std;

int parent[1000001];
int Size[1000001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	int px = find(x);
	 int py = find(y);

	if (px == py) return;
	parent[px] =py;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		bool cal;
		cin >> cal;

		if (!cal) {
			int a;
			int b;
			cin >> a >> b;
			Union(a, b);
		}
		else {
			int a;
			int b;
			cin >> a >> b;
			if (find(a) == find(b)) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}


	return 0;
}