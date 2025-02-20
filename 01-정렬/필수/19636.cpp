#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int W0, I0, T, D, I, A;

	cin >> W0 >> I0 >> T;
	cin >> D >> I >> A;

	int W1 = W0; //기초대사량 변화 반영 안함
	int W2 = W0; //기초 대사량 변화 반영 함

	int I1 = I0; //변화된 기초대사량 변수

	for (int i = 0; i < D; i++) {
		W1 += I - (I0 + A);
		W2 += I - (I1 + A);
		if (abs(I - (I1 + A)) > T) {
			I1 += floor((I - (I1 + A)) / 2.0);
		}
	}
	if (W1 <= 0 || I0 <= 0) {
		cout << "Danger Diet\n";
	}
	else {
		cout << W1 << ' ' << I0 << '\n';
	}
	if (W2 <= 0 || I1 <= 0) {
		cout << "Danger Diet";
	}
	else {
		cout << W2 << ' ' << I1 << ' ';
		if (I0 - I1 > 0) {
			cout << "YOYO";
		}
		else {
			cout << "NO";
		}
	}
}