
#include<iostream>


using namespace std;

int main()
{
	int n, val = 0;
	cin >> n;
	val = n / 5;
	while (1)
	{
		if (val < 0)
		{
			if (n % 3 == 0)
			{
				val = n / 3;
				break;
			}
			else
			{
				val = -1;
				break;
			}
		}
		else
		{
			if ((n - 5 * val) % 3 == 0)
			{
				val += (n - 5 * val) / 3;
				break;
			}
			val--;
		}


		
	}
	cout << val;

	return 0;
}


