#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct cell {
    int x;
    int y;
    int wtAct; //활성 되기 까지 시간
    int Dietm; //활성이후 사는 시간
    bool operator<(cell right) const {
        return wtAct < right.wtAct;
    }
};

int T;
int N, M, K;
int ans;
vector<cell>cells;
priority_queue<cell>pq; //활성한 된 친구들 퍼트릴거
int map[350][350];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void init() {
    memset(map, 0, sizeof(map));
    ans = 0;
    cells.clear();
}

void input() {
    cin >> N >> M >> K;
    for (int i = 150; i < N+150; i++) {
        for (int j = 150; j < M+150; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0) {
                cells.push_back({ i,j,map[i][j],map[i][j] * 2 + 1 });
            }
        }
    }
}

void solve() {
    int Diecell = 0;
    while (K != 0) {
        K--;
        for (int i = 0; i < cells.size(); i++) {
            cells[i].Dietm--;//시간지나면 죽음
            if (cells[i].Dietm == cells[i].wtAct) {
                pq.push(cells[i]);
            }
            if (cells[i].Dietm == 1) {
                Diecell++;
            }
        }
        while (!pq.empty()) {
            cell now = pq.top();
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (map[nx][ny] == 0) {
                    map[nx][ny] = now.wtAct;
                    cells.push_back({ nx,ny,map[nx][ny],map[nx][ny] * 2 + 1 });
                }
            }
        }
    }

    ans = cells.size() - Diecell;
}

int main() {

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        init();
        input();
        solve();

        cout << "#" << tc << " " << ans << "\n";
        
    }


    return 0;
}


