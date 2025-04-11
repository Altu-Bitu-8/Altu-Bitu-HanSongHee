#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    //입력
    int com_num, pair_num;
    cin >> com_num;
    cin >> pair_num;

    //벡터 선언
    vector<vector<int>> graph(com_num + 1);
    vector<int> visited(com_num + 1, -1);

    //연산
    for (int i = 0; i < pair_num; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    //queue 선언
    queue<int> q;
    q.push(1);
    visited[1] = 0;
    int infected_com = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur]) {
            if (visited[next] == -1) {
                visited[next] = visited[cur] + 1;
                q.push(next);
                infected_com++;
            }
        }
    }
    //출력
    cout << infected_com;
    return 0;
}