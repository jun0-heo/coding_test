#include<iostream>
#include<string>
#include<map>
#include<algorithm> // find를 쓰기위한 STL , count
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<tuple>
#include<cmath>    // fmod
#include<cstdlib>  // div
#include<unordered_map> // unordered_map 순서 보장 없음 예제
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
    v3.insert(v3.begin()+1, 2); // {1,2,3,3,3,3}
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
    sort(시작it, 끝it) //오름차순(작은것부터) , 첫번째 요소가 같으면 두번째 . . .
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

    // binary_search
    // 이미 정렬 되어있는 것에서만 쓸 수 있고 O(logN)
    // binary_search(시작it, 끝it, 찾을 수) -> 있으면 true 없으면 false
    
    // max_element, min_element
    // max_element(시작it, 끝it); -> max이곳의 it

    vector<int> vec_11_3 = {1,3,5,7,2,4,6};

    auto maxIt = max_element(vec_11_3.begin(),vec_11_3.end());
    auto minIt = min_element(vec_11_3.begin(),vec_11_3.end());

    cout << *maxIt << endl; // 7
    cout << *minIt << endl; // 1

    //vector/deque/array → begin/end 가능
    // queue/stack/priority_queue → begin/end 없음

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

    // 16. tuple과 priority_queue
    cout << "======= 16 ========" << endl;

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq2; 
    // tuple은 greater로 오름차순 정렬 가능
    // 앞에 값이 같으면 뒤에 값으로 순차 비교
    
    // 삽입
    pq2.push({1,2,3}); // 됨
    pq2.push({1,2,1});
    pq2.push({2,1,1});

    // 조회, 삭제
    while(!pq2.empty()){
        auto [a, b, c] = pq2.top(); // tuple은 구조분해할당 가능
        cout << "(" << a << ", " << b << ", " << c << ") ";
        pq2.pop();
    }
    cout << endl;

    // tuple 각 번호 조회
    tuple<int,int,int> t = {1,2,3};
    cout << get<0>(t) << endl; // 1

    // 17. deque
    cout << "======= 17 ========" << endl;
    deque<int> deq;
    deq.push_back(1);
    deq.push_front(2);
    deq.push_back(3);
    for (const auto& e : deq){
        cout << e << " ";
    }
    cout << endl;

    deq.front(); //2
    deq.back(); //3
    deq.pop_back();
    deq.pop_front();
    for (const auto& e : deq){
        cout << e << " ";
    }
    cout << endl;

    // 18. container 복사하기
    queue<int> que1 = que; // 표준 컨테이너 (vector, deque, list, queue, stack, priority_queue, set, map, unordered_set, unordered_map) 는 복사 가능

    // 19. iterator로 index 구하기
    vector<int> v = {1, 3, 5, 2};

    maxIt = max_element(v.begin(), v.end());
    auto idx = maxIt - v.begin();   // idx는 ptrdiff_t
    cout << idx << endl;            // 2

    // 20. pair
    cout << "======= 20 ========" << endl;
    pair<int,int> pair_ = {1,2}; //초기화
    cout << pair_.first << " " << pair_.second << endl;

    vector<pair<int,int>> vp = {{1,2},{3,4},{5,6}};
    vp.push_back({7,8}); // 이렇게 넣기 가능
    for (const auto& [first, second] : vp){ // 구조 분해 가능
        cout << first << " " << second << endl;
    } 

    // pair끼리 비교시 사전순으로 x가 같으면 y로 비교
    // pair는 ==, !=, <, >, <=, >= 연산자 사용 가능
    // 대부분의 표준 컨테이너가 원소가 비교 가능하면 비교가 가능

    pair<int, int> p1 = {1, 2};
    pair<int, int> p2 = {1, 3};

    if (p1 < p2) {
        cout << "p1이 더 작음";
    }

    // 덧셈은 안됨.
    pair<int,int> sum = {p1.first + p2.first, p1.second + p2.second};

    cout << sum.first << " " << sum.second << endl;

    // maximum_element(vector<pair<int,int>)) 도 가능하다
    vector<pair<int,int>> pairs = {p1,p2};
    max_element(pairs.begin(), pairs.end());

    // 21. 다차원 vector 초기화
    cout << "======= 21 ========" << endl;
    int rows = 3;
    int columns = 4;
    int depth = 5;
    vector<vector<int>> vec21(rows, vector<int>(columns));

    // 안쪽부터 중첩해서 쌓으면 된다. 
    //depth x rows x columns
    vector<vector<vector<int>>> vec21_1(
        depth,
        vector<vector<int>>(rows, vector<int>(columns))
     );

    // 4차원: layers x depth x rows x columns
    int layers = 5;

    vector<vector<vector<vector<int>>>> vec21_2(
        layers,
        vector<vector<vector<int>>>(
            depth,
            vector<vector<int>>(rows, vector<int>(columns, 0)) //0은 초깃값
        )
    );

    // 22. vector의 할당과 초기화
    cout << "======= 22 ========" << endl;
    // vector를 그냥 선언했다가 크기를 알았을 때
    vector<int> v22;
    v22.resize(5);

    // vector를 그냥 선언했다가 크기를 알고 같은값으로 초기화 하려할때
    vector<bool> v22_1;
    v22_1.assign(5, false);
    for(auto value: v22_1){
        cout << value << " ";
    }
    cout << endl;

    // 2차원 이상에서도 assign 초기화 할때랑 마찬가지로 가능하다.
    vector<vector<bool>> v22_2;
    v22_2.assign(rows, vector<bool>(columns,false));

    vector<vector<vector<int>>> v22_3;
    v22_3.assign(2, vector<vector<int>>(3, vector<int>(4, 0))); // 2x3x4

    // 23. string
    cout << "======= 23 ========" << endl;
    // string 초기화
    string s;
    string s2(2,'c'); // "cc"
    string c3 = "string";

    // 자주 쓰는 것들
    s2.size();
    s2.empty();

    s2[0]; //char
    s2.at(0); // 범위 체크 포함. 범위에 없으면 예외를 던짐. 예외 잡는 부분이 없으면 강제종료
    s2.front();
    s2.back();

    s += " world"; //빈 문자열에 + 연산 가능
    s.append("!"); //string 만
    s.push_back('?'); //char만

    s.substr(0,3); // 0부터 3글자
    s.find("or"); //"or"가 시작되는 위치 반환 (없으면 string::npos); bool로 따지면 true이기 때문에 직접 비교해야한다.

    cout << s << endl;

    s.clear();

    // char을 string으로 변환하는법
    char tmp = 'c';
    string s4(1, tmp);
    cout << s4 << endl;

    string str23 = "hello";
    char character = str23[-1];
    str23.pop_back();
    str23 += character;
    str23.erase(0,1); // 0번째 index부터 길이 1을 지운다

    cout << str23 << endl;

    // 24.min, max 사용법
    cout << "======= 24 ========" << endl;
    min({1,2,3}); //min은 여러개를 중괄호로 묶으면 사용할 수 있다.

    // 25. string compare
    cout << "======= 25 ========" << endl;
    string s25 = "banana";
    string s25_1 = "nana";

    // 1. 전체 vs 전체
    // a.compare(b);

    // 2. a의 [pos, pos+len) 구간 vs b 전체
    // a.compare(pos, len, b);

    // 3. a의 구간 vs b의 구간
    // a.compare(pos1, len1, b, pos2, len2);

    cout << s25.compare(2,4, s25_1) << endl;
    cout << s25.compare(2,3, s25_1, 0,3) << endl;

    //26. 대문자와 소문자
    vector<char> char_vec= {'0', 'a','z','A','Z'}; // 48, 97, 122, 65, 90
    
    for(char& c : char_vec){
        cout << c << ": " << c - '0' << endl; // 이 경우 c - '0' 은 signed int
    }

    cout << 'A' + 32 << endl;

    // 27. string find (범위 지정)
    cout << "======= 27 ========" << endl;
    string s27 = "aXbXcXd"; // X는 index 1,3,5
    // find(무엇, pos): pos부터 "끝까지" 검색. 시작점 제한 O, 끝 제한 X
    size_t pos27 = s27.find('X', 3); //3
    cout << pos27 << endl;
    // rfind(무엇, pos): pos 이하 구간을 "뒤에서부터". 반환은 항상 앞쪽 index
    cout << s27.rfind('X', 4) << endl; //3

    /*
    임의의 [lo, hi) 구간을 한 번에 지정하는 string::find 는 없다.
    시작점은 pos 로, 끝은 반환값을 hi와 비교해서 만든다. (npos 체크 먼저!)
    */
    size_t lo = 4, hi = 6;
    size_t hit = s27.find('X', lo);
    if (hit != string::npos && hit < hi) { // hit < hi 만 쓰면 p+1 오버플로 위험
        cout << "range hit at " << hit << endl; //5
    }
    // 진짜 구간 제한: std::search(반복자) 또는 substr 로 잘라서 find
    string needle27 = "X"; // 같은 객체의 begin/end 여야 함 (임시 두 개를 섞으면 UB)
    auto it27 = search(s27.begin()+lo, s27.begin()+hi, needle27.begin(), needle27.end());
    if (it27 != s27.begin()+hi) cout << "search at " << (it27 - s27.begin()) << endl; //5

    /*
    find 반환 타입은 size_t(unsigned, string::size_type). 없으면 string::npos.
    npos = (size_t)-1 = 18446744073709551615. int에 담지 말 것.
    unsigned라서 pos >= 0 은 항상 참이라 무의미.
    */
    static_assert(is_same_v<decltype(s27.find('X')), size_t>);
    cout << s27.find("ZZZ") << endl; // 그냥 찍으면 거대한 값, !=string::npos 로 비교해야

    // _of 계열은 문자 하나하나의 "집합"을 찾는다. "lo" 문자열 찾기가 아니다
    cout << s27.find_first_of("Xb") << endl; //1 ('X' 또는 'b')
    cout << s27.find_first_not_of("aX") << endl; //3

    // 모든 위치 순회: 찾은 위치 그대로 다시 넘기면 제자리라 pos++ 필수
    string s27b = "a.b.c.d";
    size_t pos27b = 0;
    while ((pos27b = s27b.find('.', pos27b)) != string::npos) {
        cout << pos27b << " "; // 1 3 5
        pos27b++;
    }
    cout << endl;

    /*
    함정: string::find 는 size_t + npos, std::find(algorithm) 는 iterator + end().
    두 개를 섞으면 npos 대신 end()를 비교하는 실수가 난다.
    */
    vector<int> v27 = {1,2,3};
    auto fit27 = find(v27.begin(), v27.end(), 5);
    if (fit27 == v27.end()) cout << "std::find not found -> end()" << endl;

    // 28. for문 여러 칸 건너뛰기
    cout << "======= 28 ========" << endl;
    // 세번째 자리는 "매 반복 후 실행"이라 i = i + 2 도 되지만 관용적으론 i += 2
    for (int i = 0; i < 10; i += 2) cout << i << " "; // 0 2 4 6 8
    cout << endl;
    for (int i = 10; i > 0; i -= 2) cout << i << " "; // 10 8 6 4 2
    cout << endl;

    // 2개씩 짝지어 순회: 마지막 원소 누락 주의 -> i + 1 < size
    vector<int> v28 = {1,2,3,4,5,6};
    for (size_t i = 0; i + 1 < v28.size(); i += 2)
        cout << "(" << v28[i] << "," << v28[i+1] << ") "; // (1,2) (3,4) (5,6)
    cout << endl;

    /*
    함정: size_t는 unsigned라 i >= 0 이 항상 참 -> 역순으로 -= 하면 무한루프.
    역순은 int로 받고 (int)v.size()-1 에서 시작.
    */
    for (int i = (int)v28.size()-1; i >= 0; i -= 2) cout << v28[i] << " "; // 6 4 2
    cout << endl;

    // 29. 나누기와 나머지(%)
    cout << "======= 29 ========" << endl;
    cout << 7 % 3 << endl;    // 1
    /*
    % 결과 부호는 "왼쪽 피연산자(피제수)"를 따른다. 수학적 modulo와 다르다.
      -7 % 3  == -1   (파이썬은 2)
       7 % -3 ==  1
    */
    cout << -7 % 3 << endl;   // -1

    // 음수도 항상 0 이상인 나머지가 필요할 때(코테 단골)
    auto mod = [](int x, int m){ return ((x % m) + m) % m; };
    cout << mod(-7, 3) << endl; // 2

    // % 는 정수 전용. 실수는 fmod
    cout << fmod(7.5, 2.0) << endl; // 1.5

    // 몫과 나머지를 한번에
    div_t d29 = div(7, 3);
    cout << d29.quot << " " << d29.rem << endl; // 2 1

    // 홀수 판정은 n % 2 != 0 (n % 2 == 1 은 음수 홀수에서 false: -3 % 2 == -1)
    // x / 0, x % 0 은 UB(크래시). 나누기 전 0 체크.
    // 큰 수 모듈러는 오버플로 주의: 100000 * 100000 % 7 은 틀린 값(3), long long 으로.
    cout << 100000LL * 100000 % 7 << endl; // 1

    // 30. map 순회 순서
    cout << "======= 30 ========" << endl;
    map<string,int> map_30;
    map_30["banana"] = 2; map_30["apple"] = 1; map_30["cherry"] = 3; // 일부러 뒤죽박죽 삽입
    // map은 레드-블랙 트리라 "비교자가 정한 순서"를 유지. begin()이 가장 작은 키.
    for (auto [k, val] : map_30) cout << k << " "; // apple banana cherry (삽입순서 아님)
    cout << endl;

    // 비교자를 바꾸면 순서도 바뀐다 -> "무조건 오름차순"이 아니라 비교자 순서
    map<int,string, greater<int>> map_30g;
    map_30g[1] = "a"; map_30g[10] = "b"; map_30g[5] = "c";
    for (auto [k, val] : map_30g) cout << k << " "; // 10 5 1 (내림차순)
    cout << endl;

    // unordered_map 은 해시 기반이라 순서를 보장하지 않음
    unordered_map<int,int> umap_30;
    umap_30[7] = 1; umap_30[1] = 2; umap_30[4] = 3;
    cout << umap_30.size() << endl; // 순서는 구현마다 다름(정렬 순회 X)

    // 구조분해 바인딩도 auto 로 받으면 매 반복 복사한다. 읽기만 하면 const auto&
    for (const auto& [k, val] : map_30) { (void)k; (void)val; } // 복사 없이 순회

    // 31. vector erase / pop_back
    cout << "======= 31 ========" << endl;
    vector<int> v31 = {1,2,3,4,5};
    v31.pop_back(); // {1,2,3,4}  맨 뒤 삭제, O(1). 반환은 void (지운 값 안 돌려줌)

    // 값이 필요하면 먼저 조회: int last = v31.back(); v31.pop_back();
    int last31 = v31.back();
    v31.pop_back();
    cout << last31 << endl; // 3

    /*
    erase 는 위치를 "iterator" 로 받는다. 인덱스로는 못 지운다.
    v31.erase(2);            // ❌ 컴파일 에러
    v31.erase(v31.begin()+2) // ✅ 인덱스 2
    (map/set 의 erase 만 키로도 지울 수 있다)
    */
    v31.erase(v31.begin()); // 맨 앞 삭제, O(N) (뒤 원소를 전부 당김)

    // 범위 삭제는 [first, last) 반열림
    vector<int> v31b = {1,2,3,4,5};
    v31b.erase(v31b.begin()+1, v31b.begin()+3); // {1,4,5}

    // 전체 삭제
    vector<int> v31c = {1,2,3};
    v31c.clear();

    // erase 는 지운 자리의 "다음" iterator를 반환한다 -> 반복 중 삭제 시 이걸로 갱신
    vector<int> v31d = {1,2,3,4,3};
    for (auto it = v31d.begin(); it != v31d.end(); ) {
        if (*it == 3) it = v31d.erase(it); // 안 받고 ++it 하면 무효 iterator(UB)
        else ++it;
    }
    cout << v31d.size() << endl; // 3

    /*
    std::remove 는 "지우지 않는다". 값을 뒤로 밀고 새 끝 iterator만 반환.
    실제 삭제는 erase 와 반드시 세트로 (erase-remove 관용구).
    std::remove_if 로 조건 삭제.
    */
    vector<int> v31e = {1,2,2,3,2,4};
    v31e.erase(remove(v31e.begin(), v31e.end(), 2), v31e.end()); // {1,3,4}
    // C++20 이면 std::erase(v31e, 2) 한 줄

    // 맨 앞 삭제가 잦으면 vector 대신 deque (pop_front O(1))
    deque<int> dq31 = {1,2,3};
    dq31.pop_front();

    // 32. pop_back / erase 요약
    cout << "======= 32 ========" << endl;
    vector<int> v32 = {1,2,3};
    v32.push_back(4);              // 맨 뒤 추가 O(1)
    v32.pop_back();                // 맨 뒤 삭제 O(1), void
    v32.erase(v32.begin() + 1);    // 특정 위치(iterator) 삭제 O(N)
    v32.clear();                   // 전체 삭제
    // erase(begin()) / 중간 삭제는 O(N), pop_back 만 O(1). back()-pop_back() 순서로 값 보존.

}