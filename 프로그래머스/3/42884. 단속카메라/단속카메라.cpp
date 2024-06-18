#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct location{
    int sc;
    int ec;
};

vector<pair<int,int>>rt;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    for(int i=0;i<routes.size();i++){
        rt.push_back({routes[i][0],routes[i][1]});
    }

    //진입 시점 기준으로 sorting
    sort(rt.begin(),rt.end());
    
    int cam = 0;
    location lo_cam = {-30001,-30001};
    
    for(int i=0;i<rt.size();i++){
        //카메라 설치 범위를 좁히다가 감당 못하면 카메라 새로 설치
        if(lo_cam.ec<rt[i].first){
            lo_cam.sc = rt[i].first;
            lo_cam.ec = rt[i].second;
            cam++;
        }
        else{
            if(lo_cam.sc<rt[i].first){
                lo_cam.sc = rt[i].first;
            }
            if(lo_cam.ec>rt[i].second){
                lo_cam.ec = rt[i].second;
            }
        }
    }
    
    answer = cam;
    
    return answer;
}
