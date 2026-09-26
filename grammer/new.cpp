#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int main(){
    pair<int,int> a = {1,2};
    pair<int,int> b = {3,4};

    pair<int,int> sum = {a.first + b.first, a.second + b.second};

    cout << sum.first << " " << sum.second << endl;

    // maximum_element(vector<pair<int,int>)) 도 가능하다
    vector<pair<int,int>> pairs = {a,b};
    max_element(pairs.begin(), pairs.end());
    // pair 두 개는 == 으로 비교 가능하다.
    if(a == b) {cout << "two fairs are the same!" << endl;}
    else { cout << "Two fairs are not the same!" << endl;}

    // 다차원 vector 초기화
    int rows = 3;
    int columns = 4;
    int depth = 5;
    vector<vector<int>> vec(rows, vector<int>(columns));

    // 안쪽부터 중첩해서 쌓으면 된다. 
    //depth x rows x columns
    vector<vector<vector<int>>> vec2(
        depth,
        vector<vector<int>>(rows, vector<int>(columns))
     );

    // 4차원: layers x depth x rows x columns
    int layers = 5;

    vector<vector<vector<vector<int>>>> vec4(
        layers,
        vector<vector<vector<int>>>(
            depth,
            vector<vector<int>>(rows, vector<int>(columns, 0)) //0은 초깃값
        )
    );
}