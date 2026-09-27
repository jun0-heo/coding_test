// https://school.programmers.co.kr/learn/courses/30/lessons/87946#
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//k	    dungeons	                result
//80	[[80,20],[50,40],[30,10]]	3
//[최소 필요 피로도, 소모 피로도]

int max_ = 0;
vector<bool> visited;
bool compare(const vector<int>& v1, const vector<int>& v2){
    if (v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] > v2[0];
}

void back_tracking(int current_k, vector<vector<int>> dungeons,int num){
    for (int i=0; i<dungeons.size(); i++){
        if(current_k >= dungeons[i][0] && !visited[i] ){
            if (num+1 > max_){
                max_ = num+1;
            }
            visited[i] = true;
            back_tracking(current_k-dungeons[i][1], dungeons, num+1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    visited.assign(dungeons.size(), false);
    back_tracking(k, dungeons, 0);
    int answer = max_;
    return answer;
}