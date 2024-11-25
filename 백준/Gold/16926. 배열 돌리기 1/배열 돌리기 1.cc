#include<iostream>
#include<algorithm>

using namespace std;

int N, M, R;
int map[301][301];

int main()
{
    cin >> N >> M >> R;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> map[i][j];
        }
    }

    int dep = min(N, M) / 2;
    
    for (int i = 0; i < R; ++i) {

        for (int j = 1; j <= dep; ++j) {

            int node = map[j][j];
            int max_col = M - j + 1;
            int max_row = N - j + 1;

            //상단
            for (int col = j + 1; col <= max_col; ++col) {
                map[j][col - 1] = map[j][col];
            }

            //우측
            for (int row = j + 1; row <= max_row; ++row) {
                map[row - 1][max_col] = map[row][max_col];
            }

            //하단
            for (int col = max_col; col >= j + 1; --col) {
                map[max_row][col] = map[max_row][col - 1];
            }

            //좌측
            for (int row = max_row; row >= j + 2; --row) {
                map[row][j] = map[row - 1][j];
            }

            map[j + 1][j] = node;
            
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}