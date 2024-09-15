#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>lf,vector<int>rg){
    return lf[1]<rg[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(),targets.end(),cmp);
    
    int start = targets[0][0];
    int ends = targets[0][1];
    int ans = 1;
    
    for(int i=0;i<targets.size();i++){    
        if(ends<=targets[i][0]){
            ans++;
            start=targets[i][0];
            ends = targets[i][1];
        }
    }
    
    answer = ans;
    
    return answer;
}