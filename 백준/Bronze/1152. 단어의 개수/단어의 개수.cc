#include<iostream>
#include<string>

using namespace std;

string str;

int main(int argc, char** argv)
{

    getline(cin, str);

    int cnt = 1;
    
    if (str.length() == 1) {
        if (str[0] == ' ') {
            cnt = 0;
        }
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            if (i != 0 && i != str.length() - 1) {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}