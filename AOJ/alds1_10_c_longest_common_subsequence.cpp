//
// Created by 李青坪 on 2018/10/29.
//

/*
 * 细节：
 * i和j有一个为0的时候要置c[i][j]为0，因此循环次数为(N+1)*(M+1)
 * 最后的返回值就是c[N][M]，因为c[N][M]是统计完最大公共子序列后的最大值存放位置
 */

#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

#define MAXN 150
#define MAXLEN 1000
using namespace std;

int c[MAXLEN + 1][MAXLEN + 1];

int countSub(string x, string y) {
    for (int i = 0; i <= x.length(); ++i) {
        for (int j = 0; j <= y.length(); ++j) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else if (x[i - 1] != y[j - 1]) {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    return c[x.length()][y.length()];
}

string getSub(string x, string y) {
    string result;
    int i = x.length(), j = y.length();
    while (i > 0) {
        if (j <= 0) {
            break;
        }
        while (j > 0) {
            if (x[i - 1] == y[j - 1]) {
                result.push_back(x[i - 1]);
                --i;
                --j;
            } else if (c[i - 1][j] > c[i][j - 1]) {
                --i;
            } else if (c[i - 1][j] < c[i][j - 1]) {
                --j;
            } else if (c[i - 1][j] == c[i][j - 1]) {
                --i;
            }
        }
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    string x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        printf("%d\n", countSub(x, y));
        string result = getSub(x, y);
        for (int j = result.length() - 1; j >= 0; --j) {
            printf("%c", result[j]);
        }
        printf("\n");
    }
}
/*
3
abcbdab
bdcaba
abc
abc
abc
bc
 */