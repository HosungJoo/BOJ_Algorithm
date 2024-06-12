#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int>pq1; //큰놈 위에
priority_queue<int,vector<int>,greater<>>pq2; //작은 놈 위에

vector<int> solution(vector<string> operations) {
    
    //명령어 수
    int cmds = operations.size();
    int push_cnt = 0;
    
    //명령어 확인
    for(int i=0;i<cmds;i++){
        //명령어 받기
        string order = operations[i];
        int num = stoi(order.substr(2,order.length()));
        
        //cout<<order<<endl;
        //cout<<num<<endl;
        
        //파싱
        if(order[0]=='I'){
            pq1.push(num);
            pq2.push(num);
            push_cnt++;
        }
        else if(order[0]=='D'){//D
            
            if(num==1){
                if(!pq1.empty()){
                    pq1.pop();
                     push_cnt--;
                }
            }
            else{
                if(!pq2.empty()){
                    pq2.pop();
                    push_cnt--;
                }
            }
            if(push_cnt==0 && !pq1.empty()&&!pq2.empty()){
                while(!pq1.empty()){
                    pq1.pop();
                }
                 while(!pq2.empty()){
                    pq2.pop();
                }
            }
        } 
    }
    
    vector<int> answer;
    
    if(push_cnt<=0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(pq1.top());
        answer.push_back(pq2.top());
    }
    
    return answer;
}