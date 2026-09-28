#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> strs, string t) {
    int n = t.size();
    const int INF = n + 1;              // 어떤 정답보다도 큰 값 = 불가능
    vector<int> dp(n + 1, INF);
    dp[0] = 0;                          // 빈 접두부는 0개

    for (int i = 1; i <= n; i++) {
        for (const string& s : strs) {         // 참조로 순회, 복사 없음
            int L = (int)s.size();
            if (L <= i && dp[i - L] != INF &&  // 도달 가능한 상태에서만
                t.compare(i - L, L, s) == 0) { // 할당 없는 비교
                dp[i] = min(dp[i], dp[i - L] + 1);
            }
        }
    }
    return dp[n] == INF ? -1 : dp[n];
}