#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101];
int dp[101][101];
int dx[]={-1,0};
int dy[]={0,-1};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    int row = n;
    int col = m;
    
    for(int i=0;i<puddles.size();i++){
        int c = puddles[i][0];
        int r = puddles[i][1];
        map[r][c] = 1;
    }
    
    
    //시작점
    dp[1][1]=1;
    
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            
            //물 웅덩이
            if(map[i][j]==1) continue;
            int tmp = 0;
            
            for(int dir=0;dir<=1;dir++){
                int bx = i+dx[dir];
                int by = j+dy[dir];
                
                if(bx<1||by<1) continue;
                if(map[bx][by]==1) continue;
                
                tmp += dp[bx][by];
            }
            dp[i][j] = max(dp[i][j],tmp%1000000007);
        }
    }
    
    answer = dp[row][col];
    
    return answer;
}