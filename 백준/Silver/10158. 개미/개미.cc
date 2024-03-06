#include <iostream>


using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h, antx, anty, t;
    int dim = 0; //우상:0, 좌상:1, 좌하:2, 우하:3
    cin >> w >> h >> antx >> anty >> t;

    int tmp = 0;

    while (1) {
        if (dim == 0) { //우상
            int distx = w - antx;
            int disty = h - anty;

            if (distx <= disty) {
                //시간 중가분 확인
                if (tmp+distx > t) {
                    //좌표 이동
                    antx += (t - tmp);
                    anty += (t - tmp);
                    tmp= t;
                }
                else {
                    //좌표 이동
                    antx += distx;
                    anty += distx;
                    tmp += distx;
                }
                
                if (distx == disty) dim = 2; //좌하
                else dim = 1; //좌상
            }
            else{
                //시간증가 확인
                if (tmp + disty > t) {
                    antx += (t - tmp);
                    anty += (t - tmp);
                    tmp = t;
                }
                else {
                    //좌표이동
                    antx += disty;
                    anty += disty;

                    tmp += disty;
                }

                dim = 3;
            }
        }
        else if (dim == 1) { //좌상
            int distx = antx;
            int disty = h - anty;

            if (distx <= disty) {
                if (tmp + distx > t) {
                    antx -= (t - tmp);
                    anty += (t - tmp);

                    tmp = t;
                }
                else {
                    //시간증가
                    tmp += distx;
                    //좌표이동
                    antx -= distx;
                    anty += distx;
                }
               
                if (distx == disty) dim = 3;//우하
                else dim = 0;
            }
            else {
                if (tmp + disty > t) {
                    antx -= (t - tmp);
                    anty += (t - tmp);
                    
                    tmp = t;
                }
                else {
                    //좌표이동
                    antx -= disty;
                    anty += disty;

                    //시간 증가
                    tmp += disty;
                }
                dim = 2;
            }
        }
        else if (dim == 2) { //좌하
            int distx = antx;
            int disty = anty;

            if (distx <= disty) {
                if (tmp + distx > t) {
                    antx -= (t - tmp);
                    anty -= (t - tmp);

                    tmp = t;
                }
                else {
                    //시간증가
                    tmp += distx;
                    //좌표이동
                    antx -= distx;
                    anty -= distx;
                }
                
                if (distx == disty) dim = 0;
                else dim = 3;
            }
            else{
                if (tmp + disty > t) {
                    antx -= (t - tmp);
                    anty -= (t - tmp);
                    tmp = t;
                }
                else {
                    //시간 증가
                    tmp += disty;
                    //좌표이동
                    antx -= disty;
                    anty -= disty;
                }

                dim = 1;
            }
        }
        else if (dim == 3) {//우하
            int distx = w - antx;
            int disty = anty;

            if (distx <= disty) {
                if (tmp + distx > t) {
                    antx += (t - tmp);
                    anty -= (t - tmp);

                    tmp = t;
                }
                else {
                    //좌표이동
                    antx += distx;
                    anty -= distx;
                    //시간증가
                    tmp += distx;
                }
                
                if (distx == disty) dim = 1;
                else dim = 2;
            }
            else if (distx > disty) {
                if (tmp + disty > t) {
                    antx += (t - tmp);
                    anty -= (t - tmp);
                    tmp = t;
                }
                else {
                    //좌표이동
                    antx += disty;
                    anty -= disty;

                    //시간증가
                    tmp += disty;
                }
                
                dim = 0;
            }
        }
        
        if (tmp == t) break;
    }

    cout << antx << " " << anty;

    return 0;
}



