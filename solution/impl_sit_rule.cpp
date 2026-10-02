#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

bool check(const vector<string>& room) {
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    int n = room.size();
    int m = room[0].size();

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (room[r][c] != 'P') continue;

            vector<vector<bool>> visited(n, vector<bool>(m, false));
            visited[r][c] = true;
            queue<tuple<int, int, int>> q;
            q.push(make_tuple(r, c, 0));

            while (!q.empty()) {
                int y, x, d;
                tie(y, x, d) = q.front();
                q.pop();
                if (d == 2) continue;

                for (int k = 0; k < 4; k++) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                    if (visited[ny][nx] || room[ny][nx] == 'X') continue;
                    if (room[ny][nx] == 'P') return false;
                    visited[ny][nx] = true;
                    q.push(make_tuple(ny, nx, d + 1));
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (const auto& room : places) {
        answer.push_back(check(room) ? 1 : 0);
    }
    return answer;
}