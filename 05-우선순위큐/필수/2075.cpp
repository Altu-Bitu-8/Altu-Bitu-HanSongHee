#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n_number, x;
    cin >> n_number;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 0; i < n_number * n_number; i++) {
        cin >> x;
        min_heap.push(x);
        if (min_heap.size() > n_number) {
            min_heap.pop();
        }
    }
    cout << min_heap.top();
    return 0;
}