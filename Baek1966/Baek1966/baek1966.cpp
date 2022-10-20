#include <iostream>
#include <queue>

using namespace std;

int main() {
    int num_test_cases;
    int N, M; //문서의 개수, 몇 번째로 놓여있는지
    int temp_order, temp_priority;

    //ifstream fin("Prob_1966.txt");
    //txt 파일을 입력할 때 사용되나 입력테스트를 위해 제외함.

    int num = 0;
    int tmp[100];

    cin >> num_test_cases;
    for (int i = 0; i < num_test_cases; ++i) {
        cin >> N >> M;

        queue<pair<int, int> > ordered_data; //순서와 중요도를 같이 저장
        priority_queue<int> priority_data; //중요도만 저장, 중요도 높은순으로 정렬

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
                ordered_data.pop(); //중요도 더 높은 문서가 있을 경우 Queue의 맨 뒤로
            }
            else {
                count++; //제 순서일 경우 출력
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