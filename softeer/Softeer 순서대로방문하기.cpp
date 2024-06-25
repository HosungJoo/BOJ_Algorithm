#include<iostream>
#include<vector>

using namespace std;

/*
* n이 4가 최대이므로 DFS를 무한으로 즐기기 가능
* 방향좌표와 visited를 이용해 넘어가며 다음 좌표에 도착하면
* dfs를 다음 좌표를 향하도록 다시 호출한다.
* 마지막 좌표에 도달할 때마다 카운트하면 서로 다른 방법의 수가 나온다.
*/

struct spot {
    int x;
    int y;
};

int n; //맵의 크기
int m; //방문지점 개수
int ans;
int map[4][4];
bool visited[4][4];
vector<spot> v;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int x, int y, int level) {
    if (x == v[level + 1].x && y == v[level + 1].y) { //다음 좌표에 도달 체크
        if (level + 1 == m - 1) { //마지막 방문 곳인지 확인
            ans++;
            return;
        }
        dfs(x, y, level + 1); // 다음레벨로
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (map[nx][ny] == 1) continue;
        if (visited[nx][ny] == 1) continue;

        visited[nx][ny] = 1;
        dfs(nx, ny, level);
        visited[nx][ny] = 0;

    }
}

int main(int argc, char** argv)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x - 1,y - 1 });
    }

    visited[v[0].x][v[0].y] = 1;
    dfs(v[0].x, v[0].y, 0);

    cout << ans;

    return 0;
}