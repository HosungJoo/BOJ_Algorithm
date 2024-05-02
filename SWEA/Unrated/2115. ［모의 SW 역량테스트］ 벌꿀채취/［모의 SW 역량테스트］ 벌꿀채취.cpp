#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, max_bottle, each_max_content;
int map[10][10];
int visited[10][10];
int max_benefit;
int bee_bnf[2];
int max_bnf0;
int max_bnf1;
vector<int>bee[2];

void init() {
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	max_bnf0 = 0;
	max_bnf1 = 0;
	for (int i = 0; i < 2; i++) {
		bee[i].clear();
	}
	max_benefit = 0;
}

void input() {
	cin >> N >> max_bottle>> each_max_content;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}

void harv_honey(int num,int idx,int cont) {
	if (idx == max_bottle) {
		if (num == 0) {
			max_bnf0 = max(max_bnf0, bee_bnf[num]);
		}
		else {
			max_bnf1 = max(max_bnf1, bee_bnf[num]);
		}
		return;
	}
	for (int i = idx; i < max_bottle; i++) {
		int tmp_cont = bee[num][i];

		if (cont + tmp_cont <= each_max_content) {
			bee_bnf[num] += (tmp_cont * tmp_cont);
			harv_honey(num, i + 1, cont + tmp_cont);
			bee_bnf[num] -= (tmp_cont * tmp_cont);
		}
		else {
			harv_honey(num, i + 1, cont);
		}
	}
}


void dfs(int lv,int ii,int jj) {
	if (lv == 2) {

		for (int i = 0; i < 2; i++) bee_bnf[i] = 0;
		max_bnf0 = 0;
		max_bnf1 = 0;
		for (int i = 0; i < lv; i++) {	
			harv_honey(i, 0, 0);
		}

		max_benefit = max(max_benefit, max_bnf0 + max_bnf1);

		return;
	}
	for (int i = ii; i < N; i++) {
		for (int j = jj; j < N; j++) {
			
			if (j + max_bottle <= N) {
				//범위 내로 채취할 수 있다면
				int pos_harv = 1;
				for (int k = j; k < j + max_bottle; k++) {
					if (visited[i][k] == 1) {
						pos_harv = 0;
						if(bee[lv].size()>0){
							bee[lv].clear();
							//복구
							for (int u = j; u <= k; u++) visited[i][u] = 0;
						}
						break;
					}
					visited[i][k] = 1;
					bee[lv].push_back(map[i][k]);
				}
				if (pos_harv) {
					dfs(lv + 1,i,j+max_bottle);
					for (int u = j; u < j + max_bottle; u++) visited[i][u] = 0;
					bee[lv].clear();
				}
			}
			else break;
		}
		jj = 0;
	}
}

void solve() {
	dfs(0,0,0);
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();

		cout << "#" << tc << " " <<max_benefit<< "\n";
	}

	return 0;
}