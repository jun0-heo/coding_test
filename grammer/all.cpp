#include<iostream>
#include<string>
#include<map>

using namespace std;


void modify(int& value){
    //call by reference
    value = 20;
}

int auto_func(){
    return 10;
}

int main(){
    // 1. string의 복사
    cout << "======= 1 ========" << endl;
    string str1 = "Hello, World!";
    string str2(str1,0,5); //Hello
    string str3(10 ,'*'); // **********

    cout << str2 << endl;
    cout << str3 << endl;

    // 2. 문자열 찾기 size_t
    cout << "======= 2 ========" << endl;
    size_t where = str1.find("World");
    cout << where << endl;

    // 3. replace
    cout << "======= 3 ========" << endl;
    str1.replace(7,5, "word"); // 글자 수 달라도 상관 없음
    cout << str1 << endl;
    str1.replace(7,4,"World");

    // 4. call by reference
    cout << "======= 4 ========" << endl;
    int value = 10;
    modify(value); // 그대로 넣음
    cout << value << endl;

    // 5. auto, typeid
    cout << "======= 5 ========" << endl;
    auto a = auto_func();
    cout << typeid(a).name() << endl;

    // 6. 범위기반 for문, map
    // for (타입 변수명 : 컨테이너) {}
    cout << "======= 6 ========" << endl;
    vector<int> vec = {1,2,3,4,5};
    for (auto a : vec){
        cout << a << endl;
    }

    map<string, int> fruitMap={{"apple",1}, {"banana",2}, {"cherry",3}};
    for (auto& a : fruitMap){ //const auto&도 괜찮. 복사비용 고려
        cout << a.first << " " << a.second << endl;
    }

}