// https://school.programmers.co.kr/learn/courses/30/lessons/12983
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> smallest;
vector<bool> visited;
vector<string> strs_;
string t_;

int dynamic_programming(int idx){
    if(visited[idx]) return smallest[idx];
    
    int min_ = 20002;
    
    for (auto str: strs_){
        if(idx + 1 <  str.size()) continue;
        if(t_.substr(idx - str.size() + 1,str.size()) == str){
            if (idx < str.size()) continue;
            int cand = dynamic_programming(idx - str.size()) + 1;
            if(cand < min_) {
                min_ = cand;
            }
        }
    }
    
    
    smallest[idx] = min_;
    visited[idx] = true;
    return min_;
}

int solution(vector<string> strs, string t)
{
    smallest.assign(t.size(), 20002);
    visited.assign(t.size(), false);
    // 초깃값 형성
    for (auto str : strs){
        auto findIdx = t.find(str);
        if(findIdx==0){
            smallest[str.size()-1] = 1;
            visited[str.size()-1] = true;
        }
    }
    t_ = t;
    strs_ = strs;
    // 선택 되기는 해야하니까 후보군들 중에서 가장 작은걸 고르는 식으로 앞으로 나아가자?
    int ret = dynamic_programming(t.size()-1);
    if (ret == 20002) return -1;
    int answer = ret;
    return answer;
}