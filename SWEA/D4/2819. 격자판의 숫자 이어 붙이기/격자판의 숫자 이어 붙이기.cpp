#include<iostream>
#include<cstring>
#include<unordered_set>
#include<string>

using namespace std;

int map[4][4];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

unordered_set<string>us;

void init()
{
	memset(map, 0, sizeof(map));
	us.clear();
}

void input()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			cin >> map[i][j];
		}
	}
}

void dfs(int x, int y, int cnt, string str)
{
	if (cnt == 7)
	{
		us.insert(str);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;

		dfs(nx, ny, cnt + 1, str + char(map[x][y] + '0'));
	}
	
}

void solve()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			dfs(i, j, 0, "");
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		solve();

		cout << "#" << tc << " " << us.size() << "\n";
	}
	

	
	return 0;
}