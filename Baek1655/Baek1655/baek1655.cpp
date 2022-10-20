#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N = 0; //������ ��ĥ ������ ����
    int tmp[10000]; //���� ��¿�
    int callNum = 0; //��ġ�� ���ڸ� ��� ����
    vector<int> numVector;
    priority_queue<int> priority_num;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> callNum;

        priority_num.push(callNum);
        int tmpNum = priority_num.size();

        for (int j = 0; j < tmpNum; j++) {
            numVector.push_back(priority_num.top());
            priority_num.pop();
        }

        for (int m = 0; m < tmpNum; m++) {
            priority_num.push(numVector[m]);
        }

        if (tmpNum % 2 == 0) {
            tmp[i] = numVector[(tmpNum / 2)];
        }
        else {
            tmp[i] = numVector[(tmpNum + 1) / 2 - 1];
        }

        numVector.clear();
    }

    for (int k = 0; k < N; k++) {
        cout << tmp[k] << endl;
    }
}