#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
* �߾Ӱ����� ���ϴ� ������ �ε����� ã�Ƽ�
* �ڽ��� ������ ���ʰ� ������ ���Ͽ� �������� ã�ƾ��Ѵ�
* �־����� �Է��� �ſ�ũ�Ƿ� BS�� �ε����� ã����ߴ�
* 
* ---------------------------------------------------
* BS�� �پ��� �������� �����ذ��� ������ ����� ã�� ���� �߿��ϴ�
* BS����ٰ� �ð� ���� Ǯ�� ���ߴ�
*/

int n; //�ڵ��� �Ѱ���
int q; //���� ����
vector<int> v;

int main(int argc, char** argv)
{
    cin >> n >> q;
    v.push_back(0);

    for (int i = 0; i < n; i++) {
        int good;
        cin >> good;
        v.push_back(good);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < q; i++) {
        int tar;
        cin >> tar;//���ϴ� �߰���

        //���� Ž��
        int start = 1;
        int eNd = n;
        int mid = 0;

        while (start <= eNd) {
            mid = (start + eNd) / 2;
            if (v[mid] == tar) {
                break;
            }
            else if (v[mid] < tar) {
                start = mid + 1;
            }
            else {
                eNd = mid - 1;
            }
        }
        if (start > eNd) { //�������� ������
            cout << 0 << "\n";
        }
        else { 
            int left = mid - 1;
            int right = n - mid;
            cout << right * left << "\n";
        }

    }

    return 0;
}