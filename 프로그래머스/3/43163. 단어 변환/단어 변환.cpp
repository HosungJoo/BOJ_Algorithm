#include <string>
#include <vector>
#include <queue>

using namespace std;

struct info{
    string w;
    int idx;
};

int visited[51];
int bans;

void bfs(string bw, string tw, vector<string>words){
    queue<info>q;
    
    bool bw_in_words = false;
    for(int i=0;i<words.size();i++){
        if(words[i]==bw){
            bw_in_words = true;
            q.push({bw,i});
            visited[i] = 1;
            break;
        }
    }
    if(!bw_in_words){
        q.push({bw,50});
        visited[50]=1;
    }
    
    int len = bw.length();
    
    while(!q.empty()){
        info now = q.front();
        q.pop();
        
        if(now.w==tw){
            bans = visited[now.idx]-1;
            return;
        }
        
        for(int i=0;i<words.size();i++){
            string next = words[i];
            
            if(visited[i]!=0) continue;
            
            //한 단어 차이 나는 지 확인
            int diff = 0;
            
            for(int j=0;j<len;j++){
                if(now.w[j]!=next[j]){
                    diff++;
                }
            }
            
            if(diff==1){
                q.push({next,i});
                visited[i]=visited[now.idx]+1;
            }
        }
        
    }
    
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    bfs(begin, target, words);
    
    answer = bans;
    
    return answer;
}