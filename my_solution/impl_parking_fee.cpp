// https://school.programmers.co.kr/learn/courses/30/lessons/92341?language=cpp
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

// fees : [180, 5000, 10, 600] // 기본시간, 기본요금 , 단위시간, 단위요금
// recoreds : ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"] // "시각 차량번호 내역"
// result : [14600, 34400, 5000]
// 차량번호가 작은 자동차부터 청구할 주차요금 정산

const int last_time = 23*60 + 59;

int calculate(vector<int> fees, vector<int> values){
    // for (auto val: values){
    //     cout << val << " ";
    // }
    // cout << endl;
    int min_time = fees[0];
    int min_fee = fees[1];
    int unit_time = fees[2];
    int unit_fee = fees[3];
    
    int size_ = values.size();
    int sum_ = 0;
    
    if(size_%2 !=0){
        sum_ += (last_time - values[size_-1]);
        values.pop_back();
    }
   
    for(int i=0; i<values.size(); i=i+2){
        sum_ += values[i+1] - values[i];
    }
    
    // 기본 시간보다 적으면 그냥 기본 요금 반환
    
    if(sum_ <= min_time) return min_fee;
    
    int fee = min_fee + ((sum_-min_time) / unit_time ) * unit_fee;
    if((sum_-min_time)%unit_time != 0) fee += unit_fee;
    
    return fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int,vector<int>> map_;
    for(auto record : records){
        int hour = stoi(record.substr(0,2));
        int minute = stoi(record.substr(3,2));
        int car_num = stoi(record.substr(6,4));
        
        map_[car_num].push_back(60*hour + minute);
        
    }

    for(auto [_,values] : map_){
        sort(values.begin(), values.end());
        answer.push_back(calculate(fees, values));
    }
    return answer;
}