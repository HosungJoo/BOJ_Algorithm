#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>

using namespace std;

int main() {

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>>pq;

    for (int i = 0; i < N; i++) {
        int order;
        scanf("%d", &order);
        if (order == 0) {
            if (pq.empty())
                printf("0\n");
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else {
            pq.push(order);
        }
    }

    return 0;
}