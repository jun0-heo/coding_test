#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<vector<int>> graphs, int start){
    unordered_map<int, vector<int>> map_;
    unordered_map<int, bool> visited;
    vector<int> solutions;
    for (auto graph : graphs){
        map_[graph[0]].push_back(graph[1]);
        visited[graph[0]] = false;
    }
    queue<int> que;
    que.push(start);
    visited[start] = true;

    while(!que.empty()){
        int now = que.front();
        que.pop();
        solutions.push_back(now);
        for(auto node : map_[now]){
            if(!visited[node]){
                que.push(node);
                visited[node] = true;
            }
        }
    }
    return solutions;
}

int main(){
    vector<vector<int>> problem1 = {{1,2},{1,3},{2,4},{2,5},{3,6},{3,7},{4,8},{5,8},{6,9},{7,9}};
    vector<vector<int>> problem2 = {{0,1},{1,2},{2,3},{3,4},{4,5},{5,0}};

    vector<int> answer1 = {1,2,3,4,5,6,7,8,9};
    vector<int> answer2 = {1,2,3,4,5,0};

    cout << "problem 1: " << (solution(problem1, 1) == answer1) << endl;
    for (auto tmp : solution(problem2,1)){
        cout << tmp << " ";
    }
    cout << endl;
    cout << "problem 2: " << (solution(problem2, 1) == answer2) << endl;

}