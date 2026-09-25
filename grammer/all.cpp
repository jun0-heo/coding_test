#include<iostream>
#include<string>
#include<map>
#include<algorithm> // find를 쓰기위한 STL , count
#include<set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


void modify(int& value){
    //call by reference
    value = 20;
}

int auto_func(){
    return 10;
}

struct Point{
    int x,y;
    Point(int x, int y) : x(x),y(y) {}
};

bool compare(const Point& a, const Point& b){
    if(a.x == b.x){
        return a.y < b.y; // 작은 순대로 정렬
    }
    return a.x < b.x;
}

struct Compare{
    bool operator()(const Point& a, const Point& b) const{
        if( a.x == b.x ) return a.y > b.y; // compare와 방향이 반대!!!!!!!
        return a.x > b.x;
    }
};

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

    // 7. 반복자, find
    /*
    컨테이너.begin() 시작위치
    컨테이너.end() 끝위치
    컨테이너.find()시 없으면 .end()를 가르친다.
    */
   cout << "======= 7 ========" << endl;
    cout << typeid(vec.begin()).name() << endl;
    // 타입은 컨테이너::iterator ex) vector<int>::iterator

    for (auto it=vec.begin(); it != vec.end(); it++ ){
        cout << *it << " "; // 포인터랑 비슷하게 취급하면 됨
    }
    cout << endl;

    auto it = fruitMap.find("banana"); //map에서는 key로만 찾기 가능
    if (it != fruitMap.end()){
        cout << it->first << " " << it->second << endl;
    } else {
        cout << "not found";
    }

    // 8. vector
    // vecto 삽입 삭제 찾기 복잡도 O(N)
    cout << "======= 8 ========" << endl;
    vector<int> v3(4,3); // {3,3,3,3}
    vector<int> v4(3); // {0,0,0}
    for (auto it = v4.begin(); it != v4.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    // 삽입, 삭제
    v3.push_back(3);

    v3.back();
    v3.pop_back();

    v3.insert(v3.begin(), 1); // {1,3,3,3,3}
    v3.erase(v3.begin()); // {3,3,3,3}
    
    // 9. set
    // 삽입, 삭제, 찾기 복잡도 O(logN)
    set<int> set_ = {3,1,3,2,5}; // {1,2,3,5} 정렬상태 유지
    for(auto it = set_.begin(); it!=set_.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // find와 erase도 쓸 수 있다
    auto setIt = set_.find(3);
    if (setIt != set_.end()){
        set_.erase(setIt);
    }

    // 10. map
    cout << "======= 10 ========" << endl;
    //map 삽입, 삭제, 찾기 시간복잡도 O(logN)
    /*
    map은 추가로 find말고 []로도 특정 키에 접근할 수 있는데 만약 없는 키에 접근하면 만들어진다. 
    그게 싫으면 find를 써라
    */ 
    // map 삽입의 두가지 방법
    map<int, string> map_10;
    map_10.insert(make_pair(1,"Apple"));
    map_10.insert({2,"Banana"});
    map_10[3] = "Cherry";
    
    //map 삭제의 두가지 방법
    map_10.erase(2); //키삭제
    auto it_10 = map_10.find(3);
    if(it_10!=map_10.end()) {
        map_10.erase(it_10);
    }

    // unordered set, unordered_map은 최악은 O(N)이지만 그런 경우는 잘 없고 O(1)이 되는 경우가 많아
    // 정렬이 필요하지 않을 때 더 효율적일 때가 많다.

    // 11.STL
    cout << "======= 11 ========" << endl;
    //count(시작it, 끝it, 찾을 것) -> int (몇번 나타나는지)
    vector<int> vec_11 = {1,2,3,4,5,4,5};
    cout << count(vec_11.begin(),vec_11.end(), 5) << endl; //2

    /*
    sort(시작it, 끝it) //오름차순(작은것부터)
    sort(시작it, 끝it, compare) // compare가 false일때 원소를 바꿈
    */
   /*
   struct Point{
        int x,y;
        Point(int x, int y) : x(x),y(y) {} 
    };

    bool compare(const Point& a, const Point& b){
        if(a.x == b.x){
            return a.y < b.y; // 작은 순대로 정렬
        }
        return a.x < b.x;
    }
    */

   vector<Point> points = {{3,4}, {1,2}, {3,1}, {2,5}};
   sort(points.begin(), points.end(), compare);

   for (const Point&p: points){
    cout << "(" << p.x << ", " << p.y << ") ";
   }
   cout << endl;

   //next_permutation(시작it, 끝it) 있으면 true, 없으면 false, 가능 순열 한개씩 반환

   vector<int> vec_11_1 = {1,2,3}; //사전순 정렬필요
   do{
    for (int i: vec_11_1){
            cout << i << " ";
        }
        cout << endl;
    } while(next_permutation(vec_11_1.begin(),vec_11_1.end()));

    // unique
    // unique(시작it, 끝it) -> 새로운 끝it
    // unique 한 것들로 뽑고 나머지는 의미 없는 값이 된다. 반환은 unique한 것까지의 it
    // 서로 붙어있는 중복 요소만 제거하므로 다 제거하려면 정렬필요

    vector<int> vec_11_2 = {1,2,2,3,3,3,4,4,5,5,5};

    auto newEnd = unique(vec_11_2.begin(), vec_11_2.end());
    for(auto it=vec_11_2.begin(); it!=newEnd; it++){
        cout << *it << " ";
    }
    cout << endl; // 1 2 3 4 5

    for(auto it=vec_11_2.begin(); it!=vec_11_2.end(); it++){
        cout << *it << " ";
    }
    cout << endl; // 1 2 3 4 5 3 4 4 5 5 5 뒷부분은 그대로 남음. 의미없는 값이됨

    //binary_search
    // 이미 정렬 되어있는 것에서만 쓸 수 있고 O(logN)
    // binary_search(시작it, 끝it, 찾을 수) -> 있으면 true 없으면 false
    
    //max_element, min_element
    // max_element(시작it, 끝it); -> max이곳의 it

    vector<int> vec_11_3 = {1,3,5,7,2,4,6};

    auto maxIt = max_element(vec_11_3.begin(),vec_11_3.end());
    auto minIt = min_element(vec_11_3.begin(),vec_11_3.end());

    cout << *maxIt << endl;
    cout << *minIt << endl;

    // 12. vector값은 변수로 선언해도 된다.
    int N;
    cin >> N;
    vector<int> vec_12(N);

    // 13. queue
    cout << "======= 13 ========" << endl;
    queue<int> que;
    // 뒤에 삽입
    que.push(0);
    que.push(1);
    // 크기
    que.size();
    que.front(); // 0
    // 가장 뒤 조회하기
    que.back();
    // 제일 앞 조회 및 제거
    while(!que.empty()){
        cout << que.front() << " "; // queue는 front stack은 top (제일 뒤)
        que.pop();
    }
    cout << endl;

    // 14. stack
    cout << "======= 14 ========" << endl;
    stack<int> stack_;
    stack_.push(10);
    stack_.push(20);
    // 조회
    stack_.size();
    stack_.top(); // 20
    while(!stack_.empty()){
        cout << stack_.top() << " ";
        stack_.pop();
    }
    cout << endl;

    //15. priority_queue
    cout << "======= 15 ========" << endl;
    // priority_queue<vector<저장할 자료형, 내부 컨테이너, compare> pq;
    // priority_queue<Point, vector<Point>, decltype(compare)*> pq(compare);
    priority_queue<Point,vector<Point>,Compare> pq;
    
    for (const Point& points_ : points){
        pq.push(points_);
    }
    while(!pq.empty()){
        cout << "(" << pq.top().x << ", " << pq.top().y << ") ";// priority queue는 top으로 조회
        pq.pop();
    }
    cout << endl;
}
