// https://school.programmers.co.kr/learn/courses/30/lessons/43162
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
unordered_map<int, vector<int>> map_;
vector<bool> visited;

void dfs(int start){
    stack<int> stack_;
    stack_.push(start);
    while(!stack_.empty()){
        int now = stack_.top();
        stack_.pop();
        visited[now] = true;
        for(auto next : map_[now]){
            if(!visited[next]){
                stack_.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j && computers[i][j]) map_[i].push_back(j);
        }
    }
    visited.assign(n, false);
    int count = 0;
    for(int i=0; i<n; i++){
        if (!visited[i]){
            count += 1;
            dfs(i);
        }
    }
    int answer = count;
    return answer;
}