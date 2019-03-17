//
// Created by 李青坪 on 2018/11/20.
//

/*
 * 注意：
 * int类型会越界，要用long long类型，long long类型的整数1用1LL表示
 * 执行floyd算法的时候，如果i到k不可达或者k到j不可达就跳过，否则会出错，比如：
 * 0-->1 -20; 1-->2 -20 0-->2 -20，当i=2，j=1，k=0时，d[2][1] = min(d[2][1], d[2][0]+d[0][1])，会发现d[2][0]+d[0][1]更小，导致结果出错
 */

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define NIL -1
#define MAXN 10000

using namespace std;

typedef long long llong;

llong INFINITY = 1LL << 32;
llong graph[MAXN][MAXN];
int n, e;

void init() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = (i == j ? 0 : INFINITY);
        }
    }
}

void floyd() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (graph[i][k] == INFINITY) continue;
            for (int j = 0; j < n; ++j) {
                if (graph[k][j] == INFINITY) continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main() {
    scanf("%lld %d", &n, &e);
    init();
    llong u, v, w;
    for (int i = 0; i < e; ++i) {
        scanf("%lld %lld %lld", &u, &v, &w);
        graph[u][v] = w;
    }
    floyd();
    for (int j = 0; j < n; ++j) {
        if (graph[j][j] < 0) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }

    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (i) printf(" ");
            if (graph[k][i] == INFINITY) printf("INF");
            else printf("%lld", graph[k][i]);
        }
        printf("\n");
    }
}
/*
6 5
0 1 50
1 2 50
2 3 50
3 4 50
4 5 50
 */