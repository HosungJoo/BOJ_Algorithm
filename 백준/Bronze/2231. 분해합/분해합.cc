#include <iostream>

using namespace std;



int main()
{
	int n;
	int ans = 0;
	cin >> n;
	
	
	for (int i = 1; i < n; i++)
	{
		int sum = 0;
		int tmp = i;
		while (tmp != 0)
		{
			sum += tmp%10; //마지막 자릿수 더함
			tmp = tmp / 10; //자릿수 올리기
		}
		if (sum+i == n) // n+각 자릿수
		{
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}