// 풀이 1
#include <string>

using namespace std;

int solution(string word) {
    const string vowels = "AEIOU";
    const int weight[5] = {781, 156, 31, 6, 1};

    int answer = 0;
    for (int i = 0; i < (int)word.size(); i++) {
        answer += vowels.find(word[i]) * weight[i] + 1;
    }
    return answer;
}
// // 풀이 2
// #include <string>

// using namespace std;

// const string vowels = "AEIOU";
// int cnt = 0;
// int result = 0;

// void dfs(string cur, const string& target) {
//     if (result) return;               // 이미 찾았으면 종료
//     if (!cur.empty()) {
//         cnt++;
//         if (cur == target) {
//             result = cnt;
//             return;
//         }
//     }
//     if (cur.size() == 5) return;

//     for (char c : vowels) {
//         dfs(cur + c, target);
//     }
// }

// int solution(string word) {
//     cnt = 0;
//     result = 0;
//     dfs("", word);
//     return result;
// }