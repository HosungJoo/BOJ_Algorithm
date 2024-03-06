#include <iostream>
#include <cmath>

using namespace std;

int K, C;

int main() {

    cin >> K >> C;

    for (int i = 0; i < C; i++) {
        int M, N;
        cin >> M >> N;

        int dist = abs(M - N);

        if (dist == 0) cout << 1 << "\n";
        else {
            if (dist > K / 2 + 1) {
                cout << 0 << "\n";
            }
            else if (dist == K / 2 + 1) {
                if (K % 2 == 0) {
                    if (N >= K / 2 + 1) cout << 0 << "\n";
                    else cout << 1 << "\n";
                }
                else {
                    if (N > K / 2 + 1) cout << 0 << "\n";
                    else cout << 1 << "\n";
                }
            }
            else cout << 1 << "\n";
        }

        
    }

    return 0;
}


