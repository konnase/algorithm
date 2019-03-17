//
// Created by 李青坪 on 2018/12/9.
//

#include <cstdio>
#include <algorithm>
#include <string>
//#include <iostream>

#define MAXN 100000
using namespace std;

string c[MAXN + 1][MAXN + 1];

string getSubsequence(string x, string y) {
    for (int i = 0; i <= x.length(); ++i) {
        for (int j = 0; j <= y.length(); ++j) {
            if (i == 0 || j == 0) {
                continue;
            } else if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + x[i - 1];
            } else if (x[i - 1] != y[j - 1]) {
                c[i][j] = c[i - 1][j].length() > c[i][j - 1].length() ? c[i - 1][j] : c[i][j - 1];
            }
        }
    }
    return c[x.length()][y.length()];
}

int main() {
//    printf("hello");
//    string s, t;
//    cin >> s;
//    int count = 0;
//
//    string l = getSubsequence(s, t);  //找到最长公共子串
//    while (l != s) {
//        if (l[0] != s[0]) {
//            int index = s.find(l);
//            int start = t.find(l[0]);
//            int j = start + 1;
//            while (t[j] != s[index - 1] && j < t.length()) {
//                ++j;
//            }
//            if (t[j] != t.length()) {
//                char temp = t[j];
//                for (int k = j; k > start; --k) {
//                    t[k] = t[k - 1];
//                }
//                t[start] = temp;
//                ++count;
//            } else {
//                printf("%d\n", -1);
//                return 0;
//            }
//        } else {
//            int index = l.length();
//            int start = t.find(l[index - 1]);
//            int j = 0;
//            while (t[j] != s[index] && j < t.length()) {
//                ++j;
//            }
//            if (t[j] != t.length()) {
//                char temp = t[j];
//                for (int k = j; k < start; ++k) {
//                    t[k] = t[k + 1];
//                }
//                t[start] = temp;
//                ++count;
//            } else {
//                printf("%d\n", -1);
//                return 0;
//            }
//        }
//        l = getSubsequence(s, t);
//    }
//    printf("%d\n", count);
}