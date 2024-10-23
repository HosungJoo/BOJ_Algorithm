#include<iostream>

using namespace std;

//�������� �ŵ����� ����

long long K; //�ʱ� ���̷���
long long P; //������
long long N; //�ð�
long long moD = 1000000007;

long long poW() {
    long long res = 1;

    while (N) {
        if (N & 1) { //������ LSB�� 1�� ���� ������ ���Ƿ� ������
            res = (res * P) % moD;
        }
        N = N >> 1; //���� �о��ֱ�
        P = (P * P) % moD; //���� ������ֱ�
    }
    return res;
}

int main(int argc, char** argv)
{
    cin >> K >> P >> N;

    N *= 10; //0.1�ʸ��� ����

    cout << K * poW() % moD;

    return 0;
}