#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[6][20][20];
int mirr[4][20][20];
int N;
int maxblock;


void top(int lv) { //위로 올리거니까 합칠 때는 위에서 부터 합치는 거 확인
    queue<int>lnstk[20];
    //위에서부터 0이 아닌 것들을 큐에 담는다.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[lv - 1][j][i] != 0) {
                lnstk[i].push(map[lv-1][j][i]);
            }
        }
    }
    //임시 맵에다가 저장함
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            
            if (!lnstk[i].empty()) {
                int now = lnstk[i].front();
                lnstk[i].pop();
                if (!lnstk[i].empty()) {
                    if (now == lnstk[i].front()) {
                        mirr[0][j][i] = now * 2;
                        lnstk[i].pop();
                    }
                    else mirr[0][j][i] = now;
                }
                else mirr[0][j][i] = now;
            }
            else {
                mirr[0][j][i] = 0;
            }
        }
    }

}

void left(int lv) { //왼쪽으로 할거니까 합칠 때는 왼쪽부터 합치는 거 확인
    queue<int>lnstk[20];
   
    //왼쪽부터 0이 아닌 것들을 큐에 담는다.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[lv - 1][i][j] != 0) {
                lnstk[i].push(map[lv - 1][i][j]);
            }
        }
    }
    //임시 맵에다가 저장함
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {


            if (!lnstk[i].empty()) {
                int now = lnstk[i].front();
                lnstk[i].pop();
                if (!lnstk[i].empty()) {
                    if (now == lnstk[i].front()) {
                        mirr[1][i][j] = now * 2;
                        lnstk[i].pop();
                    }
                    else mirr[1][i][j] = now;
                }
                else mirr[1][i][j] = now;
            }
            else {
                mirr[1][i][j] = 0;
            }
        }
    }
}

void bottom(int lv) { //아래로 내릴거니까 합칠 때는 아래에서 부터 합치는 거 확인
    queue<int>lnstk[20];
    int maxtmp = 0;
    //아래에서부터 0이 아닌 것들을 큐에 담는다.
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j >= 0; j--) {
            if (map[lv - 1][j][i] != 0) {
                lnstk[i].push(map[lv - 1][j][i]);
            }
        }
    }
    //임시 맵에다가 저장함
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j >= 0; j--) {


            if (!lnstk[i].empty()) {
                int now = lnstk[i].front();
                lnstk[i].pop();
                if (!lnstk[i].empty()) {
                    if (now == lnstk[i].front()) {
                        mirr[2][j][i] = now * 2;
                        lnstk[i].pop();
                    }
                    else mirr[2][j][i] = now;
                }
                else mirr[2][j][i] = now;
            }
            else {
                mirr[2][j][i] = 0;
            }
        }
    }

  
}

void right(int lv) { //오른쪽으로 할거니까 합칠 때는 오른쪽부터 합치는 거 확인
    queue<int>lnstk[20];
    int maxtmp = 0;
    //오른쪽부터 0이 아닌 것들을 큐에 담는다.
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j >= 0; j--) {
            if (map[lv - 1][i][j] != 0) {
                lnstk[i].push(map[lv - 1][i][j]);
            }
        }
    }
    //임시 맵에다가 저장함
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j >= 0; j--) {


            if (!lnstk[i].empty()) {
                int now = lnstk[i].front();
                lnstk[i].pop();
                if (!lnstk[i].empty()) {
                    if (now == lnstk[i].front()) {
                        mirr[3][i][j] = now * 2;
                        lnstk[i].pop();
                    }
                    else mirr[3][i][j] = now;
                }
                else mirr[3][i][j] = now;
            }
            else {
                mirr[3][i][j] = 0;
            }
        }
    }

}


void board(int lv) {
    if (lv == 6) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (maxblock < map[lv-1][i][j]) {
                    maxblock = map[lv-1][i][j];
                }
            }
        }
        return;
    }

    //위로 올리기
    top(lv);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[lv][i][j] = mirr[0][i][j];
        }
    }
    board(lv + 1);

    
   
    
    //왼쪽으로 넣기
    left(lv);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[lv][i][j] = mirr[1][i][j];
        }
    }
    board(lv + 1);



   //아래쪽으로 놓기
    bottom(lv);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[lv][i][j] = mirr[2][i][j];
        }
    }
    board(lv + 1);

    //오른쪽으로 놓기
    right(lv);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[lv][i][j] = mirr[3][i][j];
        }
    }
    board(lv + 1);
    
}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[0][i][j];
        }
    }

    board(1);

    cout << maxblock;

    return 0;
}


