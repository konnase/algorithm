//
// Created by 李青坪 on 2019/2/24.
//

#include <iostream>
#include <string>

using namespace std;


int main() {
    int alphabet[26];
    for (int i = 0; i < 26; ++i) {
        cin >> alphabet[i];
    }
    string s;
    cin >> s;
    int rowLen = 0, rowNum = 1;
    int index;
    for (int i = 0; i < s.length(); ++i) {
        index = s[i] - 'a';
        rowLen += alphabet[index];
        if (rowLen >= 100) {
            rowLen = rowLen == 100 ? 0:alphabet[index];
            ++rowNum;
        }
    }
    cout << rowNum << " " << rowLen << endl;
}