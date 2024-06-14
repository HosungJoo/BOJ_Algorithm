#include <string>
#include <vector>
#include <queue>

using namespace std;

//우선순위 큐인지 몰랐음 질문하기에서 우선순위 큐라는 제목보고 바로 깨달음

priority_queue<int>pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    for(int i=0;i<works.size();i++){
        pq.push(works[i]);
    }
    
    while(n!=0){
        if(pq.empty()) break;
        int now = pq.top();
        pq.pop();
        
        now--;
        n--;
        
        if(now!=0){
            pq.push(now);
        }
    }
    
    while(!pq.empty()){
        int part = pq.top();
        pq.pop();
        answer += part*part;
    }
    
    
    return answer;
}