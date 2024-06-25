#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

/*
* ���̰� �ϼ��� ���� �� �޾ƾ��ϴ� ���� �߿�
* x�� y��ǥ�� �ִ� �ּҸ� ���� ���̸� ���鶧 �����ϴ�
* �� �� ��͸� Ż�� �ð��ʰ��� �����ϱ� ���� ������ �ϼ��� ���̺���
* Ŭ��� ������ ��͸� Ÿ�� �ʴ� ���� �ٽ��̴�.
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