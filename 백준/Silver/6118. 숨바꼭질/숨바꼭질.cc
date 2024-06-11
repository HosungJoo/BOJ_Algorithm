#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ans {
	int min_node; //먼거리 중 작은 수
	int dist; // 가장 먼 거리
	int cnt_mins; //먼거리 수 갯수
};

vector<int>hut[20001];
int visited[20001];
int N, M;
ans info;

void bfs() {
	queue<int>q;
	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (visited[now] > info.dist) { //새롭게 먼 거리가 제시됨
			info = { now,visited[now],1 };
		}
		else if (visited[now] == info.dist) { //같다면 정보 갱신
			info.min_node = min(now, info.min_node);
			info.cnt_mins++;
		}

		for (int i = 0; i < hut[now].size(); i++) {
			int next = hut[now][i];

			if (visited[next] > 0) continue;

			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}
}

int main() {

	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		hut[from].push_back(to);
		hut[to].push_back(from);
	}

	bfs();

	cout << info.min_node << " " << info.dist-1 << " " << info.cnt_mins;

	return 0;
}