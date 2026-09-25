#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
// [[0, 3], [1, 9], [3, 5]] -> 8
// [요청시각,소요시각]

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int sum_ = 0;
    sort(jobs.begin(), jobs.end());
    int i = 0;
    int time = 0;
    int size_ = jobs.size();
    priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> pq;
    while(i<size_ || !pq.empty()){
        while(i<size_ && jobs[i][0] <= time){
            pq.push({jobs[i][1], jobs[i][0]});
            i++;
        }
        
        if(pq.empty()){
            time = jobs[i][0];
            continue;
        }
        
        auto [require, request] =pq.top();
        time += require;
        sum_ += (time - request);
        pq.pop();
    }
    answer = sum_/size_;
    return answer;
}