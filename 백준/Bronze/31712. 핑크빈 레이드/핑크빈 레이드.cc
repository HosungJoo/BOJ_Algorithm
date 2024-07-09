#include <iostream>


using namespace std;

struct info {
	int period;
	int damage;
};

int main() {

	info yoon, dalgoo, ponix;
	int pinkbean = 0;

	cin >> yoon.period >> yoon.damage;
	cin >> dalgoo.period >> dalgoo.damage;
	cin >> ponix.period >> ponix.damage;
	cin >> pinkbean;

	int tm = 0;
	while (pinkbean>0) {
		if (tm % yoon.period == 0) pinkbean -= yoon.damage;
		if (tm % dalgoo.period == 0) pinkbean -= dalgoo.damage;
		if (tm % ponix.period == 0) pinkbean -= ponix.damage;
		tm++;
	}

	cout << tm - 1;

	return 0;
}