#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;
// dfs를 재귀함수로 구현

vector<char> solutions;
unordered_map<char, bool> visited;

void dfs_func(char now, unordered_map<char, vector<char>> map_){
    solutions.push_back(now);
    visited[now] = true;
    for(auto now_map : map_[now]){
        if(!visited[now_map]){
            dfs_func(now_map, map_);
        }
    }
}

vector<char> solution(vector<vector<char>> graphs, char start){
    solutions.clear();
    unordered_map<char, vector<char>> map_;
    visited.clear();
    for(auto graph : graphs){
        map_[graph[0]].push_back(graph[1]);
        visited[graph[0]] = false;
    }
    dfs_func(start, map_);

    return solutions;
}

int main(){
    vector<vector<char>> problem1 = {{'A','B'}, {'B','C'}, {'C','D'}, {'D','E'}};
    vector<vector<char>> problem2 = {{'A','B'}, {'A','C'}, {'B','D'}, {'B','E'}, {'C','F'}, {'E','F'}};

    vector<char> answer1 = {'A','B','C','D','E'};
    vector<char> answer2 = {'A','B','D','E','F','C'};

    cout << "problem 1: " << (solution(problem1, 'A') == answer1) << endl;
    for (auto tmp : solution(problem2,'A')){
        cout << tmp << " ";
    }
    cout << endl;
    cout << "problem 2: " << (solution(problem2, 'A') == answer2) << endl;

}