#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int connecting[200];
int com_cnt;

void bfs(int com, int nets,vector<vector<int>> computers){
    queue<int>q;
    q.push(com);
    connecting[com]=nets;
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        
        for(int i=0;i<com_cnt;i++){
            int next = i;
            
            if(now==next) continue; //자기 자신을 push할 이유 없음
            if(computers[now][next]==0) continue;//연결고리 없음
            if(connecting[next]!=0) continue; //방문한 컴퓨터
            
            connecting[next]=nets;
            q.push(next);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    com_cnt = n;
    int nets = 0;
    
    for(int i=0;i<n;i++){
        if(connecting[i]==0){ //연결이 안됐으면 시작
            nets++;
            bfs(i,nets,computers);
        }
    }
    
    answer = nets;
    
    return answer;
}