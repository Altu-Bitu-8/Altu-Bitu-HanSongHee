#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int compare(string a, string b) {
    int a_size = a.size();
    int b_size = b.size();
    int a_sum = 0;
    int b_sum = 0;
    
}
int main() {
    int N;
    string s[50];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    sort(s, s + N, compare);
    for (int i = 0; i < N; i++) {
        cout << s[i] << " ";
    }

    return 0;
}