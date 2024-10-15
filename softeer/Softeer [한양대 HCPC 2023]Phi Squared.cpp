#include<iostream>
#include<vector>

using namespace std;

//주의: long long을 써야한다

//1.앞에서부터 인접한 미생물 중 작거나 같은 것을 전부 흡수
//흡수하면 크기가 합이됨
//2.흡수 당하면 사라짐
//3.흡수 전 크기로 판단해서 흡수함

struct info {
    int idx; //초기 위치
    long long size; //크기
    bool death; //생존 여부
};

int N;
vector<info>micro;

int main(int argc, char** argv)
{
    //Input
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int msize;
        cin >> msize;
        micro.push_back({ i + 1,msize,false });
    }

    //Num of micro
    int sizeMicro = N;

    //흡수 진행
    while (sizeMicro > 1) {
        for (int i = 0; i < micro.size(); ++i) {
            info now = micro[i];
            long long absorb = 0; //흡수량

            if (now.death) continue; //미생물이 이미 흡수됨

            //살아있는 자신 앞에 미생물 찾기
            for (int f = i - 1; f >= 0; --f) {
                if (!micro[f].death) { //살아있는게 있다면

                    //흡수 가능 판단
                    if (micro[f].size <= now.size) {
                        absorb += micro[f].size; //흡수
                        micro[f].death = true; //죽음
                        --sizeMicro; //미생물 감소
                    }

                    break;
                }
            }

            //살아있는 자신 뒤에 미생물 찾기
            for (int b = i + 1; b < micro.size(); ++b) {
                if (!micro[b].death) { //살아있는 게 있다면

                    //흡수 가능 판단
                    if (micro[b].size <= now.size) {
                        absorb += micro[b].size; //흡수
                        micro[b].death = true; //죽음
                        --sizeMicro; //미생물 감소
                    }
                    break;
                }
            }

            //흡수한 만큼 커짐
            micro[i].size += absorb;

        }

    }

    for (int i = 0; i < micro.size(); ++i) {
        if (!micro[i].death) {
            cout << micro[i].size << "\n" << micro[i].idx;
            break;
        }
    }

    return 0;
}