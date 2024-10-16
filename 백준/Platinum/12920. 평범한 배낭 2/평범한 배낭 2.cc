#include<iostream>
#include<vector>

using namespace std;

struct info {
	int w;
	int v;
};

int N, M; //N:물건 종류, M:가방 최대 무게                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
vector<info>matter;
int dp[10001][10001];

int main()
{
	//Input
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		int weight, value, cnt;
		cin >> weight >> value >> cnt;

		//분할
		for (int j = cnt; j > 0; j >>= 1) {
			int part = j - (j >> 1);
			matter.push_back({ weight * part,value * part });
		}
	}

	for (int i = 0; i < matter.size(); ++i) {
		for (int j = 1; j <= M; ++j) {
			if (matter[i].w > j) {
				dp[i + 1][j] = dp[i][j];
			}
			else {
				dp[i + 1][j] = max(matter[i].v + dp[i][j - matter[i].w], dp[i][j]);
			}
		}
	}

	cout << dp[matter.size()][M];

	return 0;
}