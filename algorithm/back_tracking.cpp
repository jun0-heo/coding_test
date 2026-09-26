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

vector<vector<int>> solution(int N) {
    for(int j=0; j<solutions.size(); j++){
        solutions[j].clear();
    }
    solutions.clear();
}

int main() {
    print(solution(7));
    return 0;
}