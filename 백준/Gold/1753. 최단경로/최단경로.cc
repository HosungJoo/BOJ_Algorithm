#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct NODE{
	int to;
	int cost;
	bool operator<(NODE right) const {
		if (cost > right.cost) return true;
		else return false;
	}
};

int V, E;
int start;
vector<NODE>node[20001];
int visited[20001];

void dijkstra(int s) {
	for (int i = 0; i <= 20000; i++) visited[i] = 21e8;
	
	priority_queue<NODE>pq;
	visited[s] = 1;
	pq.push({ s,visited[s] });

	while (!pq.empty()) {
		NODE now = pq.top();
		pq.pop();

		for (int i = 0; i < node[now.to].size(); i++) {
			NODE next = node[now.to][i];
			int nextcost = next.cost + visited[now.to];

			if (nextcost >= visited[next.to]) continue;

			pq.push({ next.to,nextcost });
			visited[next.to] = nextcost;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> V >> E >> start;

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		node[from].push_back({to,cost});
	}

	dijkstra(start);

	for (int i = 1; i <= V; i++) {
		if (visited[i] == 21e8) {
			cout << "INF";
		}
		else {
			cout << visited[i] - 1;
		}
		cout << "\n";
	}

	return 0;
}