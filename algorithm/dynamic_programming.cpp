// LCS 길이 계산하기
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int solution(string str1, string str2){
    vector<vector<int>> map_(str1.size()+1, vector<int>(str2.size()+1,0));
    for(int i=1; i<str1.size()+1; i++){
        for(int j=1; j<str2.size()+1; j++){
            if(str1[i] == str2[j]) map_[i][j] = map_[i-1][j-1] + 1;
            else {
                map_[i][j] = max(map_[i][j-1], map_[i-1][j]);
            }
        }
    }
    int max_ = 0;
    for (auto vec : map_){
        auto maxIt = max_element(vec.begin(), vec.end());
        max_ = max(max_, *maxIt);
    }
    return max_;
}

int main(){
    vector<vector<string>> problems = {{"ABCBDAB", "BDCAB"}, {"AGGTAB", "GXTXAYB"}};
    vector<int> results = {4,4};

    for(int i=0; i<results.size(); i++){
        int sol = solution(problems[i][0], problems[i][1]);
        cout << (sol == results[i]) << " " << sol << endl;
    }
}