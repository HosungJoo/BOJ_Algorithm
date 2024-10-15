#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int map[3][3];
int cost = 21e8;

int main(int argc, char** argv)
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> map[i][j];
        }
    }

    //가로보기
    for (int r = 0; r < 3; ++r) {
        int tmp = 0;
        for (int c = 1; c < 3; ++c) {
            tmp += abs(map[r][0] - map[r][c]);
        }
        cost = min(cost, tmp);
    }

    //세로보기
    for (int c = 0; c < 3; ++c) {
        int tmp = 0;
        for (int r = 1; r < 3; ++r) {
            tmp += abs(map[0][c] - map[r][c]);
        }
        cost = min(cost, tmp);
    }

    cout << cost;

    return 0;
}