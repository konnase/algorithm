//
// Created by 李青坪 on 2018/11/4.
//
/*
 * 注意：
 * 1.maxn = 100000，maxq = 10000，故不能对每一个q都从图里面执行一遍查找，会超时的
 *   解决方法是查找之前先把连通子图都标记好，查找的时候如果两个结点标记一样，则这两个结点在一个连通子图中
 * 
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define MAXN 100001
#define NIL -1
using namespace std;

vector<int > compo[MAXN];
int group[MAXN];
queue<int> queue1;

void init(int n){
    fill(group, group+n, NIL);
    queue1 = queue<int>();
}

void query(int node, int color){
    queue1.push(node);
    group[node] = color;
    int ex;
    while (!queue1.empty()){
        ex = queue1.front();
        queue1.pop();
        for (auto comp: compo[ex]){
            if (group[comp] != NIL) continue;
            group[comp] = color;
            queue1.push(comp);
        }
    }
}

void partitionGroup(int n){
    int c = 0;
    for (int i = 0; i < n; ++i) {
        queue1 = queue<int>();
        if (group[i] == NIL) query(i, c++);
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int s, t;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &s, &t);
        compo[s].push_back(t);
        compo[t].push_back(s);
    }
    init(n);
    partitionGroup(n);
    int q;
    scanf("%d", &q);
    for (int j = 0; j < q; ++j) {
        scanf("%d %d", &s, &t);
//        printf("%d", group[s]);
        if (group[s] == group[t]) printf("yes\n");
        else printf("no\n");
    }
}
/*
10 5
0 1
1 2
2 9
3 4
6 7
12
0 1
0 2
0 9
3 4
6 7
7 6
0 5
0 6
3 7
3 5
5 8
8 5
 */