#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    // n > s 모든 원소 1로 해도 안되는 경우
    if(n > s){
        answer.push_back(-1);
    }
    else{
        for(int i=n;i>=1;i--){
            answer.push_back(s/i);
            s -= (s/i);
        }
    }
    
    return answer;
}