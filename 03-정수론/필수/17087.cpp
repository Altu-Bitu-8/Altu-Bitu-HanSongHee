#include <iostream>
#include <algorithm>
using namespace std;

int getGcdRecur(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcdRecur(b, a % b);
}

int main() {
    int N, S, A, D;
    cin >> N >> S >> A;
    D = abs(S - A);
    for (int i = 1; i < N; i++) {
        S = A;
        cin >> A;
        D = getGcdRecur(D, abs(S - A));
    }
    cout << D;
}