#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include<algorithm>
using namespace std;

struct info {
	int node;
	int cost;
	bool operator<(info right)const {
		if (cost < right.cost) return false;
		else if (cost > right.cost) return true;
		else return false;
	}
};

int N, E;
int v1, v2;
vector<info>vecRoute[801];

int dijkstra(int start, int dest) {

	int dist[801];
	for (int i = 0; i <= 800; i++) dist[i] = INT_MAX;
	priority_queue<info>pq;
	dist[start] = 0;
	pq.push({ start,0 });

	while (!pq.empty()) {
		info now = pq.top();
		pq.pop();

		for (int i = 0; i < vecRoute[now.node].size(); i++) {
			info next = vecRoute[now.node][i];
			int nextcost = next.cost + dist[now.node];

			if (dist[next.node] <= nextcost) continue;

			dist[next.node] = nextcost;
			pq.push({ next.node,nextcost });
		}
	}

	//최종지점 및 중간지점들로 가는 경로가 없다면
	if (dist[v1] == INT_MAX || dist[v2] == INT_MAX || dist[N] == INT_MAX) {
		return -1;
	}

	return dist[dest];
}

int main() {

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		vecRoute[from].push_back({ to,cost });
		vecRoute[to].push_back({ from,cost });
	}

	cin >> v1 >> v2;

	int goV1 = 0;
	int goV2 = 0;

	//1번 정점에서 중간지점 확인
	goV1 += dijkstra(1, v1);
	if (goV1 == -1) cout << -1;
	else {
		goV2 = dijkstra(1, v2);

		goV1 += dijkstra(v1, v2);
		goV2 += dijkstra(v2, v1);

		goV1 += dijkstra(v2, N);
		goV2 += dijkstra(v1, N);

		cout << min(goV1, goV2);
	}


	return 0;
}