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

	//���ǿ� �������� ���ڿ��� ������ �Է����� �´ٴ� ������ ����

	for (int i = 0; i < len; ++i) {
		char el = container[i];

		if (st.empty()) { //�ʱ⿡�� ( �� Ȯ������ �����Ƿ� push�� ����迭�� �߰�
			st.push(el);
			ans += el;
		}
		else {
			if (el == '(') { // (�� ������ �ױ�
				st.push(el);
				ans += el;
			}
			else { // ) �� ������ �⺻���� 1�� �ְ� ��ȣ�� ���� +�� �մ� ���� �Ǵ�
				ans += '1';
				ans += el;
				st.pop();
				if (i != len - 1) { //�������̸� ���� �ʿ䰡 �����Ƿ� + ����
					ans += '+';
				}
			}
		}
	}

	cout << ans;


	return 0;
}