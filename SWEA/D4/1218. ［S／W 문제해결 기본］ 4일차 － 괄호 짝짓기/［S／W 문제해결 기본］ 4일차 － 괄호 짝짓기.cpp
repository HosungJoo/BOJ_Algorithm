#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<char>gwalho[4]; //0:() 1:[] 2:{} 3:<>
bool flag;
string str;
int n;

void init()
{
	for (int i = 0; i < 4; i++)
		gwalho[i].clear();
	str.clear();
	flag = true;
}

void input()
{
	cin >> n >> str;
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		char el = str[i];
		if (el == '(') {
			gwalho[0].push_back(el);
		}
		else if (el == ')') {
			if (gwalho[0].empty())
			{
				flag = false;
				return;
			}
			gwalho[0].pop_back();
		}
		else if (el == '[') {
			gwalho[1].push_back(el);
		}
		else if (el == ']') {
			if (gwalho[1].empty())
			{
				flag = false;
				return;
			}
			gwalho[1].pop_back();
		}
		else if (el == '{') {
			gwalho[2].push_back(el);
		}
		else if (el == '}') {
			if (gwalho[2].empty())
			{
				flag = false;
				return;
			}
			gwalho[2].pop_back();
		}
		else if (el == '<') {
			gwalho[3].push_back(el);
		}
		else if (el == '>') {
			if (gwalho[3].empty())
			{
				flag = false;
				return;
			}
			gwalho[3].pop_back();
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!gwalho[i].empty())
		{
			flag = false;
			return;
		}
	}
}

int main()
{
	for (int tc = 1; tc <= 10; tc++)
	{
		init();
		input();
		solve();

		cout << "#" << tc << " " << flag << "\n";
	}
	

	
	return 0;
}