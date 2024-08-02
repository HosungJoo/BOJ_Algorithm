#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

//set을 쓰는 게 중요함

int U,B;
int visited[8];
vector<int> log;
set<vector<int>>id_arr;

void dfs(int lv,vector<string>user_id,vector<string>banned_id){
    if(lv==B){
        vector<int>res;
        for(int i=0;i<log.size();i++) res.push_back(log[i]);
        sort(res.begin(),res.end());
        id_arr.insert(res);
        return;
    }
    for(int i=0;i<U;i++){
        if(visited[i]==1) continue;
        
        string u = user_id[i];
        string b = banned_id[lv];
        
        if(u.size()!=b.size()) continue;
        bool matching = true;
        for(int j=0;j<b.size();j++){
            if(b[j]=='*') continue;
            if(b[j]!=u[j]){
                matching = false;
                break;
            }
        }
        if(matching){
            visited[i]=1;
            log.push_back(i);
            dfs(lv+1,user_id,banned_id);
            visited[i]=0;
            log.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
   
    int answer = 0;
    
    U = user_id.size();
    B = banned_id.size();
    
    dfs(0,user_id,banned_id);
    
    answer = id_arr.size();
    
    return answer;
}
