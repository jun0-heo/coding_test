#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

vector<char> solution(vector<vector<char>> graphs, char start){
    unordered_map<char, vector<char>> map_;
    unordered_map<char, bool> visited;
    vector<char> solutions;
    for (auto graph : graphs){
        map_[graph[0]].push_back(graph[1]);
        visited[graph[0]] = false;
    }
    stack<char> stack_;
    stack_.push(start);

    while(!stack_.empty()){
        char now = stack_.top();
        stack_.pop();
        visited[now] = true;
        solutions.push_back(now);
        for(auto node : map_[now]){
            if(!visited[node]){
                stack_.push(node);
            }
        }
    }
    return solutions;
}

int main(){
    vector<vector<char>> problem1 = {{'A','B'}, {'B','C'}, {'C','D'}, {'D','E'}};
    vector<vector<char>> problem2 = {{'A','B'}, {'A','C'}, {'B','D'}, {'B','E'}, {'C','F'}, {'E','F'}};

    vector<char> answer1 = {'A','B','C','D','E'};
    vector<char> answer2 = {'A','C','F','B','E','D'};

    cout << "problem 1: " << (solution(problem1, 'A') == answer1) << endl;
    for (auto tmp : solution(problem2,'A')){
        cout << tmp << " ";
    }
    cout << endl;
    cout << "problem 2: " << (solution(problem2, 'A') == answer2) << endl;

}