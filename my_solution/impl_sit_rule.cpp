https://school.programmers.co.kr/learn/courses/30/lessons/81302#fn1
#include <string>
#include <vector>
#include <utility>

using namespace std;
// P: 응시자 O: 빈자리 X: 파티션

vector<pair<int,int>> lists = {{-2,0},{-1,-1},{-1,0},{-1,1},{0,-2},{0,-1},{0,1},{0,2},{1,-1},{1,0},{1,1},{2,0}};

bool in_range(int x, int y){
    if(x>=0 && x<5 && y>=0 && y<5) return true;
    return false;
}

bool is_blocked(vector<vector<char>> map_, int x, int y, int nx, int ny){
    if(x==nx){
        if(map_[x][(y+ny)/2] != 'X') return false;
    } else if(y==ny) {
        if(map_[(x+nx)/2][y] != 'X') return false;
    } else {
        if(!(map_[x][ny] == 'X' && map_[nx][y] == 'X')) return false;
    }
    return true;
}

int result(vector<string> place){
    vector<vector<char>> map_(5, vector<char>(5));
    vector<pair<int,int>> inspect;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            char tmp = place[i][j];
            map_[i][j] = tmp;
            if(tmp == 'P') inspect.push_back({i,j});
        }
    }
    
    for(auto [x,y] : inspect){
        for(auto [dx,dy] : lists){
            int nx = x+dx; 
            int ny = y+dy;
            if(in_range(nx, ny)){
                if(map_[nx][ny]=='O'||map_[nx][ny]=='X') continue;
                if(!is_blocked(map_,x,y,nx,ny)){
                    return 0;
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto place : places){
        answer.push_back(result(place));
    }
    return answer;
}