#include<iostream>

using namespace std;

int main()
{
    int money;
    int cnt = 0;

    cin >> money;

    money = 1000 - money;


    while (money != 0) {
        if (money / 500 > 0) {
            cnt += (money / 500);
            money -= (money / 500) * 500;
        }
        else if (money / 100 > 0) {
            cnt += (money / 100);
            money -= (money / 100) * 100;
        }
        else if (money / 50 > 0) {
            cnt += (money / 50);
            money -= (money / 50) * 50;
        }
        else if (money / 10 > 0) {
            cnt += (money / 10);
            money -= (money / 10) * 10;
        }
        else if(money / 5 > 0)
        {
            cnt += (money / 5);
            money -= (money / 5) * 5;
        }
        else {
            cnt += money;
            money = 0;
        }
    }

    cout << cnt;
    
    return 0;
}