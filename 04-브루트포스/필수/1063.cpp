#include <iostream>
#include <string>
using namespace std;

int main()
{
    //입력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char K_x_alpha, R_x_alpha;
    int K_y, R_y, N;
    cin >> K_x_alpha >> K_y >> R_x_alpha >> R_y >> N;
    int K_x = K_x_alpha - 'A' + 1;
    int R_x = R_x_alpha - 'A' + 1;
    //연산
    for (int i = 0; i < N; i++) {
        string move;
        cin >> move;
        int p_K_x = K_x, p_K_y = K_y;
        int p_R_x = R_x, p_R_y = R_y;
        if (move == "R") {
            K_x += 1;
        }
        if (move == "L") {
            K_x -= 1;
        }
        if (move == "B") {
            K_y -= 1;
        }
        if (move == "T") {
            K_y += 1;
        }
        if (move == "RT") {
            K_x += 1;
            K_y += 1;
        }
        if (move == "LT") {
            K_x -= 1;
            K_y += 1;
        }
        if (move == "RB") {
            K_x += 1;
            K_y -= 1;
        }
        if (move == "LB") {
            K_x -= 1;
            K_y -= 1;
        }
        if (K_x > 8 || K_x < 1 || K_y>8 || K_y < 1) {
            K_x = p_K_x;
            K_y = p_K_y;
        }
        if (K_x == R_x && K_y == R_y) {
            R_x += (K_x - p_K_x);
            R_y += (K_y - p_K_y);
            if (R_x > 8 || R_x < 1 || R_y>8 || R_y < 1) {
                K_x = p_K_x;
                K_y = p_K_y;
                R_x = p_R_x;
                R_y = p_R_y;
            }
        }
    }
    //출력
    char result_K_x = K_x + 'A' - 1;
    char result_R_x = R_x + 'A' - 1;
    cout << result_K_x << K_y << endl;
    cout << result_R_x << R_y << endl;
    return 0;
}