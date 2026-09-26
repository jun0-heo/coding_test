#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

int custom_max_element(queue<tuple<int,int>> que){
    vector<tuple<int>> vec;
    while(!que.empty()){
        vec.push_back(get<0>(que.front()));
        que.pop();
    }
    auto maxIt = max_element(vec.begin(), vec.end());
    return maxIt - vec.begin();
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int order = 0;
    queue<tuple<int,int>> q;
    int size_ = priorities.size();
    for(int i=0; i<size_; i++){
        q.push({priorities[i], i}); // 우선순위, 인덱스
    }
    
    while(!q.empty()){
        auto largestIndex = custom_max_element(q);

        if (largestIndex != 0){
            for(int i=0; i< (largestIndex); i++){
                auto save_ = q.front();
                q.pop();
                q.push(save_);
            }
        }
        auto [_,index] = q.front();
        q.pop();
        order += 1;
        if(index == location){
            return order;
        }
    }
    return answer;
}