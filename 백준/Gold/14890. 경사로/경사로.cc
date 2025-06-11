#include<iostream>
#include<cmath>

using namespace std;

int map[100][100];
int N, L;
int ans;

int main()
{
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	//가로 탐색
	for (int i = 0; i < N; i++)
	{
		int pre = map[i][0];
		int pre_condition = 1;
		bool pass_through = true;

		for (int j = 1; j < N; j++)
		{
			int cur = map[i][j];

			if (pre == cur)
			{
				pre = cur;
				pre_condition++;
			}
			else if (pre - cur == 1)
			{
				int setting_condition = 0;
				int range = j + L;

				for (int k = j; k < range; k++)
				{
					if (k >= N) break;
					if (cur == map[i][k])
					{
						setting_condition++;
					}
				}
				if (setting_condition == L)
				{
					pre = cur;
					j = range - 1;
					pre_condition = 0;
				}
				else
				{
					pass_through = false;
					break;
				}
			}
			else if (pre - cur == -1)
			{
				if (pre_condition >= L) 
				{
					pre = cur;
					pre_condition = 1;
				}
				else
				{
					pass_through = false;
					break;
				}
			}
			else
			{
				pass_through = false;
				break;
			}
		}

		if (pass_through == true) ans++;
 	}

	//세로 탐색
	for (int i = 0; i < N; i++)
	{
		int pre = map[0][i];
		int pre_condition = 1;
		bool pass_through = true;

		for (int j = 1; j < N; j++)
		{
			int cur = map[j][i];

			if (pre == cur)
			{
				pre = cur;
				pre_condition++;
			}
			else if (pre - cur == 1)
			{
				int setting_condition = 0;
				int range = j + L;

				for (int k = j; k < range; k++)
				{
					if (k >= N) break;
					if (cur == map[k][i])
					{
						setting_condition++;
					}
				}
				if (setting_condition == L)
				{
					pre = cur;
					j = range - 1;
					pre_condition = 0;
				}
				else
				{
					pass_through = false;
					break;
				}
			}
			else if (pre - cur == -1)
			{
				if (pre_condition >= L)
				{
					pre = cur;
					pre_condition = 1;
				}
				else
				{
					pass_through = false;
					break;
				}
			}
			else
			{
				pass_through = false;
				break;
			}
		}

		if (pass_through == true) ans++;
	}

	cout << ans;
}