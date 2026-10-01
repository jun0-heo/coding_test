#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

// "HH:MM" -> 분 단위로 변환
int toMinutes(const string& t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    // 차량번호 -> 입차 시각(분). map이라 차량번호 오름차순 자동 정렬
    map<string, int> inTime;
    // 차량번호 -> 누적 주차 시간(분)
    map<string, int> total;

    for (const string& rec : records) {
        string time = rec.substr(0, 5);
        string car  = rec.substr(6, 4);
        string act  = rec.substr(11);     // "IN" 또는 "OUT"

        int cur = toMinutes(time);

        if (act == "IN") {
            inTime[car] = cur;
        } else { // OUT
            total[car] += cur - inTime[car];
            inTime.erase(car);
        }
    }

    // 출차 기록이 없는 차량은 23:59에 출차한 것으로 간주
    int endTime = 23 * 60 + 59; // 1439
    for (auto& p : inTime) {
        total[p.first] += endTime - p.second;
    }

    vector<int> answer;
    for (auto& p : total) {   // map이므로 차량번호 오름차순
        int t = p.second;
        int fee = fees[1];    // 기본 요금
        if (t > fees[0]) {    // 기본 시간 초과 시
            fee += (int)ceil((double)(t - fees[0]) / fees[2]) * fees[3];
        }
        answer.push_back(fee);
    }

    return answer;
}