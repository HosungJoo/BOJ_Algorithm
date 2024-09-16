#include<iostream>
#include<string>
#include<stack>

using namespace std;

string container;
string ans;
stack<char>st;

int main(int argc, char** argv)
{
	cin >> container;

	int len = container.length();

	//조건에 균형잡힌 문자열을 무조건 입력으로 온다는 보장이 있음

	for (int i = 0; i < len; ++i) {
		char el = container[i];

		if (st.empty()) { //초기에는 ( 가 확정으로 들어오므로 push후 정답배열에 추가
			st.push(el);
			ans += el;
		}
		else {
			if (el == '(') { // (가 들어오면 쌓기
				st.push(el);
				ans += el;
			}
			else { // ) 가 들어오면 기본으로 1을 넣고 괄호를 닫음 +로 잇는 것을 판단
				ans += '1';
				ans += el;
				st.pop();
				if (i != len - 1) { //마지막이면 이을 필요가 없으므로 + 안함
					ans += '+';
				}
			}
		}
	}

	cout << ans;


	return 0;
}