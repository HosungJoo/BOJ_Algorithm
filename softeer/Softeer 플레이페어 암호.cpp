#include<iostream>
#include<queue>
#include<string>

using namespace std;

/*
* �����ϰ� �����ϸ��
* J�� I�� �ٲٰ�
* ���ĺ� ��뿩�δ� DAT�� Ȯ���Ѵ�.
* key�� DAT�� Ȱ���Ͽ� 5X5 ���� �����Ѵ�.
* queue 2���� Ȱ���� �ߺ����� ��Ģ�� �ذ��Ѵ�.
* �ߺ����� �ذ�� ���� �����޼��� ť�� �� ���� pop��
* ���ϸ� �켱���� ��Ģ�� �����ָ� ���������.
*/

string message;
string key;
char map[5][5];
bool dat[26];
string ans;

int main(int argc, char** argv)
{
    cin >> message >> key;

    //key�����

    int key_len = 0;
    int key_maxlen = key.length();

    //J���� Ȯ��
    for (int i = 0; i < key_maxlen; i++) {
        if (key[i] == 'J') {
            key[i] = 'I';
        }
    }
    //J �Ű� �Ⱦ��� �̸� üũ
    dat['J' - 'A'] = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (key_len < key_maxlen) { // keyȮ��
                char word = key[key_len];

                //datȮ��
                if (!dat[word - 'A']) {
                    map[i][j] = word;

                    dat[word - 'A'] = 1;
                }
                else { //������ ���� ���ڷ� �Ѿ
                    while (key_len < key_maxlen) {
                        key_len++;
                        word = key[key_len];

                        if (word == '\0') break;
                        if (!dat[word - 'A']) {
                            map[i][j] = word;
                            dat[word - 'A'] = 1;

                            break;
                        }
                    }
                    if (word == '\0') { //�ε��� �Ѿ ������ �ε����ϸ�
                        for (int k = 0; k < 26; k++) {
                            if (!dat[k]) {
                                map[i][j] = 'A' + k;
                                dat[k] = 1;
                                break;
                            }
                        }
                    }
                }
                key_len++; //���� ���� Ȯ���Ϸ� ��
            }
            else { //���� ���ĺ� Ȱ��
                for (int k = 0; k < 26; k++) {
                    if (!dat[k]) {

                        map[i][j] = 'A' + k;
                        dat[k] = 1;

                        break;
                    }
                }
            }
        }
    }

    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    //message �����
    queue<char>mes_q;
    queue<char>res_q;

    for (int i = 0; i < message.length(); i++) {
        mes_q.push(message[i]);
    }


    while (!mes_q.empty()) {
        char now = mes_q.front();
        mes_q.pop();
        res_q.push(now);

        if (!mes_q.empty()) {
            char next = mes_q.front();
            //�� ����� �� Ȯ��
            if (next == now) {
                if (now == 'X') {
                    res_q.push('Q');
                }
                else {
                    res_q.push('X');
                }
            }
            else {
                res_q.push(next);
                mes_q.pop();
            }
        }
        else {
            res_q.push('X');
        }
    }

    // while(!res_q.empty()){
    //     cout<<res_q.front()<<"\n";
    //     res_q.pop();
    // }

    //ã��
    int pos[2][2] = {};
    while (!res_q.empty()) {
        char fir = res_q.front();
        res_q.pop();
        char sec = res_q.front();
        res_q.pop();

        int cnt = 0;
        //��ġ ã��
        for (int i = 0; i < 5; i++) {
            if (cnt == 2) break;
            for (int j = 0; j < 5; j++) {
                if (cnt == 2) break;
                if (fir == map[i][j]) {
                    pos[0][0] = i; //ù���� x��ǥ
                    pos[0][1] = j; //ù���� y��ǥ
                    cnt++;
                }
                if (sec == map[i][j]) {
                    pos[1][0] = i; //�� ��° ���� x��ǥ
                    pos[1][1] = j; //�� ��° ���� y��ǥ
                    cnt++;
                }
            }
        }
        //�켱 ���� ��Ģ
        if (pos[0][0] == pos[1][0]) {//���� ������
            int fir_col = (pos[0][1] + 1) % 5;
            int sec_col = (pos[1][1] + 1) % 5;

            ans.push_back(map[pos[0][0]][fir_col]);
            ans.push_back(map[pos[1][0]][sec_col]);
        }
        else if (pos[0][1] == pos[1][1]) {//���� ���� ��
            int fir_row = (pos[0][0] + 1) % 5;
            int sec_row = (pos[1][0] + 1) % 5;

            ans.push_back(map[fir_row][pos[0][1]]);
            ans.push_back(map[sec_row][pos[1][1]]);
        }
        else {
            int fir_col = pos[0][1];
            int sec_col = pos[1][1];

            ans.push_back(map[pos[0][0]][sec_col]);
            ans.push_back(map[pos[1][0]][fir_col]);
        }
    }

    cout << ans;

    return 0;
}