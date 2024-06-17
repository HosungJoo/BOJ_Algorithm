#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> A, vector<int> B) {
    int answer = -1;
    
    //오름 차순 정렬
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int len = A.size();
    int bidx = 0;
    int aidx = 0;
    int scr = 0;
    
    while(bidx!=len){
        if(A[aidx]<B[bidx]){
            scr++;
            aidx++;
            bidx++;
        }
        else
            bidx++;
    }
    
    answer = scr;
    
    
    return answer;
}