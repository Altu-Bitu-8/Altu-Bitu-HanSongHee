#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //입력
    int n;
    int a[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //연산
    vector<int>dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < i; k++) {
            if (a[i] > a[k]) {
                dp[i] = max(dp[i], dp[k] + 1);
            }
        }
    }
    //벡터에서는 sizeof를 사용할 수 없어서 해결책을 검색하여 찾음 
    int max_length = *max_element(dp.begin(), dp.end());
    //출력
    cout << max_length;
    return 0;
}