#include<iostream>
#include<cstring>
#include<string>

using namespace std;

char map[8][8];
int N;
int ans;
int n;

void Init()
{
	memset(map, 0, sizeof(map));
	ans = 0;
}

void Input()
{
	cin >> N;
	n = N;
	for (int i = 0; i < 8; i++)
	{
		cin >> map[i];
	}
	
}

bool MakeRow(int row, int start)
{
	string just = "";
	for (int i = start; i < start + n; i++)
	{
		just += map[row][i];
	}

	string reverse = "";
	for (int i = start + n -1; i >= start; i--)
	{
		reverse += map[row][i];
	}

	if (strcmp(just.c_str(), reverse.c_str()) == 0)
	{
		return true;
	}
	return false;
}

bool MakeCol(int col, int start)
{
	string just = "";
	for (int i = start; i < start + n; i++)
	{
		just += map[i][col];
	}

	string reverse = "";
	for (int i = start + n - 1; i >= start; i--)
	{
		reverse += map[i][col];
	}

	if (strcmp(just.c_str(), reverse.c_str()) == 0)
	{
		return true;
	}
	return false;
}

void Solve()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j + n <= 8)
			{
				if (MakeRow(i, j) == true)
				{
					ans++;
				}
			}

			if (i + n <= 8)
			{
				if (MakeCol(j, i) == true)
				{
					ans++;
				}
			}
		}
	}
}

int main()
{
	for (int tc = 1; tc <= 10; tc++)
	{
		Init();
		Input();
		Solve();
		cout << "#" << tc << " " << ans << "\n";
	}
}