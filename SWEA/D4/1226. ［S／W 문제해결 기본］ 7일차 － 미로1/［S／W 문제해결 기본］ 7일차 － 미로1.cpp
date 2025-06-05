#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct miro
{
	int x;
	int y;
};

char map[16][16];
int ret;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void init()
{
	memset(map, 0, sizeof(map));
	ret = 0;
}

void input()
{
	for (int i = 0; i < 16; i++)
	{
		cin >> map[i];
	}
}

int bfs(int x, int y)
{
	queue<miro> q;
	int visited[16][16] = { 0, };

	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty())
	{
		miro now = q.front();
		q.pop();

		if (map[now.x][now.y] == '3')
		{
			return 1;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= 16 || ny >= 16) continue;
			if (map[nx][ny] == '1') continue;
			if (visited[nx][ny] == 1) continue;

			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}

	return 0;
}

void solve()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (map[i][j] == '2')
			{
				ret = bfs(i, j);
				return;
			}
		}
	}
}

int main()
{
	for (int tc = 1; tc <= 10; tc++)
	{
		int num;
		cin >> num;

		init();
		input();
		solve();

		cout << "#" << tc << " " << ret << "\n";
	}

}