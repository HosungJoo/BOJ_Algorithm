#include<iostream>
#include<string>

using namespace std;

int N;

int main(int argc, char** argv)
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		string S;
		string T;
		cin >> S >> T;

		int tar_idx = 0;

		for (int j = 0; j < S.length(); j++) {
			if (S[j] == 'x' || S[j] == 'X') {
				tar_idx = j;
				break;
			}
		}


		char ans = T[tar_idx];

		if (ans >= '0'&&ans <= '9') {//숫자인지
			cout << ans;
		}
		else if (ans >= 'a'&&ans <= 'z') {//소문자인지
			cout << (char)('A' + ans - 'a');
		}
		else {
			cout << ans;
		}

	}

	return 0;
}