#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct info {
	int x;
	int y;
	int val;
};


int R, C, T;
int map[60][60];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<info>dusts;
vector<int>M1;

int main()
{
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) dusts.push_back({ i,j,map[i][j] }); //미세먼지 버퍼 관리
			if (map[i][j] == -1) M1.push_back(i); //공기청정기 위치 넣기
		}
	}

	int ans = 0;

	for (int tm = 0; tm < T; tm++) { //T초 동안 진행
		ans = 0;
		int copyMap[60][60] = { 0, };

		//1.미세먼지 확산
		for (int i = 0; i < dusts.size(); i++) {
			info now = dusts[i];

			if (now.val < 5) {
				copyMap[now.x][now.y] += now.val;
				continue;
			}

			//확산하기
			for (int dir = 0; dir < 4; dir++) {
				int nx = now.x + dx[dir];
				int ny = now.y + dy[dir];

				if (nx<0 || ny<0 || nx>=R || ny>=C) continue;  // Out of Bound
				if (map[nx][ny] == -1) continue; //공기청정기가 있으면 확산X

				//확산돼서 값 감소 및 카피맵 저장
				copyMap[nx][ny] += (now.val / 5);
				dusts[i].val -= (now.val / 5);
			}

			//확산 후 먼지 값 저장
			copyMap[now.x][now.y] += dusts[i].val;
		}

		//2.공기청정기 작동
		for (int i = 0; i < M1.size(); i++) {
			int x = M1[i];

			if (i == 0) { //위쪽 공기 청정기

				
				//위에서 아래로 내려가는 바람
				for (int r = x - 2; r >= 0; r--)  copyMap[r + 1][0] = copyMap[r][0];

				//우에서 좌로 부는 바람
				for (int c = 1; c < C; c++) copyMap[0][c - 1] = copyMap[0][c];
				

				//아래에서 위로 부는 바람
				for (int r = 1; r <= x; r++) copyMap[r - 1][C - 1] = copyMap[r][C - 1];
				

				//좌에서 우로 부는 바람
				for (int c = C - 2; c >= 0; c--) {
					copyMap[x][c + 1] = copyMap[x][c];
				}

			}
			else { //아래쪽 공기 청정기

				//아래에서 위로 부는 바람
				for (int r = x + 2; r < R; r++) copyMap[r - 1][0] = copyMap[r][0];

				//우에서 좌로 부는 바람
				for (int c = 1; c < C; c++) copyMap[R - 1][c - 1] = copyMap[R - 1][c];

				//위에서 아래로 부는 바람
				for (int r = R - 1; r >= x; r--) {
					copyMap[r + 1][C - 1] = copyMap[r][C - 1];
				}

				//좌에서 우로 부는 바람
				for (int c = C - 2; c >= 0; c--) copyMap[x][c + 1] = copyMap[x][c];
			}
		}

		//먼지 버퍼 지우기
		dusts.clear();
		//맵 저장
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] != -1) {
					map[i][j] = copyMap[i][j];
					if (map[i][j] != 0) dusts.push_back({ i,j,map[i][j] });
					ans += map[i][j];
				}
			}
		}

		int de = 1;

	}

	cout << ans;

	return 0;
}