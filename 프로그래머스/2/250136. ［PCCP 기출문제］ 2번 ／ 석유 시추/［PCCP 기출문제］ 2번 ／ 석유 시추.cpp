#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct info{
  int x;
  int y;
};

int R,C;
int visited[500][500];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int col[500];


int solution(vector<vector<int>> land) {
    int answer = 0;
    
    R = land.size();
    C = land[0].size();
    
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            if(visited[i][j]>0) continue; //시추를 해서 이제는 확인 안해도됨
            if(land[i][j]){ //석유가 있다면 floodfill 진행
                queue<info>q;
                q.push({i,j});
                int colVisit[500]={0,};
                
                visited[i][j]=1;
                colVisit[j]=1;
                int area = 1;
                
                while(!q.empty()){
                    info now = q.front();
                    q.pop();
        
                    for(int dir=0;dir<4;++dir){
                        int nx = now.x+dx[dir];
                        int ny = now.y+dy[dir];
            
                        if(nx<0||ny<0||nx>=R||ny>=C) continue; //Out of Bound
                        if(land[nx][ny]==0) continue; //석유가 없으면 안감
                        if(visited[nx][ny]>0) continue; // 방문했으면 안감
                        
                        ++area; //영역 확장됨
                        
                        colVisit[ny]=1;
                        visited[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                for(int c=0;c<C;++c){
                if(colVisit[c]==1) col[c]+=area;
                }
            }
        }
    }
    
    for(int i=0;i<C;i++){
        if(answer<col[i]){
            answer = col[i];
        }
    }
    
    
    
    return answer;
}