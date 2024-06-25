#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

/*
* ó���� pq�� ���������� �������ǿ���
* ������ ���� �ð��� ���������� �ԷµǹǷ� queue�� �ص� �������
* queue 4���� �̿��Ͽ� �����Ѵ�.
* ���� �ð� �ȿ� ��� �����ο� ������ �������¿� ������ ���� Ȯ���Ѵ�
* empty�� Ȱ���� �ܻ����� �ƴ� ���� Ȯ���Ѵ�.
* �ܻ��� �ƴ϶�� ������ �����θ� Ȯ���ϰ�
* ������ �������� ���� ���� �ð����� �� �ð��� ������
* �׳� �������� �ȴ�.
*/

int N;
queue<pair<int, int>>q[4];
//0:A => 3:D, 1:B => 0:A, 2:C => 1:B, 3:D => 2:C
int t_A; int t_B; int t_C; int t_D;
int ia, ib, ic, id;
int ans[200000];

int main(int argc, char** argv)
{
    cin >> N;

    int cur_t = 0;

    for (int i = 0; i < 200000; i++) {
        ans[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        int t;
        char cross;
        cin >> t >> cross;

        if (i == 0)
            cur_t = t;

        q[cross - 'A'].push({ i,t });//�������ǿ� ���� ������ �˾Ƽ� ������������ push
    }

    while (1) {
        if (q[0].empty() && q[1].empty() && q[2].empty() && q[3].empty())
            break;//���� ���� ����

        t_A = 21e8; t_B = 21e8; t_C = 21e8; t_D = 21e8;

        if (!q[0].empty()) {
            ia = q[0].front().first;
            t_A = q[0].front().second;
        }

        if (!q[1].empty()) {
            ib = q[1].front().first;
            t_B = q[1].front().second;
        }

        if (!q[2].empty()) {
            ic = q[2].front().first;
            t_C = q[2].front().second;
        }

        if (!q[3].empty()) {
            id = q[3].front().first;
            t_D = q[3].front().second;
        }

        int min_t = min(t_A, min(t_B, min(t_C, t_D)));
        if (cur_t < min_t) {
            cur_t = min_t;
        }

        bool onpath_A = !q[0].empty();
        bool onpath_B = !q[1].empty();
        bool onpath_C = !q[2].empty();
        bool onpath_D = !q[3].empty();

        if (onpath_A && onpath_B && onpath_C && onpath_D) { //��������
            if (t_A <= cur_t && t_B <= cur_t && t_C <= cur_t && t_D <= cur_t) {
                break;
            }
        }

        if (onpath_A && (t_A <= cur_t)) {//���� �غ�
            if (!onpath_D) {
                ans[ia] = cur_t;
                q[0].pop();
            }
            else {
                if (t_D > cur_t) {
                    ans[ia] = cur_t;
                    q[0].pop();
                }
            }
        }

        if (onpath_B && (t_B <= cur_t)) {//���� �غ�
            if (!onpath_A) {
                ans[ib] = cur_t;
                q[1].pop();
            }
            else {
                if (t_A > cur_t) {
                    ans[ib] = cur_t;
                    q[1].pop();
                }
            }
        }

        if (onpath_C && (t_C <= cur_t)) {//���� �غ�
            if (!onpath_B) {
                ans[ic] = cur_t;
                q[2].pop();
            }
            else {
                if (t_B > cur_t) {
                    ans[ic] = cur_t;
                    q[2].pop();
                }
            }
        }

        if (onpath_D && (t_D <= cur_t)) {//���� �غ�
            if (!onpath_C) {
                ans[id] = cur_t;
                q[3].pop();
            }
            else {
                if (t_C > cur_t) {
                    ans[id] = cur_t;
                    q[3].pop();
                }
            }
        }

        cur_t++;
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << "\n";
    }



    return 0;
}