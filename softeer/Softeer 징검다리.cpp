#include<iostream>
#include<algorithm>

using namespace std;

int N;
int stBridge[3001];
int dp[3001];
int ans;

int main(int argc, char** argv)
{
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> stBridge[i];
    }

    for (int i = 1; i <= N; ++i) {
        dp[i] = 1;
        for (int j = 1; j <= i; ++j) {
            if (stBridge[i] > stBridge[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}