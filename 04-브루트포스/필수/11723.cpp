#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //입력
    int M, x;
    string D;
    set<int> S;
    cin >> M;
    //연산
    for (int i = 0; i < M; i++) {
        cin >> D;
        if (D == "add") {
            cin >> x;
            S.insert(x);
        }
        if (D == "remove") {
            cin >> x;
            S.erase(x);
        }
        if (D == "check") {
            cin >> x;
            if (S.find(x) != S.end()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        if (D == "toggle") {
            cin >> x;
            if (S.find(x) != S.end()) {
                S.erase(x);
            }
            else {
                S.insert(x);
            }
        }
        if (D == "all") {
            S = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
        }
        if (D == "empty") {
            S.clear();
        }
    }
    return 0;
}