#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
bool visited[10];
int operators[4];
int W[10][10];
int min_cost = 1e9;
void backtracking(int idx, int count, int cost, int start) {
    if (count == N) {
        if (W[idx][start] != 0) {
            min_cost = min(min_cost, cost + W[idx][start]);
        }
        return;
    }

    for (int next = 0; next < N; next++) {
        if (!visited[next] && W[idx][next] != 0) {
            visited[next] = true;
            backtracking(next, count + 1, cost + W[idx][next], start);
            visited[next] = false;
        }
    }
}
int main() {
    //입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }
    //연산
    for (int i = 0; i < N; i++) {
        fill(visited, visited + N, false);
        visited[i] = true;
        backtracking(i, 1, 0, i);
    }
    //출력
    cout << min_cost;
    return 0;
}