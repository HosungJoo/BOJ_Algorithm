#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
* 유의사항 성능 최대치 비용 최대치이면
* 성능을 2e9까지 올릴 수 있다.
* bs로 가진 비용으로 최대치 낮은 성능이 되는 컴퓨터를 찾으면 된다
* 이때 비용을 계산할 때 가진 비용보다 커져버리면 바로 멈추자
* 그렇지않으면 overflow 발생
*/

int N; //컴퓨터 수
long long totcost; //성능 향상 비용
vector<long long>com; //컴퓨터 벡터


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