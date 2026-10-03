// https://school.programmers.co.kr/learn/courses/30/lessons/84512
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<char> characters = {'U','O','I','E','A'};

int count = 0;

int solution(string word) {
    int answer = 0;
    stack<string> words;
    for (auto character : characters){
        words.push(string(1,character));    
    }
    while(!words.empty()){
        string now = words.top();
        words.pop();
        count += 1;
        if (now == word) return count;
        if (now.size() == 5) continue;
        for(auto character : characters){
            now += character;
            words.push(now);
            now.pop_back();
        }
    }
    
    return answer;
}