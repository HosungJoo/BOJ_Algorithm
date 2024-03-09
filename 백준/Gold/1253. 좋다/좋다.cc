#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long>good;
int visited[2000];

bool chk(int mid, long long sum) {
    return sum <= good[mid];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        good.push_back(num);
    }

    sort(good.begin(), good.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                int tmp = good[i] + good[j];
                //이진탐색
                int start = 0;
                int eNd = N - 1;
                int mid = 0;
                int idx = N;
                while (start <= eNd) {
                    mid = (start + eNd) / 2;
                    if (chk(mid, tmp)) {
                        eNd = mid - 1;
                        idx = min(mid, idx);
                    }
                    else {
                        start = mid + 1;
                    }
                }

                if (idx == N) continue; //존재X 다음으로
                if (good[idx] != tmp) continue; //찾았는데 작은 값이면 다음으로

                int correction = 0;
                if (visited[idx] >= 1) {
                    correction = visited[idx];
                    visited[idx]++;
                }

                for (int k = idx+correction; k < N; k++) {
                    if (good[idx] != good[k]) {
                        break;
                    }
                    else {
                        if (i == k || j == k) continue;
                        if (visited[k] == 0) {
                            visited[k] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i] >= 1) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}


