#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
* 중앙값으로 원하는 연비의 인덱스를 찾아서
* 자신을 제외한 앞쪽과 뒤쪽을 곱하여 가짓수를 찾아야한다
* 주어지는 입력이 매우크므로 BS로 인덱스를 찾기로했다
* 
* ---------------------------------------------------
* BS를 다양한 포맷으로 구현해가며 나만의 방법을 찾는 것이 중요하다
* BS만들다가 시간 내에 풀지 못했다
*/

int n; //자동차 총개수
int q; //질의 개수
vector<int> v;

int main(int argc, char** argv)
{
    cin >> n >> q;
    v.push_back(0);

    for (int i = 0; i < n; i++) {
        int good;
        cin >> good;
        v.push_back(good);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < q; i++) {
        int tar;
        cin >> tar;//원하는 중간값

        //이진 탐색
        int start = 1;
        int eNd = n;
        int mid = 0;

        while (start <= eNd) {
            mid = (start + eNd) / 2;
            if (v[mid] == tar) {
                break;
            }
            else if (v[mid] < tar) {
                start = mid + 1;
            }
            else {
                eNd = mid - 1;
            }
        }
        if (start > eNd) { //존재하지 않으면
            cout << 0 << "\n";
        }
        else { 
            int left = mid - 1;
            int right = n - mid;
            cout << right * left << "\n";
        }

    }

    return 0;
}