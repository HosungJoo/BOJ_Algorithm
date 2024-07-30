#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string>sset;

int main() {

	string str;
	cin >> str;

	int len = str.length();
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j <= len - i; j++) {
			sset.insert(str.substr(j, i));
		}
	}

	cout << sset.size();

	return 0;
}