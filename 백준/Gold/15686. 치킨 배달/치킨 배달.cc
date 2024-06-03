#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	int x;
	int y;
};

int map[51][51];
int N, M;
int min_dist = 21e8;
vector<info>chken;
vector<info>home;
vector<int>ans;

void dfs(int lv,int idx) {
	if (lv == M) {
		int dist_sum = 0;
		for (int i = 0; i < home.size(); i++) {
			int dist = 21e8;
			for (int j = 0; j <M; j++) {
				int tmp = abs(home[i].x - chken[ans[j]].x) + abs(home[i].y - chken[ans[j]].y);
				dist = min(dist, tmp);
			}
			dist_sum += dist;
			if (dist_sum >= min_dist) return;
		}
		min_dist = min(min_dist, dist_sum);
		return;
	}
	for (int i = idx; i < chken.size(); i++) {
		ans.push_back(i);
		dfs(lv + 1, i + 1);
		ans.pop_back();
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			//집과 치킨집 버퍼 만들기
			if (map[i][j] == 0) continue;
			else if (map[i][j] == 1) home.push_back({ i,j });
			else if (map[i][j] == 2) chken.push_back({ i,j });
		}
	}

	dfs(0, 0);

	cout << min_dist;

	return 0;
}