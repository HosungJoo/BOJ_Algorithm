#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct info {
    int x;
    int y;
    int t;
};

int map[50][50];
int N, M; //row,col
int entr_x, entr_y; //맨홀 입구 좌표
int tm; //소요시간
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans;

void init() {
    memset(map, 0, sizeof(map));
    ans = 1;
}

void input() {
    cin >> N >> M;
    cin >> entr_x >> entr_y;
    cin >> tm;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }
}

bool canGo(int x, int y,int dir) {
    int next_pip = map[x][y];

    if (next_pip == 0) return false;

    if (dir == 0) { //상으로 이동중
        if (next_pip == 3 || next_pip == 4 || next_pip == 7) return false;
    }
    else if (dir == 1) { //하로 이동중
        if (next_pip == 3 || next_pip == 5 || next_pip == 6) return false;
    }
    else if (dir == 2) { //좌로 이동중
        if (next_pip == 2 || next_pip == 6 || next_pip == 7) return false;
    }
    else { //우로 이동중
        if (next_pip == 2 || next_pip == 4 || next_pip == 5) return false;
    }

    return true;
}

void solve() {
    int visited[50][50] = { 0, };
    queue<info> q;
    q.push({ entr_x,entr_y ,1});
    visited[entr_x][entr_y] = 1;
    
    while (!q.empty()) {
        info now = q.front();
        q.pop();

        if (now.t == tm) return;

        int shape = map[now.x][now.y];

        if (shape == 1) { //상하좌우
            for (int i = 0; i < 4; ++i) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (visited[nx][ny] == 1) continue;
                if (!canGo(nx, ny, i)) continue;
                
                q.push({ nx,ny,now.t + 1 });
                visited[nx][ny] = 1;
                ++ans;
            }
        }
        else if (shape == 2) { //상하
            for (int i = 0; i < 2; ++i) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (nx < 0 || nx >= N) continue;
                if (visited[nx][ny] == 1) continue;
                if (!canGo(nx, ny, i)) continue;

                q.push({ nx,ny,now.t + 1 });
                visited[nx][ny] = 1;
                ++ans;
            }
        }
        else if (shape == 3) { //좌우
            for (int i = 2; i < 4; ++i) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (ny < 0 || ny >= M) continue;
                if (visited[nx][ny] == 1) continue;
                if (!canGo(nx, ny, i)) continue;

                q.push({ nx,ny,now.t + 1 });
                visited[nx][ny] = 1;
                ++ans;
            }
        }
        else if (shape == 4) { //상우
            for (int i = 0; i < 4; ++i) {
                if (i == 1 || i == 2) continue;

                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (nx < 0 || ny >= M) continue;
                if (visited[nx][ny] == 1) continue;
                if (!canGo(nx, ny, i)) continue;

                q.push({ nx,ny,now.t + 1 });
                visited[nx][ny] = 1;
                ++ans;
            }
        }
        else if (shape == 5) { //하우
            for (int i = 0; i < 4; ++i) {
                if (i == 0 || i == 2) continue;

                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (nx >= N || ny >= M) continue;
                if (visited[nx][ny] == 1) continue;
                if (!canGo(nx, ny, i)) continue;

                q.push({ nx,ny,now.t + 1 });
                visited[nx][ny] = 1;
                ++ans;
            }
        }
        else if (shape == 6) { //하좌
            for (int i = 0; i < 4; ++i) {
                if (i == 0 || i == 3) continue;

                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (ny < 0 || nx >= N) continue;
                if (visited[nx][ny] == 1) continue;
                if (!canGo(nx, ny, i)) continue;

                q.push({ nx,ny,now.t + 1 });
                visited[nx][ny] = 1;
                ++ans;
            }
        }
        else { //상좌
            for (int i = 0; i < 4; ++i) {
                if (i == 1 || i == 3) continue;

                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (nx < 0 || ny < 0 ) continue;
                if (visited[nx][ny] == 1) continue;
                if (!canGo(nx, ny, i)) continue;

                q.push({ nx,ny,now.t + 1 });
                visited[nx][ny] = 1;
                ++ans;
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; ++tc) {
        init();
        input();
        solve();

        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}