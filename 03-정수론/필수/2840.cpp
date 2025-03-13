#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N, K, S;
    char Word;
    cin >> N >> K;
    vector<char> Wheel(N, '?');
    set<char> Used_Words;
    int Position = 0;
    for (int i = 0; i < K; i++) {
        cin >> S >> Word;
        Position = (Position - S % N + N) % N;

        if (Wheel[Position] != '?' && Wheel[Position] != Word) {
            cout << "!" << endl;
            return 0;
        }
        if (Used_Words.count(Word) && Wheel[Position] != Word) {
            cout << "!" << endl;
            return 0;
        }

        Wheel[Position] = Word;
        Used_Words.insert(Word);
    }
    for (int i = 0; i < N; i++) {
        cout << Wheel[(Position + i) % N];
    }
    cout << endl;

    return 0;
}