#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct info {
	int vtx;
	char ch;
};

int numOfvtx; //정점 개수
int strLen; //문자열 길이
string dadPath; //아버지가 좋아하신는 산책길
int visited[5001]; //방문 배열
vector<info>path[5001];//트리 간선 정보
int dp[5001][5001];
int happy;

//종료:더이상 갈곳이 없으면 Leaf
int isEnd(int v) {
	for (int i = 0; i < path[v].size(); ++i) {
		if (visited[path[v][i].vtx] == 0) {
			return 0;
		}
	}
	return 1;
}

//depth마다 LCS처리 하는 게 핵심
//만들고 계속하면 O(N^3)이 됨
void dfs(int depth, int curVex, char curPath) {
	if (depth != 0) {
		//LCS
		for (int i = 1; i <= strLen; ++i) {
			if (dadPath[i - 1] == curPath) {
				dp[depth][i] = max(dp[depth - 1][i - 1] + 1, dp[depth - 1][i]);
			}
			else {
				dp[depth][i] = max(dp[depth][i-1],dp[depth - 1][i]);
			}
		}
	}
	//종료조건
	if (isEnd(curVex) == 1) {
		happy = max(happy, dp[depth][strLen]);
		return;
	}
	for (int i = 0; i < path[curVex].size(); ++i) {
		info now = path[curVex][i];
		if (visited[now.vtx] == 1) continue;
		visited[now.vtx] = 1; //역행 방지
		dfs(depth + 1, now.vtx, now.ch);
	}
}

int main(int argc, char** argv)
{
	//Input
	cin >> numOfvtx >> strLen;
	cin>> dadPath;

	for (int i = 0; i < numOfvtx - 1; ++i) {
		int from, to;
		char ch;
		cin >> from >> to >> ch;
		path[from].push_back({ to,ch });
		path[to].push_back({ from,ch });
	}

	dfs(0, 1, 0);

	cout << happy;

	return 0;
}