#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, k;
    //입력
    cin >> n >> k;
    vector<char> Table(n);//벤치 모양 식탁을 나타내는 char벡터
    vector<int> Human, Buger;//사람과 햄버거를 저장하는 int벡터
    for (int i = 0; i < n; i++) {
        //Table 벡터에 순서대로 입력
        cin >> Table[i];
    }
    int count = 0;//사람이 햄버거를 먹는 횟수 0으로 초기화
    for (int i = 0; i < n; i++) {
        //식탁에 있는게 사람이라면
        if (Table[i] == 'P') {
            //k만큼 앞뒤로 선택했을 때
            for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
                //햄버거가 있으면
                if (Table[j] == 'H') {
                    //해당 테이블 위치에 있는 햄버거를 먹은 거니 X로 바꾸기
                    Table[j] = 'X';
                    //사람이 햄버거를 먹은 횟수 증가
                    count++;
                    //j로 반복되는 for문 나가기
                    break;
                }
            }
        }
    }
    //출력
    cout << count;

    return 0;
}