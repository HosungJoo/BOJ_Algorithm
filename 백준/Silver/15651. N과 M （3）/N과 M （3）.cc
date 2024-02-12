#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int N, M;
bool dat[9];
vector<int> num;
//오름차순 순열
void recur(int node) {
	if (node == M+1) {
		for (int i = 0; i < num.size(); i++) cout << num[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		num.push_back(i);
		recur(node + 1);
		num.pop_back();
	}
}

int main() {

	cin >> N >> M;
	
	recur(1);

	return 0;
}