//
// Created by 李青坪 on 2018/11/7.
//

#include <cstdio>
#include <algorithm>
#include <set>

#define MAXN 100
#define INFINITY 1<<21
#define NIL -1
using namespace std;

int n;
int graph[MAXN][MAXN];
int d[MAXN];
int parent[MAXN];
set<int> S;
set<int> V_S;

void init(){
    S.insert(0);
    for (int j = 1; j < n; ++j) {
        V_S.insert(j);
    }
    fill(d, d+n, INFINITY);
    d[0] = 0;
    for (int k = 1; k < n; ++k) {
        d[k] = graph[0][k];
        parent[k] = 0;
    }
    fill(parent, parent+n, NIL);
}

int findMinEdge(){
    int min = INFINITY;
    int u = NIL;
    set<int>::iterator it;
    for (it = V_S.begin(); it != V_S.end(); ++it){
        if (min > d[*it]){
            min = d[*it];
            u = *it;
        }
    }
    return u;
}

void updateMinWeight(int u){
    set<int>::iterator it;
    for (it = V_S.begin(); it != V_S.end(); ++it){
        if (d[u] + graph[u][*it] < d[*it]){
            d[*it] = d[u]  + graph[u][*it];
            parent[*it] = u;
        }
    }
}

void dijkstra(){
    while (!V_S.empty()){
        int u = findMinEdge();
        S.insert(u);
        V_S.erase(V_S.find(u));
        updateMinWeight(u);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        fill(graph[i], graph[i]+n, INFINITY);
    }
    int u, k;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &u, &k);
        int v, w;
        for (int j = 0; j < k; ++j) {
            scanf("%d %d", &v, &w);
            graph[u][v] = w;
        }
    }
    init();
    dijkstra();
    for (int l = 0; l < n; ++l) {
        printf("%d %d\n", l, d[l]);
    }
}
/*
5
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3
 */