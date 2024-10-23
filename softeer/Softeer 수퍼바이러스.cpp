#include<iostream>

using namespace std;

//분할정복 거듭제곱 문제

long long K; //초기 바이러스
long long P; //증가율
long long N; //시간
long long moD = 1000000007;

long long poW() {
    long long res = 1;

    while (N) {
        if (N & 1) { //이진수 LSB가 1일 때는 제곱이 들어가므로 곱해줌
            res = (res * P) % moD;
        }
        N = N >> 1; //제곱 밀어주기
        P = (P * P) % moD; //제곱 만들어주기
    }
    return res;
}

int main(int argc, char** argv)
{
    cin >> K >> P >> N;

    N *= 10; //0.1초마다 증식

    cout << K * poW() % moD;

    return 0;
}