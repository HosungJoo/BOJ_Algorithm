#include <iostream>

using namespace std;

int main()
{
	int n, cnt = 1; 
	int final = 666; //연속666부터 시작


	cin >> n;

	while (n != cnt) //cnt==1이면 그대로 666출력 cnt가 N번째가 될때 while문 종료
	{
		final++; //666을 1씩 증가시켜서 N번째 작은 종말의 수를 찾음

		int tmp = final; //final값을 대신하여 검증할 변수 받음

		if (tmp % 1000 == 666) //666 연속하는 수가 되는 지 확인
		{
			cnt++; //True이면 cnt를 증가 시킨다.
		}
		else 
		{
			while (tmp != 0)
			{
				tmp = tmp / 10; //자릿수를 감소 시켜 666이 되는 지 확인
				if (tmp%1000 == 666)
				{
					cnt++; //666을 찾으면 종료시킨다
					break;
				}
			}
		}
		
	}

	
	cout << final;
	
	return 0;
}