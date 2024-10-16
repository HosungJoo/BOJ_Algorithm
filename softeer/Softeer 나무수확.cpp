#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//������ max�� ���������� ��쿡 ���� �з��� ���� �ʾ� �ָ���

struct info {
    int amount;
    int maxBerry;
};

int N;//���� ũ��
int map[1000][1000];
info dp[1000][1000];

int main(int argc, char** argv)
{
    //Input
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    //�ʱ� ����
    dp[0][0] = { map[0][0],map[0][0] };

    //ù ��
    for (int i = 1; i < N; i++) {
        dp[0][i].amount = dp[0][i - 1].amount + map[0][i];
        dp[0][i].maxBerry = max(dp[0][i - 1].maxBerry, map[0][i]);
    }

    //ù ��
    for (int i = 1; i < N; i++) {
        dp[i][0].amount = dp[i - 1][0].amount + map[i][0];
        dp[i][0].maxBerry = max(dp[i - 1][0].maxBerry, map[i][0]);
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            if (i == N - 1 && j == N - 1) break;
            dp[i][j].amount = max(dp[i - 1][j].amount, dp[i][j - 1].amount) + map[i][j]; //���� ��ġ �ִ� ��Ȯ��

            //��ο� �ִ� ���� ���ſ��� ���� ���� ��Ȯ�� �� �ִ� ���Ÿ� �����;��ϹǷ�
            //������ �Դ��� ���ʿ��� �Դ��� �˾ƾ���
            if (dp[i - 1][j].amount > dp[i][j - 1].amount) {
                dp[i][j].maxBerry = max(map[i][j], dp[i - 1][j].maxBerry);
            }
            else if (dp[i - 1][j].amount < dp[i][j - 1].amount) {
                dp[i][j].maxBerry = max(map[i][j], dp[i][j - 1].maxBerry);
            }
            else {
                dp[i][j].maxBerry = max(map[i][j], max(dp[i][j - 1].maxBerry, dp[i - 1][j].maxBerry));
            }
        }
    }

    int down = dp[N - 2][N - 1].amount + map[N - 1][N - 1] + max(map[N - 1][N - 1], dp[N - 2][N - 1].maxBerry);
    int right = dp[N - 1][N - 2].amount + map[N - 1][N - 1] + max(map[N - 1][N - 1], dp[N - 1][N - 2].maxBerry);

    cout << max(down, right);


}