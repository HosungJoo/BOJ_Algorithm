#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int>vec[1001];
bool visited[1001];

void dfs(int node) {
    for (int i = 0; i<vec[node].size(); i++) {
        int next = vec[node][i];
        if (visited[next]) continue;
        visited[next] = 1;
        dfs(next);
    }
}

int main() {

    int cnt = 0;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        vec[from].push_back(to);
        vec[to].push_back(from);
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        cnt++;
        visited[i] = 1;
        dfs(i);
    }

    cout << cnt;
 
    return 0;
}