#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct info {
	int vtx;
	char ch;
};

int numOfvtx; //���� ����
int strLen; //���ڿ� ����
string dadPath; //�ƹ����� �����ϽŴ� ��å��
int visited[5001]; //�湮 �迭
vector<info>path[5001];//Ʈ�� ���� ����
int dp[5001][5001];
int happy;

//����:���̻� ������ ������ Leaf
int isEnd(int v) {
	for (int i = 0; i < path[v].size(); ++i) {
		if (visited[path[v][i].vtx] == 0) {
			return 0;
		}
	}
	return 1;
}

//depth���� LCSó�� �ϴ� �� �ٽ�
//����� ����ϸ� O(N^3)�� ��
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
	//��������
	if (isEnd(curVex) == 1) {
		happy = max(happy, dp[depth][strLen]);
		return;
	}
	for (int i = 0; i < path[curVex].size(); ++i) {
		info now = path[curVex][i];
		if (visited[now.vtx] == 1) continue;
		visited[now.vtx] = 1; //���� ����
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