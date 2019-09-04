//
// Created by 李青坪 on 2018/10/3.
//
#include "cstdio"
#include "vector"
#include "stack"
#include "iostream"

using namespace std;

int main(){
    stack<int > location;
    stack<pair<int, int > > square;
    int i = 0;
    char chr[20001];
    scanf("%s", chr);
    while (chr[i] == '\\' || chr[i] =='/' || chr[i] == '_'){
        if (chr[i] =='\\'){
            location.push(i);
        }
        else if (chr[i] == '/' && !location.empty()){
            int lastLoc = location.top();
            location.pop();
            int s = i - lastLoc;
            while (!square.empty() && lastLoc < square.top().first){
                s += square.top().second;
                square.pop();
            }
            square.push(make_pair(lastLoc, s));
        }
        ++i;
    }
    int sum = 0, count = 0;
    vector<int > squ;
    while (!square.empty()){
        sum += square.top().second;
        squ.push_back(square.top().second);
        square.pop();
        ++count;
    }
    cout << sum << endl << count;
    while (!squ.empty()){
        int s = squ.back();
        squ.pop_back();
        cout << ' ' << s;
    }
    cout << endl;
    return 0;
}

/*

\\///\_/\/\\\\/_/\\///__\\\_\\/_\/_/\

 */
