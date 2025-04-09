#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    //입력
    int n;
    cin >> n;
    int person1, person2;
    cin >> person1 >> person2;
    int m;
    cin >> m;

    //벡터 선언
    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1, -1);

    //연산
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    //queue 선언
    queue<int> q;
    q.push(person1);
    visited[person1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (visited[next] == -1) {
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }
    //출력
    cout << visited[person2];
    return 0;
}