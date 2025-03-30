#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> li;// 톱니바퀴 상태를 저장할 벡터
vector<pair<int, int>> stack;// 회전할 톱니바퀴와 방향을 저장하는 stack
vector<int> visited;// 방문 여부를 체크하는 벡터 

// 회전할 수 있는 톱니바퀴를 찾는 함수
void check_rotation(int current_num, int current_dir)
{
    // 왼쪽 톱니바퀴 확인 
    if (current_num - 1 >= 0 && visited[current_num - 1] == 0)
    {
        if (li[current_num][6] != li[current_num - 1][2])
        { // 맞닿아 있는 면이 서로 다른 극인지 체크
            stack.push_back(make_pair(current_num - 1, current_dir * -1));// 반대 방향으로 회전
            visited[current_num - 1] = 1;//방문여부 저장 
            check_rotation(current_num - 1, current_dir * -1);// 재귀적으로 호출 
        }
    }
    // 오른쪽 톱니바퀴 확인 
    if (current_num + 1 < li.size() && visited[current_num + 1] == 0)
    {
        if (li[current_num][2] != li[current_num + 1][6])
        { // 맞닿아 있는 면이 서로 다른 극인지 체크
            stack.push_back(make_pair(current_num + 1, current_dir * -1));// 반대 방향으로 회전
            visited[current_num + 1] = 1;//방문여부 저장
            check_rotation(current_num + 1, current_dir * -1);// 재귀적으로 호출 
        }
    }
}

int main()
{
    int t;// 톱니바퀴 개수
    int k;// 회전 횟수

    cin >> t; // 톱니바퀴의 개수 T 입력

    li.resize(t); // 톱니바퀴 개수만큼 resize(벡터 크기 조절 )
    for (int i = 0; i < t; ++i)
        cin >> li[i]; // 톱니바퀴 상태 입력

    cin >> k; // 회전 횟수 K 입력
    for (int i = 0; i < k; ++i)
    { // k번 돌면서 회전할 수 있는지에 대해 체크
        int num, direction;//회전 시킬 톱니바퀴 번호와 방향 
        cin >> num >> direction; // 방향 입력 (1이면 시계 방항, -1이면 반시계 방향)
        stack.clear();//stack 초기화 
        stack.push_back(make_pair(num - 1, direction));//첫번째 회전할 톱니바퀴 저장 
        visited.assign(t, 0); // t개만큼 0을 초기화
        visited[num - 1] = 1;//첫번째 톱니바퀴 방문으로 저장 
        check_rotation(num - 1, direction);//회전 가능한 톱니바퀴 찾기 

        while (!stack.empty())//stack과 while을 이용하여 계속 회전
        {
            pair<int, int> top = stack.back();//stack의 마지막 원소를 가져오기 
            stack.pop_back();//stack에서 마지막 원소 제거 
            int tmp_num = top.first;  // 회전 할 톱니바퀴의 인덱스
            int tmp_dir = top.second; // 회전 방향
            if (tmp_dir == 1)
            { // 시계방향으로 회전 
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7);
            }
            else
            { // 반시계방향으로 회전 
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];
            }
        }
    }

    int cnt = 0;//12시 방향이 '1'인 톱니바퀴 개수
    for (int i = 0; i < t; ++i)
    {
        if (li[i][0] == '1')
        {
            cnt++;//톱니바퀴 개수 증가 
        }
    }

    cout << cnt << endl;//출력 

    return 0;
}