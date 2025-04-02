#include <iostream>
#include <deque>
using namespace std;

deque<int> do_deck, su_deck, do_ground, su_ground;

// 승자를 체크하는 함수
bool winner() {
    if (do_deck.empty()) {
        cout << "su";
        return true;
    }
    if (su_deck.empty()) {
        cout << "do";
        return true;
    }
    return false;
}

// 게임 중 벨을 울린 플레이어가 모든 그라운드의 카드를 가져가는 함수
void ground_cards(deque<int>& winner_deck, deque<int>& first_ground, deque<int>& second_ground) {
    while (!second_ground.empty()) {
        winner_deck.push_back(second_ground.back());
        second_ground.pop_back();
    }
    while (!first_ground.empty()) {
        winner_deck.push_back(first_ground.back());
        first_ground.pop_back();
    }
}

int main() {
    // 입력
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int d, s;
        cin >> d >> s;
        do_deck.push_front(d);
        su_deck.push_front(s);
    }

    // 연산(게임 진행)
    for (int i = 0; i < m; i++) {
        // 도도가 카드를 그라운드에 놓음
        if (!do_deck.empty()) {
            do_ground.push_front(do_deck.front());
            do_deck.pop_front();
            if (winner()) return 0;
        }

        // 수연이가 카드를 그라운드에 놓음
        if (!su_deck.empty()) {
            su_ground.push_front(su_deck.front());
            su_deck.pop_front();
            if (winner()) return 0;
        }

        // 도도가 이기는 경우 (5가 나온 경우)
        if ((!do_ground.empty() && do_ground.front() == 5) || (!su_ground.empty() && su_ground.front() == 5)) {
            ground_cards(su_deck, do_ground, su_ground);
        }
        // 수연이가 이기는 경우 (합이 5)
        else if (!do_ground.empty() && !su_ground.empty() && do_ground.front() + su_ground.front() == 5) {
            ground_cards(do_deck, su_ground, do_ground);
        }
    }

    // 출력
    if (do_deck.size() > su_deck.size()) {
        cout << "do";
    }
    else if (do_deck.size() < su_deck.size()) {
        cout << "su";
    }
    else {
        cout << "dosu";
    }

    return 0;
}