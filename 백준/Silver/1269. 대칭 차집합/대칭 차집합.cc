#include<iostream>
#include<map>

using namespace std;

int a, b;
map<int, int>A, B;

int main()
{
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		int el;
		cin >> el;
		A[el] = el;
	}

	for (int i = 0; i < b; i++) {
		int el;
		cin >> el;
		B[el] = el;
	}

	int same_el = 0;

	if (a >= b) {
		for (auto iter = B.begin(); iter != B.end(); iter++) {
			if (A.count(iter->second) == 1) {
				same_el++;
			}
		}
	}
	else {
		for (auto iter = A.begin(); iter != A.end(); iter++) {
			if (B.count(iter->second) == 1) {
				same_el++;
			}
		}
	}

	int only_A = 0;
	int only_B = 0;

	if (a - same_el > 0) only_A = (a - same_el);
	if (b - same_el > 0) only_B = (b - same_el);

	cout << only_A + only_B;


	return 0;
}