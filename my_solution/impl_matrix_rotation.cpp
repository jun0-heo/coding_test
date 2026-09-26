#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int content = 1;
    vector<vector<int>> map_(rows, vector<int>(columns));
    for(int i=0; i<rows ; i++){
        for(int j= 0; j<columns; j++){
            map_[i][j] = content;
            content++;
        }
    }
    for(auto query: queries){
        int x1 = query[0]-1;
        int y1 = query[1]-1;
        int x2 = query[2]-1;
        int y2 = query[3]-1;
       
        vector<pair<int,int>> points;
        deque<int> values;
        pair<int,int> start = {x1,y1};
        vector<pair<int,int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
        pair<int,int> current = start;
        int idx = 0;
        int minimum_ = 10001;
        
        while(points.empty() || start != current){
            points.push_back(current);
            int value = map_[current.first][current.second];
            if (value < minimum_){
                minimum_ = value;
            }
            values.push_back(value);
            pair<int,int> next = {current.first + moves[idx].first , current.second + moves[idx].second};
            if (!(next.first >=x1 && next.first <= x2 && next.second >= y1 && next.second <= y2)){
                idx += 1;
            }
            current = {current.first + moves[idx].first , current.second + moves[idx].second};
        }
        answer.push_back(minimum_);
        int tmp = values.back();
        values.pop_back();
        values.push_front(tmp);
        
        for(auto [x, y] : points){
            map_[x][y] = values.front();
            values.pop_front();
        }
        
    }
   
    return answer;
}