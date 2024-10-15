#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

double force[4]; //�絹�� �� arr
double prob[4][4][3]; //��뺰 ���� Ȯ��
int score[4]; //���� arr
double ans; 

void dfs(int me, int oth, double p) {
    if (oth == 4) {
        if (me == 2) {

            vector<pair<int, int>>rAnk;
            for (int i = 0; i < 4; ++i) {
                rAnk.push_back({ score[i],i });
            }

            sort(rAnk.begin(), rAnk.end(), greater<>()); //���� ������ sort

            if (rAnk[1].first <= score[0]) { //2���̻��̸� Ȯ�� ���ϱ�
                ans += p;
            }

        }
        else {
            dfs(me + 1, me + 2, p);
        }
        return;
    }

    //�¸�
    score[me] += 3;
    dfs(me, oth + 1, p * prob[me][oth][0]);
    score[me] -= 3;

    //�й�
    score[oth] += 3;
    dfs(me, oth + 1, p * prob[me][oth][2]);
    score[oth] -= 3;

    //���
    score[me] += 1;
    score[oth] += 1;
    dfs(me, oth + 1, p * prob[me][oth][1]);
    score[me] -= 1;
    score[oth] -= 1;


}

int main(int argc, char** argv)
{
    for (int i = 0; i < 4; ++i) {
        cin >> force[i];
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            //i win
            prob[i][j][0] = 4 * force[i] / (5 * force[i] + 5 * force[j]);

            //i j draw
            prob[i][j][1] = (force[i] + force[j]) / (5 * force[i] + 5 * force[j]);

            //j win
            prob[i][j][2] = 4 * force[j] / (5 * force[i] + 5 * force[j]);
        }
    }

    dfs(0, 1, 1);

    ans *= 1000000; // �����(100) * ��°�ڸ� Ȯ��(10000)
    int tmp = (int)ans;
    if (tmp % 10 >= 5) {
        printf("%.3lf", ans / 10000); //�ڵ� �ݿø�
    }
    else {
        printf("%.3lf", ans / 10000); //�ڵ� �ݿø�
    }


    return 0;
}