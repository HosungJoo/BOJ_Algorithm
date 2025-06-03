#include<iostream>
#include<cstring>

using namespace std;

int ladder[100][100];
int visited[100][100];
int ans;

int dx[] = { 0,0,1 };
int dy[] = { 1,-1,0 };

void init()
{
	memset(ladder, 0, sizeof(ladder));
	ans = -1;
}

void input()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			cin >> ladder[i][j];
		}
	}
}

void rideLadder(int x, int y)
{
	int nx = x;
	int ny = y;

	while (1)
	{
		if (nx >= 99)
		{
			if (ladder[nx][ny] == 2) {
				ans = y;
				return;
			}
			else return;
		}

		for (int i = 0; i < 3; i++)
		{
			int nnx = nx + dx[i];
			int nny = ny + dy[i];

			if (nny < 0 || nny >= 100) continue;
			if (ladder[nnx][nny] == 0) continue;
			if (visited[nnx][nny] == 1) continue;

			visited[nnx][nny] = 1;

			nx = nnx;
			ny = nny;
			break;
		}
	}
}

void solve()
{
	for (int i = 0; i < 100; i++)
	{
		if (ladder[0][i] == 1)
		{
			rideLadder(0, i);
			memset(visited, 0, sizeof(visited));
			if (ans != -1)
			{
				return;
			}
		}
	}
}

int main()
{
	for (int tc = 0; tc < 10; tc++)
	{
		int num;
		cin >> num;

		init();
		input();
		solve();

		cout << "#" << num << " " << ans << "\n";
	}

}