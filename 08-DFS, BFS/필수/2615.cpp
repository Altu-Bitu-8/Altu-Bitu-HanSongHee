#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix; //2차원 정수 벡터 matrix 정의
const int SIZE = 20, EMPTY = 0; //바둑판의 크기=20x20, 빈칸=0으로 정의

// 방향에 따른 좌표 증가량(오른쪽 위, 오른쪽, 오른쪽 아래, 아래 방향)
// 맨 왼쪽 위 돌을 기준으로 검사하기 때문에 오른쪽+아래쪽으로 향하는 방향만 정의
const vector<int> dx = { -1, 0, 1, 1 };//x축 이동
const vector<int> dy = { 1, 1, 1, 0 };//y축 이동

/**
 * 범위와 돌의 종류가 유효한지 확인한다.
*/
//주어진 좌표가 유효범위내에 있고 해당 칸에 같은 색이 있는지 확인하는 함수
bool isValid(matrix& board, int x, int y, int color) {
    return (x > 0 && x < SIZE && y > 0 && y < SIZE && board[x][y] == color);
}

/**
 * 해당 좌표(x, y)부터 연속적으로 5알이 놓이는지 확인한다.
*/
bool checkWin(matrix& board, int x, int y) {
    int color = board[x][y]; // 기준 색(현재 좌표의 돌 색)

    // 4개 방향에 대해 검사
    for (int idx = 0; idx < 4; idx++) {
        int cnt = 1;    // cnt: 같은 방향에 놓인 같은 색 돌의 수
        int prev_x = x - dx[idx], prev_y = y - dy[idx];//현재 방향의 이전 칸 좌표를 계산
        int next_x = x + dx[idx], next_y = y + dy[idx];//현재 방향의 다음 칸 좌표 계산

        // 같은 방향에서 그 이전에도 같은 색 돌이 있었다면 패스 (-> 여섯 알 이상 놓이는 경우를 제외하기 위함)
        if (isValid(board, prev_x, prev_y, color)) {
            continue;
        }

        // 연속적으로 놓인 5알이 같은 색인지 확인
        while (isValid(board, next_x, next_y, color) && cnt < 6) {
            next_x += dx[idx];//다음칸으로 이동
            next_y += dy[idx];
            cnt++; //같은 방향에 놓은 같은 색 돌 개수 증가
        }
        // cnt가 5일 때만 true(승리) 리턴 (-> 다섯 알보다 적거나 다섯 알보다 많이 놓이는 경우를 제외)
        if (cnt == 5) {
            return true;
        }
    }
    return false;//어떤 방향에서도 정확히 5개가 연속되지 않음-> false 반환
}

int main() {
    // 입력
    matrix board(SIZE, vector<int>(SIZE, 0)); // 바둑판(20x20) 초기화
    //입력: (1,1)~(19,19)까지 바둑판 상태 입력
    for (int i = 1; i < SIZE; i++)
        for (int j = 1; j < SIZE; j++)
            cin >> board[i][j];

    // 연산 및 출력
    for (int y = 1; y < SIZE; y++) {//열 기준 반복
        for (int x = 1; x < SIZE; x++) {//행 기준 반복
            // 빈 칸이면 검사패스
            if (board[x][y] == EMPTY) {
                continue;
            }
            // 해당 좌표(x, y)부터 연속적으로 5알이 놓였다면 정답 출력
            if (checkWin(board, x, y)) {
                cout << board[x][y] << '\n'//승리한 돌의 색 출력
                    << x << ' ' << y;//승리 시작점의 좌표 출력
                return 0;
            }
        }
    }
    cout << 0;//승리 조건을 만족하는 돌이 없으면 0출력

    return 0;
}