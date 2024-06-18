#include <iostream>
#include <vector>
using namespace std;



int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int fwd = 1; //맨앞
    int tot_w = 1+2*w; //기지국 통신 영향 총 거리
    int ap = 0; //기지국 개수
    
    for(int i=0;i<stations.size();i++){
        
        int center = stations[i]; //기지국 건설 위치
        
        // 기지국 건설시 최 앞단과 기지국 건설 전 앞단의 연산을 통한 빈 공간
        int disconnect_space = center - w - fwd;
        
        if(disconnect_space<0){
            fwd = center + w + 1;
            continue;
        }
        
        //나머지가 있으면 1개 더 설치 아니면 필요한만큼 설치
        if(disconnect_space%tot_w!=0){
            ap += (disconnect_space/tot_w+1);
        }
        else{
            ap += (disconnect_space/tot_w);
        }
        
        fwd = center + w + 1;
    }
    
    //마지막 아파트까지 영향 확인
    if(stations[stations.size()-1]+w < n){
        int bwd = stations[stations.size()-1] + w;
        int remain = n - bwd;
        if(remain%tot_w!=0){
            ap+=(remain/tot_w+1);
        }
        else{
            ap+=(remain/tot_w);
        }
    }
   
    answer = ap;

    return answer;
}