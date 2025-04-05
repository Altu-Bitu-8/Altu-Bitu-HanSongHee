#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;  // cards 벡터 정의 0: 도도, 1: 수연
const int DO = 0, SU = 1;

/** 승리 판단하기 */
string judge(cards& deck) {
	//도도와 수연의 deck크기 정의
	int do_deck = deck[DO].size(),su_deck = deck[SU].size();
	//도도의 카드가 더 많을 경우
	if (do_deck > su_deck) {
		return "do"; //도도가 승리
	}
	//수연의 카드가 더 많을 경우
	else if (do_deck < su_deck) {
		return "su"; //수연의 승리
	}
	return "dosu";//카드의 수가 같다면 무승부이므로 dosu반환
}

/** 그라운드에서 덱으로 카드 옮기기 */
void groundToDeck(deque<int>& deck, deque<int>& ground) {
	//ground가 비어있지 않다면
	while (!ground.empty()) {
		deck.push_back(ground.back());//ground에서 맨 뒤 카드부터 deck 뒤에 추가
		ground.pop_back();//ground에서 카드 제거
	}
}

/** 종을 쳤을 때 */
void ringTheBell(int player, cards& deck, cards& ground) {
	groundToDeck(deck[player], ground[!player]);// 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); // 카드 가져가기 (본인 그라운드 -> 본인 덱)
}


/** 종을 울릴 수 있는 사람 판단 */
int whoCanRingTheBell(cards& deck, cards& ground) {
	// 도도의 그라운드 맨위 카드가 5이면
	if (!ground[DO].empty() && ground[DO].front() == 5) { 
		return DO;//도도가 종을 침
	}
	//수연의 그라운드 맨위 카드가 5이면
	else if (!ground[SU].empty() && ground[SU].front() == 5) { 
		return DO;//도도가 종을 침
	}
	//양쪽 그라운드 맨 위 카드의 합이 5일때
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { // 수연
		return SU; //수연이 종을 침
	}
	return -1; // 종을 울릴 수 없음
}

/** 게임 진행 */
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; // 도도 먼저
	//m번 라운드 반복
	while (m--) {
		ground[turn].push_front(deck[turn].front()); // 카드 내려놓기(덱 -> 그라운드)
		deck[turn].pop_front();//deck에서 카드 제거
		//현재 플레이어의 deck이 비어있다면
		if (deck[turn].empty()) {
			break;//게임종료
		}

		int bell = whoCanRingTheBell(deck, ground); // 종을 울릴 수 있는 사람
		if (bell != -1) { // 종을 울린 경우
			ringTheBell(bell, deck, ground);//종을 친 사람이 그라운드의 카드를 가져감
		}
		turn = !turn; // 차례 바꾸기
	}
	return judge(deck);//게임종료 후 judge함수로 승자 판단
}

/**
 * 도도, 수연이 각각 덱과 그라운드를 가짐
 * 도도->수연->도도->수연... 순으로 차례를 바꿔가며 게임 진행 (game 함수)
 * 1. 카드를 덱에서 한 장 내려놓음
 * 2. 어떤 플레이어가 종을 칠 수 있는지 판단 (whoCanRingTheBell 함수)
 * 3. 종을 친 경우 그라운드의 카드를 덱으로 이동(ringTheBell, groundToDeck 함수)
 * 종료 조건 만족 시 승리한 사람 리턴(judge 함수)
 */

int main() {
	int n, m, card1, card2;//카드 수 n,라운드 횟수 m, 각 플레이어의 카드값
	cards deck(2), ground(2); // 0: 도도, 1: 수연

	// 입력
	cin >> n >> m;
	while (n--) {
		cin >> card1 >> card2; //카드 두장입력(도도,수연)
		deck[DO].push_front(card1);//도도 카드 앞에 추가
		deck[SU].push_front(card2);//수연 카드 앞에 추가
	}

	// 출력 & 연산
	cout << game(m, deck, ground); //게임 실행

	return 0;
}