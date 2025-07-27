#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>A;
vector<int>B;

int bs(int start, int end, int target)
{
	int mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (target == B[mid])
		{
			return 0;
		}
		else if (B[mid] < target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return target;
}

int main()
{
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; i++)
	{
		int el;
		cin >> el;
		A.push_back(el);
	}

	for (int i = 0; i < b; i++)
	{
		int el;
		cin >> el;
		B.push_back(el);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	vector<int>ans;
	for (int i = 0; i < a; i++)
	{
		int out = bs(0, b, A[i]);
		if (out)
		{
			ans.push_back(A[i]);
		}
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}