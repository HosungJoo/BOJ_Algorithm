#include <iostream>

using namespace std;


int main() {

	int X;
	int stick = 64;
	int sum = 0;
	int cnt = 0;

	cin >> X;

	if (stick != X) {
		while (sum!=X) {
			stick >>= 1;
			
			if (stick + sum <= X) {
				sum += stick;
				cnt++;
			}
		}
	}
	else {
		cnt = 1;
	}

	cout << cnt;

	return 0;
}