#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t = 0;
	double num, max = 0, average=0;
	vector<double> v_n;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> num;
		if (num >= max)
		{
			max = num;
		}
		v_n.push_back(num);
	}
	for (int j = 0; j < v_n.size(); ++j)
	{
		
		average += v_n[j] / max * 100;
		
	}
	printf("%lf", average / t);

	return 0;
}
