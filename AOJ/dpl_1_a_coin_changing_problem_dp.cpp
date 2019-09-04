//
// Created by 李青坪 on 2018/12/13.
//

/*
 * 1.将是否使用第i个coin写入DP公式里面
 * 2.所有小于coin[i+1]面值的j都用不上coin[i+1]，故这些j的cnt值都等于使用coin[i]计算的最小硬币枚数
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define MAXN 1000000000
#define MAXM 100000
#define NIL -1
#define INFINITY 1<<30
using namespace std;

int n, m;
int coin[MAXM+1];
int cnt[MAXM+1][MAXN+1];

int leastCoinDP(){
    for (int i = 0; i <= m; ++i) {
        fill(cnt[i], cnt[i]+n+1, INFINITY);
    }
    cnt[0][0] = 0;
    for (int i = 1; i <= m; ++i) {
        cnt[i][0] = 0;
        for (int j = coin[i]; j <= n; ++j) {
            if (coin[i] == n) {
                return 1;
            }
            cnt[i][j] = min(cnt[i-1][j], cnt[i][j-coin[i]]+1);
        }
        //所有小于coin[i+1]面值的j都用不上coin[i+1]，故这些j的cnt值都等于使用coin[i]计算的最小硬币枚数
        for (int j = 1; j < coin[i+1]; ++j) {
            cnt[i+1][j] = cnt[i][j];
        }
    }
    int minC = INFINITY;
    for (int i = 1; i <= m; ++i) {
        minC = min(minC, cnt[i][n]);
    }
    return minC;
//    return cnt[m][n];
}

int main(){
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; ++i) {
        coin[i] = i;
    }
    printf("%d\n", leastCoinDP());
}
