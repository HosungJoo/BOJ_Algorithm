#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct domi {
	int l_col;
	int l_row;
	int r_col;
	int r_row;
};

struct info {
	int x;
	int y;
};

int map[110][110];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int row, col;
int sq_cnt;
vector<int>area;
vector<domi>sq;

void bfs(int x, int y) {
	queue<info>q;
	q.push({ x,y });

	int tmpArea = 0;
	map[x][y] = 1;

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		tmpArea++;

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
			if (map[nx][ny] == 1) continue;

			map[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	area.push_back(tmpArea);
}

int main() {
	
	cin >> row >> col >> sq_cnt;

	for (int i = 0; i < sq_cnt; i++) {
		int lc, lr, rc, rr;
		cin >> lc >> lr >> rc >> rr;
		sq.push_back({ lc,row-lr,rc,row-rr });
	}

	//색칠하기
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			for (int s = 0; s < sq.size(); s++) {
				//색칠할수있는지 체크하고 색칠하면 멈춤
				if (i < sq[s].l_row && i >= sq[s].r_row) {
					if (j >= sq[s].l_col && j < sq[s].r_col) {
						map[i][j] = 1;
						break;
					}
				}
			}

		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 0) {
				bfs(i, j);
			}
		}
	}

	sort(area.begin(), area.end());

	cout << area.size() << "\n";
	for (int i = 0; i < area.size(); i++) {
		cout << area[i] << " ";
	}

	return 0;
}