#include <iostream>
#include <cmath>

using namespace std;

int K, C;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K >> C;

    for (int i = 0; i < C; i++) {
        int M, N;
        cin >> M >> N;

        int dist = M - N;
        if (dist == 0) cout << 1 << "\n";
        else {
            if (dist > 0) {
                if (K - dist < M - 2) cout << 0 << "\n";
                else cout << 1 << "\n";
            }
            else if (dist < 0) {
                if (K + dist < N - 1) cout << 0 << "\n";
                else cout << 1 << "\n";
            }
        }
        
    }

    return 0;
}


