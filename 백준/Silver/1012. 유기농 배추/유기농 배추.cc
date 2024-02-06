#include <iostream>
#include<cstring>

using namespace std;


int T;
int M, N, K;
int cnt;
int map[50][50];
int visited[50][50];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void init() {
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    cnt = 0;
}

void input() {
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> y >> x;
        map[x][y] = 1;
    }
}

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (!map[nx][ny]) continue;
        if (visited[nx][ny]) continue;

        visited[nx][ny] = 1;
        dfs(nx, ny);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!map[i][j]) continue;
            if (visited[i][j]) continue;
            dfs(i, j);
            cnt++;
        }
    }
    cout << cnt << "\n";
}

int main() {

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        
        init();
        input();
        solve();
    }
    
    return 0;
}