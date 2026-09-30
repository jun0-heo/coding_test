// https://school.programmers.co.kr/learn/courses/30/lessons/72410
#include <string>
#include <vector>
#include<iostream>
#include<unordered_map>
using namespace std;

// 영어는 26쌍, 둘 차이는 32

string solution(string new_id) {
    // vector<char> vec= {'a','z','A','Z'}; // 97, 122, 65, 90
    
    // for(char& c : vec){
    //     cout << c << ": " << c - '0' << endl;
    // }
    // 1단계 -> 2단계 -> 3단계
    string new_str;
    for(char& c : new_id){
        char ans = 0;
        if(c>='A' && c<='Z') {
            ans = (char)(c + 32);
        } else if(c=='.'){
            if(!new_str.empty() && new_str.back()=='.') {continue;}
            ans = c;
        } else if(!(c=='-' || c=='_' || (c>='a'&&c<='z') || (c>='0'&&c<='9'))){
            continue;
        } else {
            ans = c;
        }
        if(ans) new_str += ans;
    }
    // 4단계
    if(new_str.front() == '.') new_str.erase(0,1);
    if(new_str.back() == '.') new_str.erase(new_str.size()-1,1);
    // 5단계
    if(new_str.empty()) new_str += 'a';
    //6단계
    if(new_str.size() > 15) new_str = new_str.substr(0,15);
    if(new_str.back() == '.') new_str.erase(new_str.size()-1,1);
    //7단계
    if(new_str.size() <= 2) {
        char last = new_str.back();
        string tmp(3-(int)(new_str.size()),last);
        new_str += tmp;
    }
    
    return new_str;
}