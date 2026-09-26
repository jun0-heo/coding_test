#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <deque>

using namespace std;

struct Compare {
    bool operator()(const tuple<int,int>& t1, const tuple<int,int>& t2) const {
        if(get<0>(t1) == get<0>(t2)){
            return get<1>(t1) > get<1>(t2);
        } 
        return get<0>(t1) < get<0>(t2);        
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<tuple<int,int>, vector<tuple<int,int>>, Compare> pq;
    int size_ = priorities.size();
    for(int i=0; i<size_; i++){
        pq.push({priorities[i], i});
    }
    
    int last_index = -1;
    int order = 0; //order는 실제 순서
    
    
    while(!pq.empty()){
        deque<tuple<int,int>> roll;
        auto [prio, index] = pq.top();
        roll.push_back({prio, index});
        pq.pop();
        while(!pq.empty() && get<0>(pq.top()) == prio){ //같은 prio까지 모으기
            auto [prio2, index2] = pq.top();
            roll.push_back({prio2, index2});
            pq.pop();
        }
        
        if (last_index > get<1>(roll.front()) && last_index < get<1>(roll.back())){
            while (last_index > get<1>(roll.front())){
                auto tmp = roll.front();
                roll.pop_front();
                roll.push_back(tmp);
            }
        }
               
        while(!roll.empty()){
            last_index = get<1>(roll.front());
            if(get<1>(roll.front()) == location){
                return order + 1;
            }
            roll.pop_front();
            order += 1;
        }
    }
    
    return answer;
}