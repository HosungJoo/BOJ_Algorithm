//모든 "장르별"로 최대 2곡씩이라는 말이 제대로 안나타나서 실수함 
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct info{
    int plays;
    int p_idx;
    bool operator<(info right) const{
        if(plays>right.plays) return false;
        else if(plays<right.plays) return true;
        else {
            if(p_idx<right.p_idx)return false;
            else if(p_idx>right.p_idx) return true;
            else return false;
        }
    }
};

unordered_map<string,int> cal_gen;
unordered_map<string,int> idx_gen;
priority_queue<info>pq[100];

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int idx = 0;
    for(int i=0;i<genres.size();i++){
        //장르당 재생횟수 계산 및 인덱스 부여
        if(cal_gen.count(genres[i])==0){
            cal_gen[genres[i]] = plays[i];
            idx_gen[genres[i]]=idx;
            idx++;
        }
        else{
            cal_gen[genres[i]] += plays[i];
        }
        //장르 내부 노래 횟수 우선순위 저장
        pq[idx_gen[genres[i]]].push({plays[i],i});
    }
    
    //순회하면서 pq에 넣기
    priority_queue<pair<int,string>>rank_pq;
    
    for(auto el:cal_gen){
        rank_pq.push({el.second,el.first});
    }
    
    for(int i=0;i<idx;i++){
        if(rank_pq.empty()) break;
        pair<int,string>now = rank_pq.top();
        rank_pq.pop();
        answer.push_back(pq[idx_gen[now.second]].top().p_idx);
        pq[idx_gen[now.second]].pop();
        if(!pq[idx_gen[now.second]].empty()){
            answer.push_back(pq[idx_gen[now.second]].top().p_idx);
        }
    }
    
    
    return answer;
}
