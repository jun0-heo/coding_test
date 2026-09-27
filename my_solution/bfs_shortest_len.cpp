// https://school.programmers.co.kr/learn/courses/30/lessons/1844
#include<vector>
#include<queue>
#include<utility>
#include<tuple>
using namespace std;
// [0,0] -> [n-1, m-1]
// 1이 벽 없는 자리
vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
vector<vector<bool>> visited;
int N,M;

bool in_range(int x, int y){
    if(x>=0 && x<N && y>=0 && y<M) return true;
    return false;
}

int bfs(vector<vector<int>> maps){
    queue<tuple<int,int,int>> que;
    que.push({0, 0, 1});
    visited[0][0] = true;
    while(!que.empty()){
        auto [x,y,num] = que.front();
        que.pop();
        if (x==N-1 && y==M-1) return num;
        for(auto [dx, dy] : directions){
            int nx = x + dx;
            int ny = y + dy;
            if(in_range(nx, ny) && !visited[nx][ny] && maps[nx][ny]){
                visited[nx][ny] = true;
                que.push({nx,ny,num+1});
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    N = maps.size();
    M = maps[0].size();
    visited.assign(N, vector<bool>(M,false));
    int answer = bfs(maps);
    return answer;
}