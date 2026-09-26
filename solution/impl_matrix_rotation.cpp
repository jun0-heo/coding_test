#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows + 1, vector<int>(columns + 1));
    
    // 1부터 순서대로 채우기
    int num = 1;
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            board[i][j] = num++;
    
    for (auto& q : queries) {
        int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
        
        // 테두리 좌표를 시계방향 순서로 수집
        vector<pair<int,int>> coords;
        for (int j = y1; j <= y2; j++) coords.push_back({x1, j});        // 위쪽 변 (왼→오)
        for (int i = x1 + 1; i <= x2; i++) coords.push_back({i, y2});    // 오른쪽 변 (위→아래)
        for (int j = y2 - 1; j >= y1; j--) coords.push_back({x2, j});    // 아래쪽 변 (오→왼)
        for (int i = x2 - 1; i > x1; i--) coords.push_back({i, y1});     // 왼쪽 변 (아래→위)
        
        // 마지막 값을 임시 저장 (한 칸씩 뒤로 밀기 위함)
        int n = coords.size();
        int last = board[coords[n-1].first][coords[n-1].second];
        int minVal = last;
        
        for (int i = n - 1; i > 0; i--) {
            int val = board[coords[i-1].first][coords[i-1].second];
            board[coords[i].first][coords[i].second] = val;
            minVal = min(minVal, val);
        }
        board[coords[0].first][coords[0].second] = last;
        
        answer.push_back(minVal);
    }
    
    return answer;
}