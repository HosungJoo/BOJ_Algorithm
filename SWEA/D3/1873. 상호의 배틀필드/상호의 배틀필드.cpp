#include<iostream>
#include<cstring>

using namespace std;

struct tank
{
	int dir; //0:상 1:하 2:좌 3:우
	int x;
	int y;
};
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int H, W, N;
char map[20][20];
char cmd[100];
tank player;

void init()
{
	memset(map, 0, sizeof(map));
	memset(cmd, 0, sizeof(cmd));
}

void input()
{
	cin >> H >> W;
	for (int i = 0; i < H; i++)
	{
		cin >> map[i];
		for (int j = 0; j < W; j++)
		{
			if (map[i][j] == '^')
			{
				player = { 0,i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == 'v')
			{
				player = { 1,i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == '<')
			{
				player = { 2,i,j };
				map[i][j] = '.';
			}
			else if(map[i][j] == '>')
			{
				player = { 3,i,j };
				map[i][j] = '.';
			}
		}
	}
	cin >> N;
	cin >> cmd;
}

void moveTank(int dir)
{
	int nx = player.x + dx[dir];
	int ny = player.y + dy[dir];

	if (nx < 0 || ny < 0 || nx >= H || ny >= W) return;
	if (map[nx][ny] != '.') return;

	player.x = nx;
	player.y = ny;
}

void shoot(int dir)
{
	int tx = player.x;
	int ty = player.y;

	while (1)
	{
		tx += dx[dir];
		ty += dy[dir];

		if (tx < 0 || ty < 0 || tx >= H || ty >= W) return;
		if (map[tx][ty] == '#') return;
		if (map[tx][ty] == '*')
		{
			map[tx][ty] = '.';
			return;
		}
	}
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		if (cmd[i] == 'S')
		{
			shoot(player.dir);
		}
		else {
			int tdir = 0;
			if (cmd[i] == 'D') { tdir = 1; }
			else if (cmd[i] == 'L') { tdir = 2; }
			else if (cmd[i] == 'R') { tdir = 3; }
			player.dir = tdir;
			moveTank(tdir);
		}
	}
	
	char c_tdir;
	if (player.dir == 0) { c_tdir = '^'; }
	else if (player.dir == 1) { c_tdir = 'v'; }
	else if (player.dir == 2) { c_tdir = '<'; }
	else { c_tdir = '>'; }

	map[player.x][player.y] = c_tdir;
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
		cout << "#" << tc << " ";
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cout << map[i][j];
			}
			cout << "\n";
		}
	}

}