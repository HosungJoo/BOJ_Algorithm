#include <iostream>
#include<queue>
#include<cstring>

using namespace std;

struct knight {
    int x;
    int y;
};

int T;
int N;
int visited[300][300];
int dx[] = { -1,-2,-2,-1,1,2,2,1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };

knight start;
knight destn;

void init() {
    memset(visited, 0, sizeof(visited));
}

void input() {
    cin >> N;
    cin >> start.x >> start.y;
    cin >> destn.x >> destn.y;
}

void bfs(int x, int y) {
    
    queue<knight>q;
    q.push({ x,y });
    visited[x][y] = 1;

    while (!q.empty()) {
        knight now = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visited[nx][ny] != 0) continue;

            visited[nx][ny] = visited[now.x][now.y] + 1;
            q.push({ nx,ny });
            
        }
    }

}

void solve() {
    bfs(start.x, start.y);
}

int main() {

    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        
        init();
        input();
        solve();
        cout << visited[destn.x][destn.y] - 1 << "\n";

    }

    return 0;
}