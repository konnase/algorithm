//
// Created by 李青坪 on 2019/1/29.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n, m;

class Solution {
public:
    void replaceSpace(char *str, int length) {
        int spaceNum = 0;
        for (int i = length-1; i >= 0; --i) {
            if (str[i] == ' ') {
                spaceNum++;
            }
        }
        int newLen = length + 2 * spaceNum;
        int i = length - 1;
        while (i >= 0){
            if (str[i] == ' '){
                for (int j = newLen - 2; j >= i+1; --j) {
                    str[j+2] = str[j];
                }
                int index = i;
                str[index++] = '%';
                str[index++] = '2';
                str[index] = '0';
            }
            i--;
        }
    }
};

int main() {
    char a[100] = "We Are Happy";
    Solution s;
    s.replaceSpace(a, 12);
    cout << a <<endl;
}

/*
 3 4
 1 4 7 8
 2 6 8 9
 6 10 12 20
 */
