#include<iostream>
#include<algorithm>

using namespace std;

int N;
int ans = -21e8;
int ingred[100002];
int dp[100002];
int rdp[100002];

int preSum[100002];
int proSum[100002];

int main(int argc, char** argv)
{
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> ingred[i];
    }

    //i��°������ �κм�����  ��
    for (int i = 1; i <= N; ++i) {
        dp[i] = max(dp[i - 1] + ingred[i], ingred[i]);
    }

    //i��°�� ������ �� �κм���  ��
    rdp[N] = ingred[N];
    for (int i = N - 1; i >= 1; --i) {
        rdp[i] = max(rdp[i + 1] + ingred[i], ingred[i]);
    }

    preSum[1] = dp[1];
    proSum[N] = rdp[N];


    //i�� ���������� �ִ� �κм��� �� 
    for (int i = 2; i <= N; ++i) {
        preSum[i] = max(preSum[i - 1], dp[i]);
    }

    for (int i = N - 1; i >= 1; --i) {
        proSum[i] = max(proSum[i + 1], rdp[i]);
    }

    //��� ��ᰡ ���ӵǸ� �ȵ�
    for (int i = 2; i <= N - 1; ++i) {
        ans = max(ans, proSum[i + 1] + preSum[i - 1]);
    }

    cout << ans;

    return 0;
}