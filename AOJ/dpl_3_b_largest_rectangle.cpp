//
// Created by 李青坪 on 2019/1/20.
//
/*
 * 坑：
 * 1.每次从栈中弹出一个长方形后，当前元素所构成的长方形的左端点要更新到弹出的长方形对应的左端点
 * 2.s的每一行需要以0结尾，否则如果一行的数值相同，就计算不出长方形面积
 */


#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

#define MAXN 1400
#define NIL -1
using namespace std;

class Rect {
public:
    int h;
    int pos;

    Rect(int h, int pos) : h(h), pos(pos) {}
};

int H, W;
int c[MAXN][MAXN];
int s[MAXN][MAXN];

void histogram() {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (c[i][j] == 1) {
                s[i][j] = 0;
            } else {
                s[i][j] = i > 0 ? s[i - 1][j] + 1 : 1;
            }
        }
    }
}

int findLargestRect() {
    int maxS = 0;
    for (int i = 0; i < H; ++i) {
        stack<Rect> stk;
        for (int j = 0; j <= W; ++j) {
            s[i][W] = 0;
            if (stk.empty()) {
                stk.push(Rect(s[i][j], j));
            } else if (stk.top().h < s[i][j]) {
                stk.push(Rect(s[i][j], j));
            } else if (stk.top().h > s[i][j]) {
                int pre_pos = j;
                while (stk.top().h >= s[i][j]) {
                    maxS = max(maxS, stk.top().h * (j - stk.top().pos));
                    pre_pos = stk.top().pos; //
                    stk.pop();
                    if (stk.empty()) {
                        break;
                    }
                }
                stk.push(Rect(s[i][j], pre_pos));
            }
        }
    }
    return maxS;
}

int main() {
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            scanf("%d", &c[i][j]);
        }
    }
    histogram();
    printf("%d\n", findLargestRect());
}
/*
4 5
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 0 0 1 0
 */