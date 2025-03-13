#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void isPrime(int n, vector<bool>& is_prime) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<bool> is_prime(1000001, true);
    isPrime(1000000, is_prime);
    int N;
    while (true) {
        cin >> N;
        if (N == 0)break;
        bool flag = false;
        for (int i = 2; i <= (N / 2); i++) {
            if (is_prime[i] && is_prime[N - i]) {
                cout << N << " = " << i << " + " << (N - i) << '\n';
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }
    return 0;
}