//
// Created by 李青坪 on 2018/10/30.
//

/*
 * 重点：矩阵链的长度从2--n递增，求出各个子矩阵链对应的最小乘法运算次数
 */
#include <cstdio>
#include <algorithm>

#define MAXN 100
#define INFINITY 1000000000
using namespace std;

int p[MAXN+1];  //记录矩阵的维度
int m[MAXN+1][MAXN+1];

void init(){
    for (int i = 0; i < MAXN+1; ++i) {
        fill(m[i], m[i]+MAXN+1, INFINITY);
    }
}

int calculateMatrixMulti(int n){
    for (int i1 = 1; i1 <= n; ++i1) {
        m[i1][i1] = 0;
    }
    for (int l = 2; l <= n; ++l) { // l is the length of chain
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            for (int k = i; k < j; ++k) {
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]);
            }

        }
    }
    return m[1][n];
}

int main(){
    int n;
    scanf("%d", &n);
    int r, c;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &r, &c);
        p[i] = r;
        p[i+1] = c;
    }
    init();
    printf("%d\n", calculateMatrixMulti(n));
}
/*
6
30 35
35 15
15 5
5 10
10 20
20 25
 */