#include<iostream>
#include<vector>

using namespace std;

/*
* 하드 코딩에 유의해야한다
* 12개의 신호에 대해 3가지 신호를 방향 배열 인덱스와 일치시킨다.
* 교차로를 2차원을 1차원으로 변환해 벡터로 3가지 신호를 받는다.
* 신호의 주도적인 방향은 %로 확인하여 진입방향과 신호가 맞지 않으면 바로 리턴시킨다
* 이후는 dfs이다
*/

int N, T;
int visited[100][100];
vector<int> cross[10000]; //교차로 신호 저장
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
//0:우 1:상 2:좌 3:하 4:없음

int sign[12][3] = { {1,0,3},{2,1,0},{1,2,3},{2,3,0},
                 {1,0,4},{2,1,4},{2,3,4},{3,0,4},
                 {0,3,4},{1,0,4},{1,2,4},{2,3,4} };

void dfs(int level, int x, int y, int dir) {
    if (level == T) {
        return;
    }
    int stdir = cross[N * x + y][level % 4];
    if (dir != stdir % 4) return; //신호가 맞지 않으며 리턴
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[sign[stdir][i]];
        int ny = y + dy[sign[stdir][i]];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

        visited[nx][ny] = 1;

        dfs(level + 1, nx, ny, sign[cross[N * x + y][level % 4]][i]);
    }
}

int main() {

    cin >> N >> T;

    for (int i = 0; i < N * N; i++) {
        for (int j = 0; j < 4; j++) {
            int sigs;
            cin >> sigs;
            cross[i].push_back(sigs - 1);
        }
    }

    visited[0][0] = 1;
    dfs(0, 0, 0, 1);

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 1) ans++;
        }
    }

    cout << ans;

    return 0;
}