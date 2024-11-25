#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

struct info {
    int r;
    int c;
    int s;
};


int N, M, K;
int map[7][51][51];
vector<info>rotation;
int pattern[7];
int ans = 21e8;

void spin(int r,int c,int s,int k) {

    int start_row = r - s;
    int end_row = r + s;

    int start_col = c - s;
    int end_col = c + s;

    int dep = (2 * s + 1) / 2;

    for (int j = 0; j < dep; ++j) {

        int s_r = start_row + j;
        int s_c = start_col + j;
        int e_r = end_row - j;
        int e_c = end_col - j;

        int node = map[k][s_r][s_c]; //첫 시작점 저장

        //좌측
        for (int row = s_r + 1; row <= e_r; row++) { //하에서 상으로 덮어쓰기 
            map[k][row - 1][s_c] = map[k][row][s_c];
        }

        //하단
        for (int col = s_c + 1; col <= e_c; col++) { //우에서 좌로 덮어쓰기
            map[k][e_r][col - 1] = map[k][e_r][col];
        }

        //우측
        for (int row = e_r; row >= s_r + 1; row--) { //상에서 하로 덮어쓰기
            map[k][row][e_c] = map[k][row - 1][e_c];
        }

        //상단
        for (int col = e_c; col >= s_c + 2; col--) { //좌에서 우로 덮어쓰기
            map[k][s_r][col] = map[k][s_r][col - 1];
        }

        map[k][s_r][s_c + 1] = node; //상단 좌에서 우로 시작점 하나 덮어쓰기
    }

}

void dfs(int lv) {
    if (lv == K+1) {

        for (int i = 1; i <= N; ++i) {
            int temp = 0;
            for (int j = 1; j <= M; ++j) {
                temp += map[lv - 1][i][j];
            }
            ans = min(ans, temp);
        }

        return;
    }
    
    for (int i = 0; i < rotation.size(); i++) {

        if (pattern[i] == 1) continue; //사용한 돌리기 패턴이면 다른거

        pattern[i] = 1;
        memcpy(map[lv], map[lv - 1], sizeof(map[lv - 1])); //이전 단 모습 가져오기
        spin(rotation[i].r, rotation[i].c, rotation[i].s, lv);
        dfs(lv + 1);
        pattern[i] = 0;

    }

}

int main()
{
    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> map[0][i][j];
        }
    }

    for (int i = 0; i < K; ++i) {

        int r, c, s;
        cin >> r >> c >> s;
        rotation.push_back({ r,c,s });
    }

    dfs(1);

    cout << ans;

    return 0;
}