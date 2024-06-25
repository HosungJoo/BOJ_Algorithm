#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

/*
* 넓이가 완성될 때는 각 받아야하는 점들 중에
* x와 y좌표의 최대 최소를 통한 넓이를 만들때 가능하다
* 이 때 재귀를 탈때 시간초과를 방지하기 위해 이전에 완성된 넓이보다
* 클경우 이전에 재귀를 타지 않는 것이 핵심이다.
*/

using namespace std;

int N, K;
int ans = 21e8;
vector<pair<int, int>>dot[21];

void recur(int level, int minx, int miny, int maxx, int maxy, int sum) {
    if (level == K + 1) {
        ans = sum;
        return;
    }
    for (int i = 0; i < dot[level].size(); i++) {
        int nx = dot[level][i].first;
        int ny = dot[level][i].second;

        int tmpminx = min(minx, nx);
        int tmpminy = min(miny, ny);
        int tmpmaxx = max(maxx, nx);
        int tmpmaxy = max(maxy, ny);

        int tmpsum = (tmpmaxx - tmpminx) * (tmpmaxy - tmpminy);
        if (tmpsum < ans) {
            recur(level + 1, tmpminx, tmpminy, tmpmaxx, tmpmaxy, tmpsum);
        }
    }

}

int main(int argc, char** argv)
{
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int x, y, num;
        cin >> x >> y >> num;

        dot[num].push_back({ x,y });
    }

    recur(1, 1000, 1000, -1000, -1000, ans);


    cout << ans;

    return 0;
}