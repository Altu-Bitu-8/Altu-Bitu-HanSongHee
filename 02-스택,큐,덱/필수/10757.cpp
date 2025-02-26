#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    //두 문장의 길이를 비교해 짧은 쪽 앞에 0을 추가함
    while (A.length() < B.length()) A = '0' + A;
    while (B.length() < A.length()) B = '0' + B;

    string result = "";
    int round = 0; //자리올림변수

    //뒤에서 부터 차례대로 덧셈
    for (int i = A.length() - 1; i >= 0; i--) {
        int sum = (A[i] - '0') + (B[i] - '0') + round;
        round = sum / 10; //10을 넘으면 1을 올림
        result += (sum % 10) + '0'; //자리수 하나 추가함
    }

    if (round) result += '1'; //마지막으로 올림이 남아있으면 자리를 올림
    reverse(result.begin(), result.end()); //뒤에서 부터 계산했으니 reverse로 뒤집어서 출력

    cout << result;
}