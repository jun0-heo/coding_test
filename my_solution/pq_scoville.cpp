// https://school.programmers.co.kr/learn/courses/30/lessons/42626
#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int mix_(vector<int> scoville, int k){
    for(auto hot : scoville){
        pq.push(hot);
    }
    int count = 0;
    while(!pq.empty()){
        int first = pq.top();
        pq.pop();
        if (first >= k) return count;
        if(pq.empty()) return -1;
        int second = pq.top();
        pq.pop();
        int new_ = first + 2*second;
        count += 1;
        pq.push(new_);
    }
    return -1;
}


int solution(vector<int> scoville, int K) {
    int answer = mix_(scoville, K);
    return answer;
}