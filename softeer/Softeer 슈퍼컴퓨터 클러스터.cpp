#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
* ���ǻ��� ���� �ִ�ġ ��� �ִ�ġ�̸�
* ������ 2e9���� �ø� �� �ִ�.
* bs�� ���� ������� �ִ�ġ ���� ������ �Ǵ� ��ǻ�͸� ã���� �ȴ�
* �̶� ����� ����� �� ���� ��뺸�� Ŀ�������� �ٷ� ������
* �׷��������� overflow �߻�
*/

int N; //��ǻ�� ��
long long totcost; //���� ��� ���
vector<long long>com; //��ǻ�� ����


int bs() {
    long long start = 1;
    long long end = 2e9;
    long long mid = 0;
    long long lowest_spec = 0;

    while (start <= end) {
        mid = (start + end) / 2;
        long long cost = 0;

        for (int i = 0; i < N; i++) {
            if (com[i] < mid) {
                cost += (long long)(mid - com[i]) * (mid - com[i]);
                if (cost > totcost) break;
            }
        }
        if (cost <= totcost) {
            start = mid + 1;
            lowest_spec = mid;
        }
        else {
            end = mid - 1;
        }
    }
    return lowest_spec;
}

int main(int argc, char** argv)
{
    cin >> N >> totcost;

    for (int i = 0; i < N; i++) {
        long long spec;
        cin >> spec;
        com.push_back(spec);
    }

    sort(com.begin(), com.end());

    long long ans = bs();

    cout << ans;

    return 0;
}