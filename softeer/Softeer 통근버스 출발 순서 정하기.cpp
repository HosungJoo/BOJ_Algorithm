#include<iostream>

using namespace std;

/*
-유의상항
자연수라고 했지 int범위를 안넘는다고 한 적 없다를 유의하자
3중 for문으로 할 경우 시간초과를 마주한다
N=5000이다

1번째 for문에서 일단 index 0부터 N-3까지 기준을 잡는다
(N-3인 이유는 N=3이상부터이고 어짜피 자기포함 3개 안되면 할 필요없음)

스택정렬이 불가능 한 경우는
i(기준 index)<j(기준보다 큰 수 index)<k(기준보다 작은 수 index)를
만족해야한다.

2번째 for문에서는 기준보다 큰 수를 찾는다. 2번째 for문으로 탐색 중에
기준보다 큰수를 만나기 전에 있는
기준보다 작은 수가 있다면 count한다.
이유는 기준보다 큰 수를 기점으로
기준보다 작은수가 기준보다 큰 수의 index이전에 있다면
불가능한 가짓수에 포함되지 않기 때문이다.

또한 이미 기준보다 작은 수가 기준 전에 있을 수 있는 경우가 있기 때문에
수열을 입력 받은 이후 2중 for문으로 현재 index의 버스 번호보다
이전 index에 현재 버스번호보다 작은 버스가 있다면 개수를 저장하도록 한다.

이 상황을 고려하면
기준을 잡은 버스 기준으로
불가능한 가짓수
= (기준 번호 - 1) - (기준 인덱스 전 작은 버스 수)
- (기준 보다 큰 수 만나기 전 기준보다 작은 번호 버스 수) 가 성립한다.

이 연산을 통해서 0이면 가능한거고
0이 아닌 다른 수가 나오면 불가능한 가짓수가 나온다.

*/

int N;
long long bus[5000];
long long lowbus[5000];

long long impossible;


int main(int argc, char** argv)
{
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> bus[i]; //순서별 버스 번호    
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (bus[i] > bus[j]) {
                lowbus[i]++;
            }
        }
    }

    for (int i = 0; i <= N - 3; i++) {
        int standard = bus[i];
        int lowcnt = 0;
        for (int j = i + 1; j <= N - 2; j++) {
            if (standard < bus[j]) {
                int mid = bus[j];
                impossible += (standard - 1 - lowbus[i] - lowcnt);
            }
            else {
                lowcnt++;
            }
        }
    }

    cout << impossible;

    return 0;
}