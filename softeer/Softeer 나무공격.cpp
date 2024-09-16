#include<iostream>


using namespace std;

int n, m;
int map[101][101];
int destroyer;

int main(int argc, char** argv)
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> map[i][j];
			if (map[i][j]) {
				++destroyer;//파괴범 count
			}
		}
	}

	int rmDestroyer = 0;

	for (int i = 0; i < 2; ++i) {
		int st, ed; //공격 범위 start & end
		cin >> st >> ed;

		for (int i = st; i <= ed; ++i) {
			for (int j = 0; j <= m; ++j) {
				if (map[i][j]) { //파괴범을 만나면
					map[i][j] = 0; //제거
					++rmDestroyer; //제거한 수 counting
					break;
				}
			}
		}
	}

	cout << destroyer - rmDestroyer;



	return 0;
}