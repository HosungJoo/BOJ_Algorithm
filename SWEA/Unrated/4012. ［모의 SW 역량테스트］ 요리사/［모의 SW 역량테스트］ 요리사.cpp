#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


using namespace std;

int T;
int N;
int map[16][16];
int visited[16];
int ans;
vector<int>gro;
vector<int>rest;


void init() {
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    gro.clear();
    rest.clear();
    ans = 20000;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
}

void recur(int level, int idx) {
    if (level == N / 2) {
        int sinuz1 = 0;
        for (int i = 0; i < gro.size() - 1; i++) {
            for (int j = i + 1; j < gro.size(); j++) {
                sinuz1 += (map[gro[i]][gro[j]] + map[gro[j]][gro[i]]);
            }
        }
        
        int sinuz2 = 0;
        for (int i = 0; i < N; i++) if (!visited[i]) rest.push_back(i);
        for (int i = 0; i < rest.size() - 1; i++) {
            for (int j = i + 1; j < rest.size(); j++) {
                sinuz2 += (map[rest[i]][rest[j]] + map[rest[j]][rest[i]]);
            }
        }
        rest.clear();
        ans = min(ans, abs(sinuz1 - sinuz2));
        return;
    }
    for (int i = idx; i < N; i++) {
        gro.push_back(i);
        visited[i] = 1;
        recur(level + 1, i + 1);
        visited[i] = 0;
        gro.pop_back();
    }
}

void solve() {
       recur(0, 0);
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


