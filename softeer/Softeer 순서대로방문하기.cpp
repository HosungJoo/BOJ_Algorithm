#include<iostream>
#include<vector>

using namespace std;

/*
* n�� 4�� �ִ��̹Ƿ� DFS�� �������� ���� ����
* ������ǥ�� visited�� �̿��� �Ѿ�� ���� ��ǥ�� �����ϸ�
* dfs�� ���� ��ǥ�� ���ϵ��� �ٽ� ȣ���Ѵ�.
* ������ ��ǥ�� ������ ������ ī��Ʈ�ϸ� ���� �ٸ� ����� ���� ���´�.
*/

struct spot {
    int x;
    int y;
};

int n; //���� ũ��
int m; //�湮���� ����
int ans;
int map[4][4];
bool visited[4][4];
vector<spot> v;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int x, int y, int level) {
    if (x == v[level + 1].x && y == v[level + 1].y) { //���� ��ǥ�� ���� üũ
        if (level + 1 == m - 1) { //������ �湮 ������ Ȯ��
            ans++;
            return;
        }
        dfs(x, y, level + 1); // ����������
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (map[nx][ny] == 1) continue;
        if (visited[nx][ny] == 1) continue;

        visited[nx][ny] = 1;
        dfs(nx, ny, level);
        visited[nx][ny] = 0;

    }
}

int main(int argc, char** argv)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x - 1,y - 1 });
    }

    visited[v[0].x][v[0].y] = 1;
    dfs(v[0].x, v[0].y, 0);

    cout << ans;

    return 0;
}