#include <iostream>
#include <queue>

using namespace std;

int main() {
    int num_test_cases;
    int N, M; //������ ����, �� ��°�� �����ִ���
    int temp_order, temp_priority;

    //ifstream fin("Prob_1966.txt");
    //txt ������ �Է��� �� ���ǳ� �Է��׽�Ʈ�� ���� ������.

    int num = 0;
    int tmp[100];

    cin >> num_test_cases;
    for (int i = 0; i < num_test_cases; ++i) {
        cin >> N >> M;

        queue<pair<int, int> > ordered_data; //������ �߿䵵�� ���� ����
        priority_queue<int> priority_data; //�߿䵵�� ����, �߿䵵 ���������� ����

        for (int j = 0; j < N; ++j) {
            cin >> temp_priority;
            ordered_data.push({ temp_priority, j });
            priority_data.push(temp_priority);
        }

        int count = 0;
        while (!ordered_data.empty()) {
            int temp_priority = ordered_data.front().first;
            int temp_order = ordered_data.front().second;

            if (temp_priority < priority_data.top()) {
                ordered_data.push(ordered_data.front());
                ordered_data.pop(); //�߿䵵 �� ���� ������ ���� ��� Queue�� �� �ڷ�
            }
            else {
                count++; //�� ������ ��� ���
                ordered_data.pop();
                priority_data.pop();

                if (temp_order == M) {
                    tmp[num] = count;
                    num = num + 1;
                    break;
                }
            }
        }
    }
    for (int k = 0; k < num_test_cases; k++) {
        cout << tmp[k] << endl;
    }

    return 0;
}