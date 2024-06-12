#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    //초기값
    dp[0][0] = triangle[0][0];
    //층
    int layer = triangle.size();
    
    //dp table 만들기
    for(int i=1;i<layer;i++){
        for(int j=0;j<triangle[i].size();j++){
            
            if(j==0){ //맨 왼쪽일 경우
               dp[i][j] = dp[i-1][0] + triangle[i][j];
            }
            else if(j==triangle[i].size()-1){ //맨 오른쪽일 경우
                dp[i][j] = dp[i-1][triangle[i-1].size()-1] + triangle[i][j];
            }
            else{//나머지 상황
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            }
            
            //최댓값 갱신
            answer = max(answer,dp[i][j]);
        }
    }
    
    return answer;
}