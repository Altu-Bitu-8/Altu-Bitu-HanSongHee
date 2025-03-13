#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true) {
        //줄별로 문장 입력받기
        string input;
        getline(cin, input);

        //.이 입력되면 while문 끝내기
        if (input == ".") {
            break;
        }
        //문장의 괄호를 담을 stack과 yes/no를 표현할 result 생성
        stack<char> S;
        bool result = true;
        for (int i = 0; i < input.length(); i++) {
            //문장안에 여는 괄호가 있으면 stack에 담기(push)
            if (input[i] == '[' || input[i] == '(') {
                S.push(input[i]);
            }
            //문장안에 닫는 괄호가 있을때
            if (input[i] == ']') {
                //stack이 비어있지 않고(empty()가 0) stack의 가장 위의 값이 짝꿍 여는 괄호이면 stack의 가장 위의 값을 제거(pop)
                if (S.empty() == 0 && S.top() == '[') {
                    S.pop();
                }
                //아니라면 result를 false로 바꾸고 while문 종료
                else {
                    result = false;
                    break;
                }
            }
            if (input[i] == ')') {
                if (S.empty() == 0 && S.top() == '(') {
                    S.pop();
                }
                else {
                    result = false;
                    break;
                }
            }
        }
        //stack이 비어있고 result가 true라면 yes출력
        if (S.empty() == 1 && result == true) {
            cout << "yes" << endl;
        }
        //아니라면 no출력
        else {
            cout << "no" << endl;
        }
    }
}