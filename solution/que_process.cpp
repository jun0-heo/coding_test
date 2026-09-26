#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int,int>> q; // {인덱스, 우선순위}
    for (int i = 0; i < (int)priorities.size(); i++) {
        q.push({i, priorities[i]});
    }

    int order = 0; // 실행된 순서 카운트

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        // 남은 큐 중에 나보다 우선순위 높은 게 있는지 확인
        bool hasHigher = false;
        queue<pair<int,int>> temp = q;
        while (!temp.empty()) {
            if (temp.front().second > cur.second) {
                hasHigher = true; 
                break;
            }
            temp.pop();
        }

        if (hasHigher) {
            q.push(cur); // 뒤로 보냄
        } else {
            order++; // 실행
            if (cur.first == location) {
                return order;
            }
        }
    }

    return order; // 도달하지 않음
}