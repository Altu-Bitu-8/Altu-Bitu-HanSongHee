#include <iostream>
#include <vector>
using namespace std;

vector<long long>dp(1001, -1);

long long calculate(int n) {
    if (dp[n] != -1) {
        return dp[n];
    }
    return dp[n] = (calculate(n - 1) + calculate(n - 2)) % 10007;
}
int main()
{
    //입력
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    //출력
    cout << calculate(n);
    return 0;
}