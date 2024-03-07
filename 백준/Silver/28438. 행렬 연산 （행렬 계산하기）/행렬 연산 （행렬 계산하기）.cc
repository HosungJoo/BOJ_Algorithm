#include <iostream>
#include <vector>

using namespace std;

vector<int>row;
vector<int>col;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, Q;
	cin >> N >> M >> Q;

	row = vector<int>(N, 0);
	col = vector<int>(M, 0);

	for (int i = 0; i < Q; i++) {
		int sel; //1이면 r번째 행 v를 더함, 2이면 r번째 열 v를 더함
		int r, v;
		cin >> sel >> r >> v;
		if (sel == 1) {
			row[r - 1] += v;
		}
		else {
			col[r - 1] += v;
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << row[i] + col[j] << " ";
		}
		cout << "\n";
	}

	return 0;
}