#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 정수 N을 입력받아 1부터 N까지의 숫자 중에서 합이 10이 되는 조합을 배열로 반환하는 solution() 함수를 작성하시오.
void print(vector<vector<int>> vec){
    cout << "[";
    for(int i=0; i<vec.size(); i++){
        cout << "[ ";
        for(int j=0; j<vec[i].size(); j++){
            cout << vec[i][j] << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;
}

vector<vector<int>> solutions;


void back_tracking(int current, vector<int> track, vector<int> visited_, int sum_, int goal, int N){
    if(find(visited_.begin(),visited_.end(),current) != visited_.end()) return;
    track.push_back(current);
    sum_ += current;
    if(sum_ > goal) {
        return;
    } 
    
    if (sum_ == goal) {
        solutions.push_back(track);
        return;
    }
        
    for(int i=current + 1; i<=N; i++){
        if(find(visited_.begin(),visited_.end(),i) == visited_.end())
            visited_.push_back(current);
            back_tracking(i, track, sum_, goal, N);
            visited_.pop_back();
    }
}

void solution(int N) {
    visited_.clear();
    for(int j=0; j<solutions.size(); j++){
        solutions[j].clear();
    }
    solutions.clear();
    for(int i=1; i<=N; i++){
        back_tracking(i, {}, {}, 0, 10, N);
    }
}

int main() {
    solution(7);
    print(solutions);
    return 0;
}