#include<iostream>


using namespace std;

struct info {
	int x;
	int y;
	int dir; //0:북 1:동 2:남 3:서 시계방향
};

int N, M;
int map[51][51];
int visited[51][51];
info start;
int dx[][4] = {
	{0,1,0,-1},
	{-1,0,1,0},
	{0,-1,0,1},
	{1,0,-1,0}
};
int dy[][4] = { 
	{-1,0,1,0},
	{0,-1,0,1},
	{1,0,-1,0},
	{0,1,0,-1}
};

int robot_clean(int x,int y,int dir) {
	info now = { x,y,dir };
	int clean_area = 0;
	while (1) {
		//1번 현재 칸이 청소 돼있지 않으면 청소
		if (map[now.x][now.y] == 0 && visited[now.x][now.y] == 0) {
			visited[now.x][now.y] = 1;
			clean_area++;
		}
		
		//2,3번 현재 칸 둘러보기
		bool is_three = false;
		for (int i = 0; i < 4; i++) { //보는 방향 기준 반시계로 둘러보기
			int nx = now.x + dx[now.dir][i];
			int ny = now.y + dy[now.dir][i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue; //밖으로 나가면 안됨
			if (map[nx][ny] == 1) continue; //벽이면 안감
			if (visited[nx][ny] == 1) continue; //청소했으면 안감

			now = { nx,ny,(4 + now.dir - (i + 1)) % 4 };
			is_three = true;
			break;
		}
		if (is_three) continue;

		//2번 전부 청소 돼있음
		//후진 여부 판단
		int nx = now.x + dx[now.dir][1];
		int ny = now.y + dy[now.dir][1];

		if (map[nx][ny] == 1) break; //벽이라 후진 못함 작동 중지
		else {
			now = { nx,ny,now.dir };
		}
	}
	return clean_area;
}

int main()
{
	int r, c, d;

	cin >> N >> M;
	cin >> r >> c >> d;
	start = { r,c,d };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	
	cout << robot_clean(r, c, d);

	return 0;
}