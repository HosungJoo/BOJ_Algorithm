#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int>num;
vector<int>tmp;


int bs(int start, int end, int tar) {
	int mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		if (tmp[mid] == tar) {
			return mid;
		}
		else if (tmp[mid] > tar) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		num.push_back(number);
		tmp.push_back(number);
	}

	sort(tmp.begin(), tmp.end());

	//vector에서 중복인 수를 지우는 방법
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());


	for (int i = 0; i < N; i++) {
		int ans = bs(0, tmp.size()-1, num[i]);
		cout << ans << " ";
	}
	
	return 0;
}