
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
	
int n, m;
int x = 0, y = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };


vector<vector<int>> maze;

void miro()
{
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m||maze[nx][ny]==0)
			{
				continue;
			}
			if (maze[nx][ny] == 1)
			{
				maze[nx][ny] = maze[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}


int main()
{
	cin >> n >> m;

	maze = vector<vector<int>>(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%01d", &maze[i][j]);
		}
	}

	miro();
	
	cout << maze[n - 1][m - 1];
	

	return 0;
}


