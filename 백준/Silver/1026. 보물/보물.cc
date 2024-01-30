#include <iostream>
#include<algorithm>

using namespace std;

int N;
int A[51];
int B[51];
int ans;

bool cmp1(int a, int b){
	return a < b;
}

bool cmp2(int a, int b) {
	return a > b;
}

int main(){

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	stable_sort(A, A + N, cmp1);
	stable_sort(B, B + N, cmp2);
	

	for (int i = 0; i < N; i++)
	{
		ans += A[i] * B[i];
	}

	cout << ans;

	return 0;
}