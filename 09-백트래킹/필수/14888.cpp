#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> numbers;
int operators[4];
int max_result = -1e9;
int min_result = 1e9;
void backtracking(int idx, int current) {
    if (idx == N) {
        max_result = max(max_result, current);
        min_result = min(min_result, current);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) {
            operators[i]--;
            int next = current;
            if (i == 0) {
                next += numbers[idx];
            }
            else if (i == 1) {
                next -= numbers[idx];
            }
            else if (i == 2) {
                next *= numbers[idx];
            }
            else if (i == 3) {
                if (next < 0) {
                    next = -(-next / numbers[idx]);
                }
                else next /= numbers[idx];
            }
            backtracking(idx + 1, next);
            operators[i]++;
        }
    }
}
int main() {
    //입력
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }
    //연산
    backtracking(1, numbers[0]);
    //출력
    cout << max_result << "\n" << min_result;
    return 0;
}