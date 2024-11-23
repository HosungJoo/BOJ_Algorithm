#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct info {
	int x;
	int y;
	int speed;
	int dir;
	int size;
	bool operator<(info right) const {
		if (x < right.x) return true;
		else if (x == right.x) {
			if (y < right.y) return true;
			else if (y == right.y) {
				if (size > right.size) return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}
};

int R, C; //행열
int M; //상어 수
int dx[] = { 0,-1,1,0,0 }; //상: 1 하: 2
int dy[] = { 0,0,0,1,-1 }; //우: 3 좌: 4
int ans;
vector<info>shark; //상어를 담는 버퍼

void moveShark(int idx) {
	info now = shark[idx]; //현재 상어
	int rest_dist = 0;

	if (now.dir == 1) { //상
		rest_dist = now.x - 1;
		if (rest_dist >= now.speed) { //남은 거리가 스피드보다 크거나 같을 때
			now.x = now.x + now.speed*dx[now.dir];
		}
		else {
			now.x = now.x + rest_dist * dx[now.dir]; //일단 끝으로 감
			now.speed = now.speed - rest_dist; //남은 거리 만큼 소요
			int one_way = now.speed / (R - 1); //편도 가능 여부 및 횟수
			int last_dist = now.speed % (R - 1); // 최종 남은 거리

			if (one_way > 0) { //남은 추진력이 있다면
				if (one_way % 2 == 0) {//현재와 동일 위치
					if (last_dist != 0) {
						now.dir = 2; //방향 전환
					}
				}
				else {//현재와 정반대 위치
					now.x = R;
				}
			}
			else { //없다면
				now.dir = 2; //방향 전환
			}
			now.x += last_dist * dx[now.dir];//남은 거리만큼 이동
		}
	}
	else if (now.dir == 2) { //하
		rest_dist = R - now.x;
		if (rest_dist >= now.speed) { //남은 거리가 스피드보다 크거나 같을 때
			now.x = now.x + now.speed*dx[now.dir];
		}
		else {
			now.x = now.x + rest_dist * dx[now.dir]; //일단 끝으로 감
			now.speed = now.speed - rest_dist; //남은 거리 만큼 소요
			int one_way = now.speed / (R - 1); //편도 가능 여부 및 횟수
			int last_dist = now.speed % (R - 1); // 최종 남은 거리

			if (one_way > 0) { //남은 추진력이 있다면
				if (one_way % 2 == 0) {//현재와 동일 위치
					if (last_dist != 0) {
						now.dir = 1; //방향 전환
					}
				}
				else {//현재와 정반대 위치
					now.x = 1;
				}
			}
			else { //없다면
				now.dir = 1; //방향 전환
			}
			now.x += last_dist * dx[now.dir];//남은 거리만큼 이동
		}
	}
	else if (now.dir == 3) { //우
		rest_dist = C-now.y;
		if (rest_dist >= now.speed) { //남은 거리가 스피드보다 크거나 같을 때
			now.y = now.y + now.speed*dy[now.dir];
		}
		else {
			now.y = now.y + rest_dist * dy[now.dir]; //일단 끝으로 감
			now.speed = now.speed - rest_dist; //남은 거리 만큼 소요
			int one_way = now.speed / (C - 1); //편도 가능 여부 및 횟수
			int last_dist = now.speed % (C - 1); // 최종 남은 거리

			if (one_way > 0) { //남은 추진력이 있다면
				if (one_way % 2 == 0) {//현재와 동일 위치
					if (last_dist != 0) {
						now.dir = 4; //방향 전환
					}
				}
				else {//현재와 정반대 위치
					now.y = 1;
				}
			}
			else { //없다면
				now.dir = 4; //방향 전환
			}
			now.y += last_dist * dy[now.dir];//남은 거리만큼 이동
		}
	}
	else { //좌
		rest_dist = now.y - 1;
		if (rest_dist >= now.speed) { //남은 거리가 스피드보다 크거나 같을 때
			now.y = now.y + now.speed*dy[now.dir];
		}
		else {
			now.y = now.y + rest_dist * dy[now.dir]; //일단 끝으로 감
			now.speed = now.speed - rest_dist; //남은 거리 만큼 소요
			int one_way = now.speed / (C - 1); //편도 가능 여부 및 횟수
			int last_dist = now.speed % (C - 1); // 최종 남은 거리

			if (one_way > 0) { //남은 추진력이 있다면
				if (one_way % 2 == 0) {//현재와 동일 위치
					if (last_dist != 0) {
						now.dir = 3; //방향 전환
					}
				}
				else {//현재와 정반대 위치
					now.y = C;
				}
			}
			else { //없다면
				now.dir = 3; //방향 전환
			}
			now.y += last_dist * dy[now.dir];//남은 거리만큼 이동
		}
	}
	shark[idx] = { now.x,now.y,shark[idx].speed,now.dir,now.size };
}

int main()
{
	cin >> R >> C >> M;

	for (int i = 0; i < M; ++i) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		shark.push_back({ r,c,s,d,z });
	}

	//상어 잡기 시작
	for (int i = 1; i <= C; ++i) {

		//낚시왕이 있는 열 중 땅과 제일 가까운 상어 찾기
		int narrow_to_ground = 101; //같은 열 중 가장 작은 행 찾기
		int shark_index = 10000;
		for (int j = 0; j < shark.size(); ++j) {
			if (shark[j].size == 0) continue; //이미 존재하지 않은 상어
			if (i == shark[j].y) { //같은 열임
				if (shark[j].x < narrow_to_ground) {// 현재 검색한 상어들 중 가장 땅과 가까운 행
					narrow_to_ground = shark[j].x; //행 갱신
					shark_index = j; // 상어 갱신
				}
			}
		}

		if (shark_index != 10000) { //상어가 잡혔다면
			ans += shark[shark_index].size; //잡은 상어 더하고
			shark[shark_index].size = 0; //잡은 상어 표시
		}

		//상어 이동하기
		for (int j = 0; j < shark.size(); ++j) {
			if (shark[j].size == 0) continue; //이미 존재하지 않은 상어
			moveShark(j);
		}

		//겹치는 상어 확인
		info flag_shark = { 0,0,0,0,0 };
		sort(shark.begin(), shark.end()); //상어 정렬
		for (int j = 0; j < shark.size(); ++j) {
			if (shark[j].size == 0) continue; //존재하지 않은 상어
			if (flag_shark.x == shark[j].x&&flag_shark.y == shark[j].y) {//기준 상어와 위치가 같다면
				shark[j].size = 0;
			}
			else {
				flag_shark = shark[j];
			}
		}

	}

	cout << ans;

	return 0;
}