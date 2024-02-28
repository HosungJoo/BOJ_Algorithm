#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int T;
int N;
int operators[4]; //0:'+',1:'-',2:'*',3:'/'
int maX=-2134567890;
int miN = 2134567890;
vector<int>number;

void init() {
    memset(operators, 0, sizeof(operators));
    number.clear();
    maX = -2134567890;
    miN = 2134567890;
}

void input() {

    cin >> N;

    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        number.push_back(num);
    }
}

void recur(int level,int sum) {
    if (level == N) {
        maX = max(sum, maX);
        miN = min(sum, miN);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (operators[i] == 0) continue;
        
        operators[i]--;

        if (i == 0) recur(level + 1, sum + number[level]);
        else if (i == 1) recur(level + 1, sum - number[level]);
        else if (i == 2) recur(level + 1, sum * number[level]);
        else recur(level + 1, sum / number[level]);

        operators[i]++;
    }
}

void solve() {
    recur(1,number[0]);
}

int main() {

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        init();
        input();
        solve();

        cout << "#" << tc << " " << maX - miN << "\n";
    }
  
   
    return 0;
}