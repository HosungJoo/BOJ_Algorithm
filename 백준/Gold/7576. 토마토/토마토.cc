#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct tOm {
    int x;
    int y;
};

int M, N;
int map[1000][1000];
int visited[1000][1000];
int tomato;
int cnttomato;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans;

vector<tOm>paw;

void bfs() {
    queue<tOm>q;
    for (int i = 0; i < paw.size(); i++) {
        int x = paw[i].x;
        int y = paw[i].y;
        q.push({ x,y });
        visited[x][y] = 1;
        cnttomato++;
    }

    while (!q.empty()) {
        tOm now = q.front();
        q.pop();

        if (ans < visited[now.x][now.y])
            ans = visited[now.x][now.y];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (map[nx][ny] == -1) continue;
            if (visited[nx][ny] != 0) continue;

            visited[nx][ny] = visited[now.x][now.y] + 1;
            cnttomato++;
            q.push({ nx,ny });
        }
    }
}

int main() {

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] != -1)
                tomato++;
            if (map[i][j] == 1)
                paw.push_back({ i,j });
        }
    }
 
    bfs();

    if (cnttomato == tomato)
        cout << ans - 1;
    else
        cout << -1;

    return 0;
}