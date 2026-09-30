#include <string>

using namespace std;

string solution(string new_id) {
    string s;

    // 1~3단계: 소문자화 + 허용 문자만 + 연속 마침표 제거를 한 번에
    for (char c : new_id) {
        c = tolower(c);
        if (c == '.') {
            if (!s.empty() && s.back() == '.') continue;  // 연속 마침표 스킵
        } else if (!((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||
                     c == '-' || c == '_')) {
            continue;  // 허용되지 않은 문자 제거
        }
        s += c;
    }

    // 4단계: 처음/끝의 마침표 제거
    if (!s.empty() && s.front() == '.') s.erase(s.begin());
    if (!s.empty() && s.back() == '.') s.pop_back();

    // 5단계: 빈 문자열이면 "a"
    if (s.empty()) s = "a";

    // 6단계: 16자 이상이면 앞 15자만, 끝이 '.'이면 제거
    if (s.size() >= 16) {
        s = s.substr(0, 15);
        if (s.back() == '.') s.pop_back();
    }

    // 7단계: 2자 이하이면 마지막 문자 반복해 3자로
    while (s.size() <= 2) s += s.back();

    return s;
}