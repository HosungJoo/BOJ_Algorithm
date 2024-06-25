#include<iostream>
#include<queue>
#include<vector>

using namespace std;

/*
BFS�� �ϵ� ������ ���� ���� �ؼ� ���찡 ���� �ǹ̰� �ִ��� Ȯ�� ���״�
������ ���� �湮�迭 ���� map�� ħ����Ű�鼭 �湮ǥ���ߴ�
�߰��� �湮�迭 x,y�߸� �����Ŷ� ��� return���Ѿ� �������� �Ǵ����� ���� �ð��� ���� ��Ƹ���
���� ��ü�� �Ҹ��ѵ�
*/

struct info {
	int x;
	int y;
	char state;
};

int n, m;
char map[1002][1002];
int visited[1002][1002];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

info namw; //����
vector<info>ghost;

void bfs() {
	queue<info>q;

	//���� ���� �ֱ�
	for (int i = 0; i < ghost.size(); i++) {
		q.push(ghost[i]);
	}
	//���� �ֱ�
	q.push(namw);
	visited[namw.x][namw.y] = 1;

	while (!q.empty()) {
		info now = q.front();
		char state = now.state; //�������� ��������
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue; //out of bound
			if (state == 'N') { //������
				if (map[nx][ny] == '#') continue; //���̸� ����
				if (map[nx][ny] == 'G') continue; //������ ������ ����
				if (visited[nx][ny] == 1) continue;//�湮�� ���̸� �Ȱ�
				if (map[nx][ny] == 'D') { //���������� ��!
					cout << "Yes";
					return;
				}
				visited[nx][ny] = 1;
				q.push({ nx,ny,'N' });
			}
			else if (state == 'G') { //�����̶��
				if (map[nx][ny] == 'G') continue; //���� ��ħ
				map[nx][ny] = 'G'; //������ ��
				q.push({ nx,ny,'G' });
			}
		}
	}
	cout << "No";

}

int main(int argc, char** argv)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	//���� �ⱸ ���� ã��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'N') namw = { i,j,'N' };
			else if (map[i][j] == 'G') ghost.push_back({ i,j,'G' });
		}
	}

	bfs();

	return 0;
}