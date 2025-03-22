#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//대기자 정보 저장 구조체
struct info {
    int idx;        // 처음 줄에 선 번호(0부터 시작)
    int line_num;   // 대기열 번호(m개의 줄 중 어디에 속했는가)
    int work_days;  // 근무 일수(많을 수록 높은 우선순위)
    int urgency;    // 급한 정도(높을 수록 높은 우선순위)
};

//우선순위 queue의 정렬 기준을 정의하는 구조체
struct cmp {
    bool operator()(const info& child, const info& parent) {
        //work_days가 많은 사람이 우선
        if (parent.work_days != child.work_days) {
            return parent.work_days > child.work_days;
        }
        //urgency가 높은 사람이 우선
        if (parent.urgency != child.urgency) {
            return parent.urgency > child.urgency;
        }
        //조건이 같으면 line_num이 작은 사람이 우선
        return parent.line_num < child.line_num;
    }
};

int simulation(int m, int k, vector<queue<info>>& lines) {
    // 우선순위 queue 선언
    priority_queue<info, vector<info>, cmp> pq;

    // 각 줄에서 첫번째 사람을 우선순위 queue에 삽입
    for (int i = 0; i < m; i++) {
        if (!lines[i].empty()) {
            pq.push(lines[i].front());
            lines[i].pop();
        }
    }

    int count = 0; // k번째 사람이 자신의 차례가 오기 전까지 처리된 사람 수

    while (!pq.empty() && pq.top().idx != k) {  // k의 차례가 되기 전까지 반복
        int line_num = pq.top().line_num; //현재 처리된 사람의 줄번호
        pq.pop();

        //해당 줄에서 다음 사람이 있으면 queue에 추가
        if (!lines[line_num].empty()) {
            pq.push(lines[line_num].front());
            lines[line_num].pop();
        }

        count++;//처리된 사람 수 증가
    }

    return count; //k번째 사람 앞에 있던 사람 수 반환
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, d, h;
    cin >> n >> m >> k;

    vector<queue<info>> lines(m, queue<info>());

    // n명의 정보를 입력받아 각 줄에 배치
    for (int i = 0; i < n; i++) {
        cin >> d >> h;
        lines[i % m].push({ i, i % m, d, h }); //i번째 사람을 i%m번째 줄에 배치
    }

    // 시뮬레이션 실행 후 결과 출력
    cout << simulation(m, k, lines);

    return 0;
}