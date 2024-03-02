#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>


using namespace std;

struct cell {
    vector<pair<int,int>>info;
};

struct micro {
    int x;
    int y;
    int siZe;
    int dir;
};

int T;
int N, M, K; //N:셀의크기, M:격리시간, K:군집의 개수 
cell map[100][100];
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
vector<micro>microbe;
int ans;


void init() {
    memset(map, 0, sizeof(map));
    microbe.clear();
    ans = 0;
}

void input() {
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int x, y, siZe, dir;
        cin >> x >> y >> siZe >> dir;
        microbe.push_back({ x,y,siZe,dir });
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j].info.push_back({ 0,0 });
        }
    }
    
}

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}

void solve() {
    for (int i = 0; i < M; i++) { //M시간 동안 이동
        for (int j = 0; j < microbe.size(); j++) { //이동시작
            int nextX = microbe[j].x + dx[microbe[j].dir]; //다음 위치 X
            int nextY = microbe[j].y + dy[microbe[j].dir]; //다음 위치 Y
            int nextSize = microbe[j].siZe; //약품에 닿지 않으면 그대로
            int nextDir = microbe[j].dir; //약품에 닿지 않으면 그대로
           

            //약품에 닿을 경우
            if (nextX == 0 || nextY == 0 || nextX == N - 1 || nextY == N - 1) {
                nextSize /= 2; //무리가 반토막
                if (nextSize == 0) {
                    nextDir = 0;
                }
                else { //무리가 존재할 경우 방향이 전환됨
                    if (nextDir == 1) nextDir = 2;
                    else if (nextDir == 2) nextDir = 1;
                    else if (nextDir == 3) nextDir = 4;
                    else if (nextDir == 4) nextDir = 3;
                }
            }

            //수정된 사항 입력
            microbe[j] = { nextX,nextY,nextSize,nextDir };
        }
        //이동후 상황 입력
        for (int j = 0; j < microbe.size(); j++) {
            if (microbe[j].siZe == 0) continue; //무리가 없다면 입력X
            int x = microbe[j].x;
            int y = microbe[j].y;
            int siZe = microbe[j].siZe;
            int dir = microbe[j].dir;

            if (map[x][y].info[0].first == 0) { //아직 아무 무리도 안왔으면 입력
                map[x][y].info[0] = { siZe,dir };
            }
            else { //어떤 무리가 차지했다면 push_back
                map[x][y].info.push_back({ siZe,dir });
            }
        }
        //map의 저장후 미생물 벡터 초기화 후 다시 담을 준비
        microbe.clear();

        //map의 상황을 확인하고 미생물 무리 저장하기
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (map[j][k].info[0].first == 0) continue;
                if (map[j][k].info.size() > 1) {
                    //한 곳에 여러무리가 만났다
                    //크기가 큰 놈이 앞으로 가게 한다.
                    sort(map[j][k].info.begin(), map[j][k].info.end(), cmp);
                    int infosize = map[j][k].info.size();
                    for (int p = 1; p < infosize; p++) { //무리합
                        map[j][k].info[0].first += map[j][k].info[p].first;
                    }
                    //뒤에 무리 지우기
                    for (int p = 1; p < infosize; p++) {
                        map[j][k].info.pop_back();
                    }  
                }
                //미생물 확인후 저장 및 맵 초기화
                microbe.push_back({ j,k,map[j][k].info[0].first,map[j][k].info[0].second });
                map[j][k].info[0] = { 0,0 };
            }
        }
    }
    for (int i = 0; i < microbe.size(); i++) {
        ans += microbe[i].siZe;
    }
}

int main() {

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        init();
        input();
        solve();

        cout << "#" << tc << " " << ans << "\n";
    }
  
   
    return 0;
}