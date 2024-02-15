#include<iostream>
#include<vector>

using namespace std;

int N, M;
int parent[51];
vector<int>known;
vector<int>party[51];


int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void Union(int person1, int person2) {
	person1 = find(person1);
	person2 = find(person2);
	if (person1 == person2) return;
	parent[person1] = person2;
}

int main() {

	cin >> N >> M;

	int know;
	cin >> know;

	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < know; i++) {
		int num;
		cin >> num;
		known.push_back(num); //진실 그룹 만들기
	}

	for (int i = 0; i < M; i++) {
		int people;
		cin >> people;

		for (int j = 0; j < people; j++) {
			int member;
			cin >> member;
			party[i].push_back(member); //파티 그룹 생성
		}

		int person = party[i][0];

		for (int j = 0; j < party[i].size(); j++) { //파티 그룹 union, 모든 멤버가 마지막 멤버를 부모로 가짐
			Union(person, party[i][j]);
		}
	}

	int ans = 0;

	for (int i = 0; i < M; i++) {
		bool dontknow = 1;
		for (int j = 0; j < known.size(); j++) {
			if (find(party[i][0]) == find(known[j])) {
				dontknow = 0;
				break;
			}
		}
		if (dontknow) {
			ans++;
		}
	}

	
	cout << ans;


	return 0;
}