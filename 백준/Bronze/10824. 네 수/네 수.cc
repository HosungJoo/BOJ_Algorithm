#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
    string a, b, c, d;
    long long first = 0;
    long long second = 0;

    cin >> a >> b >> c >> d;

    a = a + b;
    c = c + d;

    int alen = a.length();
    int clen = c.length();

    for (int i = 0; i <alen; i++) {
        first += ((a[i] - '0') * pow(10, alen-1-i));
    }

    for (int i = 0; i < clen; i++) {
        second += ((c[i] - '0') * pow(10, clen - 1 - i));
    }

    cout << first + second;

    return 0;
}