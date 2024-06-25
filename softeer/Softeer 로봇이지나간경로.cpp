#include<iostream>
#include<vector>

using namespace std;

/*
* 시작점을 찾는 게 핵심이다.
* 시작점은 4방향을 탐색하여 갈 수 있는 경로가 하나만 나올 때이다.
* 시작점을 찾았으면 이를 기점으로 dfs를 하되
* 방향 전환에 대한 기록을 해야한다.
* 기준 방향은 시계방향으로 잡았다
* 따라서 방향전환이 없으면 직진
* 한번 있으면 우회전
* 세번 있으면 좌회전이다
* dfs의 종료조건을 위해 탐색하면서 #의 개수가 전체 개수가 될때 return되도록 했다.
*/

int H, W;
char map[25][25];
int totshap;
//0:상, 1:우, 2:하, 3:좌
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int visited[25][25];
char sdir[4] = { '^','>','v','<' };
vector<char>order;
int sx, sy;

void dfs(int x, int y, int dir, int cnt) {
    if (totshap == cnt) {
        return;
    }
    int turn = dir; //방향 전환을 몇번했는지 체크
    while (1) {
        int nx = x + dx[dir % 4];
        int ny = y + dy[dir % 4];

        if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
            dir++;
            continue;
        }
        if (map[nx][ny] != '#') {
            dir++;
            continue;
        }
        if (visited[nx][ny] == 1) {
            dir++;
            continue;
        }

        int dnx = nx + dx[dir % 4];
        int dny = ny + dy[dir % 4];

        visited[nx][ny] = 1;
        visited[dnx][dny] = 1;

        if (dir - turn == 0) {
            order.push_back('A');
        }
        else if (dir - turn == 1) {
            order.push_back('R');
            order.push_back('A');
        }
        else if (dir - turn == 3) {
            order.push_back('L');
            order.push_back('A');
        }

        cnt += 2;
        dfs(dnx, dny, dir % 4, cnt);
        return;
    }
}

int main(int argc, char** argv)
{
    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        cin >> map[i];
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] == '#') totshap++;
        }
    }

    //시작점 찾기
    int face = 0;
    int shap = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] == '#') {
                shap = 0;
                for (int s = 0; s < 4; s++) {
                    int chkx = i + dx[s];
                    int chky = j + dy[s];

                    if (chkx < 0 || chky < 0 || chkx >= H || chky >= W) continue;
                    if (map[chkx][chky] == '#') {
                        face = s; //시작 방향
                        shap++; //주위의 # 갯수
                    }
                }
                if (shap == 1) {
                    dfs(i, j, face, 1);
                    sx = i;
                    sy = j;
                    break;
                }
            }
        }
        if (shap == 1) break;
    }

    cout << sx + 1 << " " << sy + 1 << "\n";
    cout << sdir[face] << "\n";
    for (int i = 0; i < order.size(); i++) {
        cout << order[i];
    }

    return 0;
}