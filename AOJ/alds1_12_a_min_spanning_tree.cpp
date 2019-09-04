//
// Created by 李青坪 on 2018/11/6.
//
/*
 * prim算法
 * 注意：
 * 一开始的找V_T中与T相连的最小的边的时候是遍历T和V_T相连的所有的边，复杂度为Sum(k*(n-k)) k = 1 -> n-1，复杂度在n^3
 * 修改：记录V_T与T相连的最小的边的权值，每次查找最小边的时候，遍历一遍V_T，找到最小边对应的结点u，将u加入T中并从V_T中删除。
 *      同时，由于u加入到T中，遍历V_T，并更新V_T与T相连的最小的边的权值
 */

#include <cstdio>
#include <algorithm>
#include <set>
#define MAXN 100
#define INFINITY 1<<20
#define NIL -1
using namespace std;

int n;
int sum;
int counter = 0;
int graph[MAXN][MAXN];
int d[MAXN];
int parent[MAXN];
set<int> T;
set<int> V_T;

void init(){
    fill(d, d+n, INFINITY);
    fill(parent, parent+n, NIL);
    T.insert(0);
    for (int i = 1; i < n; ++i) {
        V_T.insert(i);
    }
    for (int j = 0; j < n; ++j) {
        d[j] = graph[0][j];
    }
}

pair<int, int> findMinEdge(){
    int min = INFINITY;
    int v;
    set<int >::iterator itr;
    for (itr = V_T.begin(); itr != V_T.end(); itr++){
        ++counter;
        if (min > d[*itr]){
            min = d[*itr];
            v = *itr;
        }
    }
    return make_pair(min, v);
}

void updateMinWeight(int u){
    for (set<int>::iterator itr1 = V_T.begin(); itr1 != V_T.end(); itr1++){
        if (d[*itr1] > graph[u][*itr1]){
            d[*itr1] = graph[u][*itr1];
            parent[*itr1] = u;
        }
    }
}

void findMinSpanTree(){
    while (!V_T.empty()){
        pair<int, int> u = findMinEdge();
        sum += u.first;
        T.insert(u.second);
        V_T.erase(V_T.find(u.second));
        updateMinWeight(u.second);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int w;
        for (int j = 0; j < n; ++j) {
            scanf("%d", &w);
            if (w == -1) graph[i][j] = INFINITY;
            else graph[i][j] = w;
        }
    }
    init();
    findMinSpanTree();
    printf("%d\n", sum);
//    printf("%d", counter);
}
/*
5
 -1 2 3 1 -1
 2 -1 -1 4 -1
 3 -1 -1 1 1
 1 4 1 -1 3
 -1 -1 1 3 -1
 */