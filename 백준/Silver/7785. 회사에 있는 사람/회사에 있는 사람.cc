#include <iostream>
#include <map>

using namespace std;

map<string, bool, greater<string>>gate;

int main() {
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string name, log;
		cin >> name >> log;
		if (log == "enter") {
			gate[name] = true;
		}
		else {
			gate[name] = false;
		}
	}

	for (auto data : gate) {
		if (data.second) {
			cout << data.first << "\n";
		}
	}

	return 0;
}