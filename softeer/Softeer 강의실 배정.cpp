#include<iostream>
#include<algorithm>

using namespace std;

//문제 출력을 잘못 이해함
//강의장 개수가 아니라 강의실 1개 최대 강의 수 였다

int N;
pair<int, int>tmTable[1000000];

bool cmp(pair<int, int>lf, pair<int, int>rg) {
    if (lf.second < rg.second) {
        return true;
    }
    else if (lf.second > rg.second) {
        return false;
    }
    else {
        if (lf.first < rg.first) {
            return true;
        }
        else {
            return false;
        }
    }
}

int main(int argc, char** argv)
{
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int st, en;
        cin >> st >> en;

        tmTable[i] = { st,en };
    }

    sort(tmTable, tmTable + N, cmp);

    int en = 0;
    int lec = 0;
    for (int i = 0; i < N; ++i) {
        if (en > tmTable[i].first) {
            continue;
        }
        en = tmTable[i].second;
        ++lec;
    }

    cout << lec;

    return 0;
}