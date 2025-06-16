#include<iostream>
#include<cstring>

using namespace std;

int test_case[13];
int visited[13];
int n;

void dfs(int cnt, int idx)
{
	if (cnt + (n - idx) < 6) return;
	if (cnt == 6)
	{
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == 1)
			{
				cout << test_case[i] << " ";
			}
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (visited[i] == 1) continue;
		visited[i] = 1;
		dfs(cnt + 1, i);
		visited[i] = 0;
	}
}

int main()
{
	while (1)
	{
		cin >> n;

		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			cin >> test_case[i];
		}

		dfs(0, 0);
		cout << "\n";

		memset(test_case, 0, sizeof(test_case));
		memset(visited, 0, sizeof(visited));
	}
	
	return 0;
}