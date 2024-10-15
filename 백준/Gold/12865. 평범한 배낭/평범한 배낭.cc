#include<iostream>
#include<vector>

using namespace std;

struct info {
    int w;
    int v;
};

int N, K;
vector<info>bag;
int dp[101][100001];
int ans;

int main()
{
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int weight, value;
        cin >> weight >> value;
        bag.push_back({ weight,value });
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {

            if (bag[i-1].w > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(bag[i - 1].v + dp[i - 1][j - bag[i - 1].w], dp[i - 1][j]);
            }
            
        }
    }

    for (int i = 1; i <= N; ++i) {
        ans = max(dp[i][K], ans);
    }

    cout << ans;
    return 0;
}