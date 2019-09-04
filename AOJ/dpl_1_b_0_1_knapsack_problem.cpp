//
// Created by 李青坪 on 2018/12/14.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define MAXN 100
#define MAXW 10000
#define NIL -1
using namespace std;

struct Good {
    int v;
    int w;

    Good(int v, int w) : v(v), w(w) {}
};

int n, m;
vector<Good> goods;
int c[MAXN + 1][MAXW + 1];

int knapsack() {
    for (int i = 0; i <= n; ++i) {
        fill(c[i], c[i] + m + 1, 0);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j - goods[i].w >= 0) {
                if (c[i - 1][j - goods[i].w] + goods[i].v > c[i - 1][j]) {
                    c[i][j] = c[i-1][j - goods[i].w] + goods[i].v;  //注意后面是用c[i-1][j-goods[i].w]来计算的，不是c[i]，，，
                } else {
                    c[i][j] = c[i-1][j];
                }
            } else {
                c[i][j] = c[i - 1][j];
            }
        }

    }
    return c[n][m];
}

int main() {
    scanf("%d %d", &n, &m);
    int x, y;
    goods.push_back(Good(0, 0));
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        goods.push_back(Good(x, y));
    }
    printf("%d\n", knapsack());
}