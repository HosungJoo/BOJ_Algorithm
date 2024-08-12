#include<iostream>
#include<queue>

using namespace std;

struct info {
	int floor;
	int cnt;
};

int F, S, G;//F: 전체 층 수 S: 강호가 있는 층 G:스타트 링크가 있는 층
int U, D; //U: U층을 위로 가는 버튼, D: D층 아래로 가는 버튼

bool visited[1000001];

void bfs() {
	queue<info>q;
	visited[S] = true;
	q.push({ S,0 });

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		if (now.floor == G) {
			cout << now.cnt;
			return;
		}

		//위로 올라가기
		if (now.floor + U <= F) {
			if (!visited[now.floor + U]) {
				q.push({ now.floor + U,now.cnt + 1 });
				visited[now.floor + U] = true;
			}
		}

		//아래로 내려가기
		if (now.floor - D >= 1) {
			if (!visited[now.floor - D]) {
				q.push({ now.floor - D,now.cnt + 1 });
				visited[now.floor - D] = true;
			}
		}
	}

	cout << "use the stairs";
}

int main()
{
	cin >> F >> S >> G >> U >> D;

	bfs();

	return 0;
}