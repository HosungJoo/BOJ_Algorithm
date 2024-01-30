#include <iostream>
#include<vector>

using namespace std;

int map[5][5];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector<int> ans;


void recur(int level, int x, int y, int sum) {
	
	if (level == 5) {
		bool flag = 1;
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == sum) {
				flag = 0;
				break;
			}
		}
		if (flag)
			ans.push_back(sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 5 || ny >= 5 || nx < 0 || ny < 0)
			continue;
		recur(level + 1, nx, ny, sum * 10 + map[nx][ny]);
	}

}


int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			recur(0, i, j,map[i][j]);
		}
	}

	cout << ans.size();

	return 0;
}