#include <iostream>
#include <queue>

using namespace std;


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	priority_queue<int>pq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;

		if (data == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else {
				cout << 0 << "\n";
			}
		}
		else {
			pq.push(data);
		}
	}

	return 0;
}