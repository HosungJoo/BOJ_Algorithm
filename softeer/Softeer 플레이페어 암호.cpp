#include<iostream>
#include<queue>
#include<string>

using namespace std;

/*
* 정직하게 구현하면됨
* J는 I로 바꾸고
* 알파벳 사용여부는 DAT로 확인한다.
* key와 DAT를 활용하여 5X5 판을 생성한다.
* queue 2개를 활용해 중복문자 규칙을 해결한다.
* 중복문자 해결로 만든 최종메세지 큐를 두 개씩 pop해
* 비교하며 우선순위 규칙에 맞춰주면 만들어진다.
*/

string message;
string key;
char map[5][5];
bool dat[26];
string ans;

int main(int argc, char** argv)
{
    cin >> message >> key;

    //key만들기

    int key_len = 0;
    int key_maxlen = key.length();

    //J인지 확인
    for (int i = 0; i < key_maxlen; i++) {
        if (key[i] == 'J') {
            key[i] = 'I';
        }
    }
    //J 신경 안쓰게 미리 체크
    dat['J' - 'A'] = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (key_len < key_maxlen) { // key확인
                char word = key[key_len];

                //dat확인
                if (!dat[word - 'A']) {
                    map[i][j] = word;

                    dat[word - 'A'] = 1;
                }
                else { //했으면 다음 문자로 넘어감
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
                    if (word == '\0') { //인덱스 넘어서 공백을 인덱싱하면
                        for (int k = 0; k < 26; k++) {
                            if (!dat[k]) {
                                map[i][j] = 'A' + k;
                                dat[k] = 1;
                                break;
                            }
                        }
                    }
                }
                key_len++; //다음 문자 확인하러 감
            }
            else { //남은 알파벳 활용
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

    //message 만들기
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
            //쌍 생기는 거 확인
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

    //찾기
    int pos[2][2] = {};
    while (!res_q.empty()) {
        char fir = res_q.front();
        res_q.pop();
        char sec = res_q.front();
        res_q.pop();

        int cnt = 0;
        //위치 찾기
        for (int i = 0; i < 5; i++) {
            if (cnt == 2) break;
            for (int j = 0; j < 5; j++) {
                if (cnt == 2) break;
                if (fir == map[i][j]) {
                    pos[0][0] = i; //첫문자 x좌표
                    pos[0][1] = j; //첫문자 y좌표
                    cnt++;
                }
                if (sec == map[i][j]) {
                    pos[1][0] = i; //두 번째 문자 x좌표
                    pos[1][1] = j; //두 번째 문자 y좌표
                    cnt++;
                }
            }
        }
        //우선 순위 규칙
        if (pos[0][0] == pos[1][0]) {//행이 같으면
            int fir_col = (pos[0][1] + 1) % 5;
            int sec_col = (pos[1][1] + 1) % 5;

            ans.push_back(map[pos[0][0]][fir_col]);
            ans.push_back(map[pos[1][0]][sec_col]);
        }
        else if (pos[0][1] == pos[1][1]) {//열이 같으 면
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