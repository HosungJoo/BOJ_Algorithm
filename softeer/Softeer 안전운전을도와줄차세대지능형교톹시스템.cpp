#include<iostream>
#include<vector>

using namespace std;

/*
* �ϵ� �ڵ��� �����ؾ��Ѵ�
* 12���� ��ȣ�� ���� 3���� ��ȣ�� ���� �迭 �ε����� ��ġ��Ų��.
* �����θ� 2������ 1�������� ��ȯ�� ���ͷ� 3���� ��ȣ�� �޴´�.
* ��ȣ�� �ֵ����� ������ %�� Ȯ���Ͽ� ���Թ���� ��ȣ�� ���� ������ �ٷ� ���Ͻ�Ų��
* ���Ĵ� dfs�̴�
*/

int N, T;
int visited[100][100];
vector<int> cross[10000]; //������ ��ȣ ����
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
//0:�� 1:�� 2:�� 3:�� 4:����

int sign[12][3] = { {1,0,3},{2,1,0},{1,2,3},{2,3,0},
                 {1,0,4},{2,1,4},{2,3,4},{3,0,4},
                 {0,3,4},{1,0,4},{1,2,4},{2,3,4} };

void dfs(int level, int x, int y, int dir) {
    if (level == T) {
        return;
    }
    int stdir = cross[N * x + y][level % 4];
    if (dir != stdir % 4) return; //��ȣ�� ���� ������ ����
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[sign[stdir][i]];
        int ny = y + dy[sign[stdir][i]];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

        visited[nx][ny] = 1;

        dfs(level + 1, nx, ny, sign[cross[N * x + y][level % 4]][i]);
    }
}

int main() {

    cin >> N >> T;

    for (int i = 0; i < N * N; i++) {
        for (int j = 0; j < 4; j++) {
            int sigs;
            cin >> sigs;
            cross[i].push_back(sigs - 1);
        }
    }

    visited[0][0] = 1;
    dfs(0, 0, 0, 1);

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 1) ans++;
        }
    }

    cout << ans;

    return 0;
}