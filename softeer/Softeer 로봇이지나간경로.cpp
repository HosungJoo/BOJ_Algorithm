#include<iostream>
#include<vector>

using namespace std;

/*
* �������� ã�� �� �ٽ��̴�.
* �������� 4������ Ž���Ͽ� �� �� �ִ� ��ΰ� �ϳ��� ���� ���̴�.
* �������� ã������ �̸� �������� dfs�� �ϵ�
* ���� ��ȯ�� ���� ����� �ؾ��Ѵ�.
* ���� ������ �ð�������� ��Ҵ�
* ���� ������ȯ�� ������ ����
* �ѹ� ������ ��ȸ��
* ���� ������ ��ȸ���̴�
* dfs�� ���������� ���� Ž���ϸ鼭 #�� ������ ��ü ������ �ɶ� return�ǵ��� �ߴ�.
*/

int H, W;
char map[25][25];
int totshap;
//0:��, 1:��, 2:��, 3:��
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int visited[25][25];
char sdir[4] = { '^','>','v','<' };
vector<char>order;
int sx, sy;

void dfs(int x, int y, int dir, int cnt) {
    if (totshap == cnt) {
        return;
    }
    int turn = dir; //���� ��ȯ�� ����ߴ��� üũ
    while (1) {
        int nx = x + dx[dir % 4];
        int ny = y + dy[dir % 4];

        if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
            dir++;
            continue;
        }
        if (map[nx][ny] != '#') {
            dir++;
            continue;
        }
        if (visited[nx][ny] == 1) {
            dir++;
            continue;
        }

        int dnx = nx + dx[dir % 4];
        int dny = ny + dy[dir % 4];

        visited[nx][ny] = 1;
        visited[dnx][dny] = 1;

        if (dir - turn == 0) {
            order.push_back('A');
        }
        else if (dir - turn == 1) {
            order.push_back('R');
            order.push_back('A');
        }
        else if (dir - turn == 3) {
            order.push_back('L');
            order.push_back('A');
        }

        cnt += 2;
        dfs(dnx, dny, dir % 4, cnt);
        return;
    }
}

int main(int argc, char** argv)
{
    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        cin >> map[i];
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] == '#') totshap++;
        }
    }

    //������ ã��
    int face = 0;
    int shap = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] == '#') {
                shap = 0;
                for (int s = 0; s < 4; s++) {
                    int chkx = i + dx[s];
                    int chky = j + dy[s];

                    if (chkx < 0 || chky < 0 || chkx >= H || chky >= W) continue;
                    if (map[chkx][chky] == '#') {
                        face = s; //���� ����
                        shap++; //������ # ����
                    }
                }
                if (shap == 1) {
                    dfs(i, j, face, 1);
                    sx = i;
                    sy = j;
                    break;
                }
            }
        }
        if (shap == 1) break;
    }

    cout << sx + 1 << " " << sy + 1 << "\n";
    cout << sdir[face] << "\n";
    for (int i = 0; i < order.size(); i++) {
        cout << order[i];
    }

    return 0;
}