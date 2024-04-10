#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

struct BC {
	int x;
	int y;
	int dist;
	int chrg;
};

int M, A; //M:이동시간 A:통신탑 갯수
int path_A[100];
int path_B[100];
int dx[] = { 0,-1,0,1,0 };
int dy[] = { 0,0,1,0,-1 };
int ans;
BC AP[8]; //통신탑 정보 buffer
vector<int>useAP[2]; //사용가능 통신 탑 buffer

void init() {
	memset(path_A, 0, sizeof(path_A));
	memset(path_B, 0, sizeof(path_B));
	memset(AP, 0, sizeof(AP));
	ans = 0;
	useAP[0].clear();
	useAP[1].clear();
}

void input() {
	cin >> M >> A;
	//이동자 A경로 입력 받기
	for (int i = 0; i < M; i++) {
		cin >> path_A[i];
	}
	//이동자 B경로 입력 받기
	for (int i = 0; i < M; i++) {
		cin >> path_B[i];
	}
	//통신탑 정보 받기
	for (int i = 0; i < A; i++) {
		int x, y, c, p;
		cin >> y >> x >> c >> p;
		AP[i] = { x,y,c,p };
	}
}

void findAP(int x, int y,int id) {
	int cnt = 0;
	for (int i = 0; i < A; i++) {
		int apx = AP[i].x;
		int apy = AP[i].y;
		int dist = AP[i].dist;

		if ((abs(x - apx) + abs(y - apy)) <= dist) {
			useAP[id].push_back(i);
		}
	}
	
}

void solve() {
	int tm = 0;
	int ax = 1; int ay = 1;
	int bx = 10; int by = 10;
	int tot = 0;

	while (tm <= M) {
		//A 사용가능 AP탐색
		findAP(ax, ay, 0);

		//B 사용가능 AP탐색
		findAP(bx, by, 1);
		
		//사용 AP비교해서 최대 점수 찾기
		//통신탑 갯수
		int posA = useAP[0].size(); 
		int posB = useAP[1].size();

		//충전합 계산
		int sumchrg = 0;
		if (posA != 0 && posB != 0) { //통신탑이 둘다 있음
			for (int i = 0; i < posA; i++) {
				for (int j = 0; j < posB; j++) {

					//사용 통신탑 번호
					int useA = useAP[0][i]; 
					int useB = useAP[1][j];

					if (useA == useB) {
						sumchrg = max(sumchrg, AP[useA].chrg);
					}
					else {
						sumchrg = max(sumchrg, AP[useA].chrg + AP[useB].chrg);
					}

				}
			}
		}
		else if (posA == 0 && posB != 0) { //B만 있음
			for (int i = 0; i < posB; i++) {
				sumchrg = max(sumchrg, AP[useAP[1][i]].chrg);
			}
		}
		else if (posA != 0 && posB == 0) { //A만있음
			for (int i = 0; i < posA; i++) {
				sumchrg = max(sumchrg, AP[useAP[0][i]].chrg);
			}
		}
		
		//최댓값 구한거 누적해주기
		tot += sumchrg;
		//시간 증가
		//tm일때 사용 AP 비워주기
		useAP[0].clear();
		useAP[1].clear();

		//A이동
		ax += dx[path_A[tm]];
		ay += dy[path_A[tm]];

		//B이동
		bx += dx[path_B[tm]];
		by += dy[path_B[tm]];
		tm++;
	}

	ans = tot;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();

		cout << "#" << tc << " " << ans << "\n";
	}


	return 0;
}