#include <iostream>
#include <deque>

using namespace std;

struct info { // 각 칸마다 내구도와 로봇 존재 여부 저장하는 구조체
    int power; //내구도
    bool is_on = false; //로봇이 해당 칸 위에 있는지 여부(default=없음)
};

// 벨트를 한 칸 회전
void rotateBelt(deque<info>& belt, int n) {
    belt.push_front(belt.back()); // 벨트의 마지막 칸을 앞에 push
    belt.pop_back();              // 마지막 칸을 pop
    belt[n - 1].is_on = false;    // 내리는 위치(n-1)에 로봇이 있으면 로봇 내리기
}

// 로봇을 움직일 수 있다면 한 칸 이동
void moveRobot(deque<info>& belt, int n) {
    for (int i = n - 2; i >= 0; i--) { // 배열 접근 가능 범위가 0~n-1인데 다음 칸과 비교하기 위해 0~n-2까지 반복
        // 현재 칸에 로봇이 존재하고, 다음 칸에 로봇이 없으며, 다음 칸에 내구도가 남아있을 때 이동 가능
        if (belt[i].is_on && !belt[i + 1].is_on && (belt[i + 1].power >= 1)) {
            belt[i].is_on = false; //현재 위치에서 로봇 제거
            belt[i + 1].is_on = true; //다음 위치에서 로봇 배치
            belt[i + 1].power--; //다음 위치 내구도 감소
        }
    }
    belt[n - 1].is_on = false; // 내리는 위치에 로봇이 도달하면 로봇 내리기
}

// 올리는 칸에 로봇을 올릴 수 있다면 올리기
void putRobot(deque<info>& belt) {
    // 올리는 칸의 내구도가 남아 있으면(1이상)
    if (belt[0].power >= 1) {
        belt[0].is_on = true; //로봇 올리기
        belt[0].power--; //내구도 감소
    }
}

// 벨트의 내구도 체크(내구도가 0인 칸의 개수가 k개 이상인지 확인)
bool checkFinish(deque<info>& belt, int n, int k) {
    int cnt = 0; // 내구도 0인 칸의 개수
    for (int i = 0; i < 2 * n; i++) {
        if (belt[i].power == 0) {
            cnt++; //내구도가 0인 칸 수 세기
        }
    }

    return cnt >= k; //내구도 0인 칸이 k개 이상이면 true반환
}
//전체 시뮬레이션을 실행하고 종료 시점의 단계를 반환
int solution(deque<info>& belt, int n, int k) {
    // 1단계부터 시작
    int step = 1;
    while (true) {
        // 1. 벨트 회전
        rotateBelt(belt, n);

        // 2. 로봇 이동
        moveRobot(belt, n);

        // 3. 로봇 올리기
        putRobot(belt);

        // 4. 내구도가 0인 칸의 개수가 k개 이상인지 체크
        if (checkFinish(belt, n, k)) {
            return step; //조건을 충족하면 현재 단계를 반환
        }
        step++; //다음단계로
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n, k; // n:컨베이어 벨트의 길이, k:내구도 0인 칸의 최대 개수
    cin >> n >> k;
    deque<info> belt(2 * n); // 2n개의 칸을 가지는 벨트 deque

    // 벡트의 각 칸마다 내구도 입력, 로봇 존재 여부 초기화
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> belt[i].power; //내구도 저장
    }

    // 연산 & 출력
    cout << solution(belt, n, k);
}