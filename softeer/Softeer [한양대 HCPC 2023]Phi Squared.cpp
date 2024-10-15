#include<iostream>
#include<vector>

using namespace std;

//����: long long�� ����Ѵ�

//1.�տ������� ������ �̻��� �� �۰ų� ���� ���� ���� ���
//����ϸ� ũ�Ⱑ ���̵�
//2.��� ���ϸ� �����
//3.��� �� ũ��� �Ǵ��ؼ� �����

struct info {
    int idx; //�ʱ� ��ġ
    long long size; //ũ��
    bool death; //���� ����
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

    //��� ����
    while (sizeMicro > 1) {
        for (int i = 0; i < micro.size(); ++i) {
            info now = micro[i];
            long long absorb = 0; //�����

            if (now.death) continue; //�̻����� �̹� �����

            //����ִ� �ڽ� �տ� �̻��� ã��
            for (int f = i - 1; f >= 0; --f) {
                if (!micro[f].death) { //����ִ°� �ִٸ�

                    //��� ���� �Ǵ�
                    if (micro[f].size <= now.size) {
                        absorb += micro[f].size; //���
                        micro[f].death = true; //����
                        --sizeMicro; //�̻��� ����
                    }

                    break;
                }
            }

            //����ִ� �ڽ� �ڿ� �̻��� ã��
            for (int b = i + 1; b < micro.size(); ++b) {
                if (!micro[b].death) { //����ִ� �� �ִٸ�

                    //��� ���� �Ǵ�
                    if (micro[b].size <= now.size) {
                        absorb += micro[b].size; //���
                        micro[b].death = true; //����
                        --sizeMicro; //�̻��� ����
                    }
                    break;
                }
            }

            //����� ��ŭ Ŀ��
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