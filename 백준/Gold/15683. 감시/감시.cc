#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct info {
    int x;
    int y;
};

int N, M;
int map[9][8][8];
int tot_cnt;
vector<info>cctv;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans = 21e8;

int check(int x, int y, int node) {
    if (x < 0 || y < 0 || x >= N || y >= M) return 0; //Out of Bound
    if (map[0][x][y] == 6) return 0; //벽
    if (map[0][x][y] > 0 && map[0][x][y] < 6) return 1; //cctv 존재
    if (map[node][x][y] == 7) return 1; // 이미 감시
    return 2;
}

int monitoring(int node,int dir, int x,int y) {
    int cnt = 0;

    while (1) {
        x += dx[dir];
        y += dy[dir];

        int chk = check(x, y, node);

        if (chk == 0) break;
        else if (chk == 1) continue;
        else {
            map[node][x][y] = 7;
            ++cnt;
        }
    }

    return cnt;
}

void dfs(int node, int cnt) {
    if (node == cctv.size() + 1) {
        ans = min(ans, tot_cnt-cnt);
        return;
    }

    info now = cctv[node - 1];
    int cam = map[0][now.x][now.y]; //cctv 종류

    if (cam == 1) {
        for (int i = 0; i < 4; ++i) { // 한 방향 90도씩 돌리기
            int tmp_cnt = 0; //감시 영역 개수
            memcpy(map[node], map[node - 1], sizeof(map[node])); // 이전 단 map을 복사

            tmp_cnt += monitoring(node, i, now.x, now.y);
            dfs(node + 1, cnt + tmp_cnt);
        }
    }
    else if (cam == 2) {
        for (int i = 0; i < 2; ++i) { // 수평 감시 돌리기
            int tmp_cnt = 0; //감시 영역 개수
            memcpy(map[node], map[node - 1], sizeof(map[node])); // 이전 단 map을 복사

            if (i == 0) { //상하
                tmp_cnt += monitoring(node, 0, now.x, now.y);
                tmp_cnt += monitoring(node, 1, now.x, now.y);
            }
            else { //좌우
                tmp_cnt += monitoring(node, 2, now.x, now.y);
                tmp_cnt += monitoring(node, 3, now.x, now.y);
            }
            dfs(node + 1, cnt + tmp_cnt);
        }
    }
    else if (cam == 3) {
        for (int i = 0; i < 4; ++i) { //직각 돌리기
            int tmp_cnt = 0; //감시 영역 개수
            memcpy(map[node], map[node - 1], sizeof(map[node])); // 이전 단 map을 복사

            if (i == 0) { //상우
                tmp_cnt += monitoring(node, 0, now.x, now.y);
                tmp_cnt += monitoring(node, 3, now.x, now.y);
            }
            else if (i == 1) { //우하
                tmp_cnt += monitoring(node, 3, now.x, now.y);
                tmp_cnt += monitoring(node, 1, now.x, now.y);
            }
            else if (i == 2) { //하좌
                tmp_cnt += monitoring(node, 1, now.x, now.y);
                tmp_cnt += monitoring(node, 2, now.x, now.y);
            }
            else { //좌상
                tmp_cnt += monitoring(node, 2, now.x, now.y);
                tmp_cnt += monitoring(node, 0, now.x, now.y);
            }
            dfs(node + 1, cnt + tmp_cnt);
        }
    }
    else if (cam == 4) {
        for (int i = 0; i < 4; ++i) { //직각 돌리기
            int tmp_cnt = 0; //감시 영역 개수
            memcpy(map[node], map[node - 1], sizeof(map[node])); // 이전 단 map을 복사

            if (i == 0) { //상좌우
                tmp_cnt += monitoring(node, 0, now.x, now.y);
                tmp_cnt += monitoring(node, 2, now.x, now.y);
                tmp_cnt += monitoring(node, 3, now.x, now.y);
            }
            else if (i == 1) { //상우하
                tmp_cnt += monitoring(node, 0, now.x, now.y);
                tmp_cnt += monitoring(node, 3, now.x, now.y);
                tmp_cnt += monitoring(node, 1, now.x, now.y);
            }
            else if (i == 2) { //하좌우
                tmp_cnt += monitoring(node, 1, now.x, now.y);
                tmp_cnt += monitoring(node, 2, now.x, now.y);
                tmp_cnt += monitoring(node, 3, now.x, now.y);
            }
            else { //좌상하
                tmp_cnt += monitoring(node, 0, now.x, now.y);
                tmp_cnt += monitoring(node, 1, now.x, now.y);
                tmp_cnt += monitoring(node, 2, now.x, now.y);
            }
            dfs(node + 1, cnt + tmp_cnt);
        }
    }
    else if (cam == 5) {
        int tmp_cnt = 0; //감시 영역 개수
        memcpy(map[node], map[node - 1], sizeof(map[node])); // 이전 단 map을 복사

        tmp_cnt += monitoring(node, 0, now.x, now.y);
        tmp_cnt += monitoring(node, 1, now.x, now.y);
        tmp_cnt += monitoring(node, 2, now.x, now.y);
        tmp_cnt += monitoring(node, 3, now.x, now.y);

        dfs(node + 1, cnt + tmp_cnt);
    }

}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[0][i][j];
            if (map[0][i][j] == 0) { //벽과 카메라를 제외한 칸 수
                ++tot_cnt;
            }
            else if (map[0][i][j] < 6) { //감시 카메라 위치 버퍼
                cctv.push_back({ i,j });
            }
        }
    }

    dfs(1, 0);

    cout << ans;
    
    return 0;
}