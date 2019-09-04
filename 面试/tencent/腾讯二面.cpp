//
// Created by 李青坪 on 2019-03-26.
//

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

string findStr(vector<string> str){
    int len = str.size();
    if (len == 0) {
        return "";
    }
    int count = 0;
    bool finish = false;
    while (!finish) {
        char cmp = str[0][count];
        for (int i = 1; i < len; ++i) {
            if (str[i].length() <= count) {
                if (str[i][count] != cmp) {
                    finish = true;
                    break;
                }
            } else {
                break;
            }
        }
        ++count;
    }
    if (finish) {
        count--;
    }
    if (count <= 0) return "";
    return str[0].substr(0, count);
}

int main() {
//    cout << "Hello World!" << endl;
//    vector<string> s = vector<string>({"abc", "abcd", "abced"});
//    cout << findStr(s);
    int n;
    cin >> n;
    vector<string> s;
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        s.push_back(temp);
        cout << temp << endl;
    }
    clock_t startTime, endTime;
    startTime = clock();
    cout << findStr(s) <<endl;
    endTime = clock();
    cout << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;
}