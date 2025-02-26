#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //N값 입력받기
    int N;
    cin >> N;

    //1부터 N까지 담긴 queue생성
    queue<int> Q;
    for (int i = 1; i <= N; i++) {
        Q.push(i);
    }

    //문제 조건대로 마지막 하나가 남을 때까지 실행
    while (Q.size() != 1) {
        //제일 앞에 있는 값 빼기
        Q.pop();
        //그다음으로 앞에 있는 값을 queue에 삽입
        Q.push(Q.front());
        //그후 앞에 있는 값 빼기. 이러면 결론적으로 앞에 있는 값을 뒤로 보낸셈이 된다.
        Q.pop();
    }

    cout << Q.front();
    return 0;
}