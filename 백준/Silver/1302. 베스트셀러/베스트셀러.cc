#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int>books;

int main() {

	int cnt = 0;
	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		string str;
		cin >> str;

		books[str]++;
	}

	int max_sell = 0;
	string title;

	for (auto iter = books.begin(); iter != books.end(); iter++) {
		if (iter->second > max_sell) {
			max_sell = iter->second;
			title = iter->first;
		}
	}
	
	cout << title;

	return 0;
}