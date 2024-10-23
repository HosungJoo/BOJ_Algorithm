#include<iostream>
#include<algorithm>

using namespace std;

//���� ����� �߸� ������
//������ ������ �ƴ϶� ���ǽ� 1�� �ִ� ���� �� ����

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