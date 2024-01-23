#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


using namespace std;


int main()
{
	
	int up, down, height;
	cin >> up >> down >> height;

	int days = 1;
	int valid = up - down;

	days += (height - up) / valid;
	
	if ((height - up) % valid != 0)
	{
		days++;
	}
	if (up >= height)
	{
		cout << "1";
	}
	else
	{
		cout << days;
	}


	return 0;
}