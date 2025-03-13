#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int E, S, N;
    int Pred_E, Pred_S, Pred_N;
    int Year;
    cin >> E >> S >> N;
    if (E == 15 && S == 28 && N == 19) {
        Year = 7980;
    }
    Year = E;
    while (true) {
        Pred_S = Year % 28;
        Pred_N = Year % 19;
        if (Pred_S == S % 28 && Pred_N == N % 19) {
            break;
        }
        Year += 15;
    }
    cout << Year;
    return 0;
}