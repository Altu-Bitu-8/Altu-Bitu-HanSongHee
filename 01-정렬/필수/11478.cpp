#include <iostream>
#include <string>
#include <set>

using namespace std;
int main() {
    string str;
    cin >> str;
    set<string> S;
    int N = str.size();
    for (int i = 0; i < N; i++) {
        for (int len = 1; len <= N - i; len++) {
            S.insert(str.substr(i, len));
        }
    }
    cout << S.size();
    return 0;
}