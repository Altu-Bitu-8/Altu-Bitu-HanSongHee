#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    //입력
    cin >> n;
    vector<int> v(n); //각 행성별로 이동하는데 필요한 최소 속도 저장 int 벡터
    for (int i = 0; i < n; i++) {
        //입력
        cin >> v[i];
    }
    long long s = v[n - 1]; //마지막 행성에서 필요한 속도
    for (int i = n - 2; i >= 0; i--) {
        s = (s + v[i] - 1) / v[i] * v[i];//s/v[i]를 올림한 몫에 v[i]를 곱하여 배수로 만들기
    }
    //출력
    cout << s;
    return 0;
}