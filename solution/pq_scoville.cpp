#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    // 최소 힙 (작은 값이 top)
    priority_queue<long long, vector<long long>, greater<long long>> pq(
        scoville.begin(), scoville.end());

    int answer = 0;

    while (pq.top() < K) {
        if (pq.size() < 2) return -1;   // 섞을 음식이 없음

        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();

        pq.push(first + second * 2);
        answer++;
    }

    return answer;
}