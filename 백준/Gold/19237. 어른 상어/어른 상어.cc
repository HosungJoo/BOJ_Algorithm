#include <iostream>
#include <vector>
using namespace std;

struct shark {
	int x;
	int y;
	int dir;
	int alive;
};

struct info {
	int num;
	int tm;
};

int N, M, k; //N:맵 크기, M:상어 수, k:향수 지속 시간
info map[20][20];
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
shark sharks[401]; // 상어 버퍼
int shark_dir[401][5][4]; //상어 방향 우선순위
int ans = -1;

int moveShark(shark now,int num,int re) {
	for (int j = 0; j < 4; j++) {
		int dir = shark_dir[num][now.dir][j];
		int nx = now.x + dx[dir];
		int ny = now.y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (re == 0) {
			if (map[nx][ny].num > 0) continue; //초기 탐색
		}
		else {
			if (map[nx][ny].num != num) continue; //채취있는 곳으로 재탐색
		}

		sharks[num] = { nx,ny,dir,1 };
		return 1;
	}
	return 0;
}

int main() {

	int tot_shark = 0;

	cin >> N >> M >> k;

	tot_shark = M;

	//맵 정보
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int shark_num;
			cin >> shark_num;
			if (shark_num > 0) {
				sharks[shark_num] = { i,j,0,1 };
				map[i][j] = { shark_num,k };
				shark_num++;
			}
		}
	}

	//초기 상어 방향
	for (int i = 1; i <= M; i++) {
		int dir;
		cin >> dir;
		sharks[i].dir = dir;
	}

	//상어별 방향 우선순위 순서
	for (int i = 1; i <= M; i++) { //i번째 상어의
		for (int j = 1; j <= 4; j++) { //상 하 좌 우의
			for (int d = 0; d < 4; d++) { //우선순위 방향
				int dir;
				cin >> dir;
				shark_dir[i][j][d] = dir;
			}
		}
	}

	
	for (int tm = 1; tm <= 1000; tm++) {
		//이동
		for (int i = 1; i <= M; i++) {
			if (sharks[i].alive == 0) continue;
			shark now = sharks[i];
			int is_move = 0;

			//인접한 칸 중 냄새가 없는 칸을 먼저 탐색
			is_move = moveShark(now, i, 0);

			if (is_move != 1) { //자신의 채취에서 가기
				moveShark(now, i, 1);
			}
		}

		//채취 시간 감소
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].tm != 0) { //시간 감소
					map[i][j].tm--;
					if (map[i][j].tm == 0) { // 채취 제거
						map[i][j].num = 0;
					}
				}
			}
		}

		//상어 채취 남기기
		for (int i = 1; i <= M; i++) {
			if (sharks[i].alive == 0) continue; //죽었으면 다음으로
			shark now = sharks[i];
			//이동한 칸 상황 보기
			if (map[now.x][now.y].num == 0 || map[now.x][now.y].num == i) { //아무도 없거나 내 채취가 있음
				map[now.x][now.y] = { i,k };
			}
			else { //죽음
				sharks[i].alive = 0;
				tot_shark--;
			}
		}

		//종료 조건
		if (tot_shark == 1) {
			ans = tm;
			break;
		}
	}

	cout << ans;

	return 0;
}