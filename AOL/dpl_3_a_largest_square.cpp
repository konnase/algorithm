//
// Created by 李青坪 on 2019/1/17.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define MAXN 1400
#define NIL -1
using namespace std;

int H, W;
int c[MAXN][MAXN];
int s[MAXN][MAXN];

int square() {
    int maxS = 0;
    for (int i = 0; i < H; ++i) {
        s[i][0] = c[i][0] == 1 ? 0 : 1;
        if (c[i][0] == 0) maxS = 1;
    }
    for (int j = 0; j < W; ++j) {
        s[0][j] = c[0][j] == 1 ? 0 : 1;
        if (c[0][j] == 0) maxS = 1;
    }
    for (int i = 1; i < H; ++i) {
        for (int j = 1; j < W; ++j) {
            if (c[i][j] == 1){
                s[i][j] = 0;
            } else{
                s[i][j] = min(s[i-1][j-1], min(s[i-1][j], s[i][j-1])) + 1;
                maxS = max(maxS, s[i][j]);
            }
        }
    }
    return maxS * maxS;
}

int main() {
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            scanf("%d", &c[i][j]);
        }
    }
    printf("%d\n", square());
}