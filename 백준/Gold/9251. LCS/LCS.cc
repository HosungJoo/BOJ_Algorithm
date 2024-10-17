#include<iostream>
#include<algorithm>

using namespace std;

string str1, str2;
int dp[1001][1001];

int main()
{
	cin >> str1 >> str2;

	for (int i = 1; i <= str1.length(); ++i) {
		for (int j = 1; j <= str2.length(); ++j) {

			if (str1[i-1] == str2[j-1]) { //같은 문자면 
				//이전 부분 수열에 현재 문자 + 1 과 이전 부분 수열 개수 비교 
				dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i - 1][j]);
			}
			else { //다른 문자면 이전 부분수열 개수 과 현재 부분 수열 개수 중 비교
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}

		}
	}

	cout << dp[str1.length()][str2.length()];

	return 0;
}