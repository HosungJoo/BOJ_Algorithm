#include<iostream>
#include<queue>

using namespace std;

int old, young;
int visited[100001];
int ans;

void bfs(int x) {
	queue<int>q;

	visited[x] = 1;
	q.push(x);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == young) {
			ans = visited[now] - 1;
			return;
		}

		//X-1
		if (now - 1 >= 0) {
			if (visited[now - 1] == 0) {
				visited[now - 1] = visited[now] + 1;
				q.push(now - 1);
			}
		}

		//X+1
		if (now + 1 <= 100000) {
			if (visited[now + 1] == 0) {
				visited[now + 1] = visited[now] + 1;
				q.push(now + 1);
			}
		}

		//2*X
		if (now * 2 <= 100000) {
			if (visited[2 * now] == 0) {
				visited[2 * now] = visited[now] + 1;
				q.push(2 * now);
			}
		}
	}

}

int main() {

	cin >> old >> young;

	bfs(old);

	cout << ans;

	return 0;
}