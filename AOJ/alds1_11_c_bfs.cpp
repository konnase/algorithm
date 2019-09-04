//
// Created by 李青坪 on 2018/11/3.
//
/*
 * 注意：
 * 1.有向图可能有环，不是DAG，故需要visited数组来标识结点是否已经被访问，从而判断是否应该将结点加入队列
 * 2.对于一个结点，如果有多条路径可以到达，需要选取路径最短的 dist[j] = dist[j] >= 0 ? min(dist[j], dist[i] + 1): dist[i] + 1;
 *
 */

#include <cstdio>
#include <algorithm>
#include <queue>

#define MAXN 101
using namespace std;
int n;
int graph[MAXN][MAXN];
int dist[MAXN];
bool visited[MAXN];
queue<int > q;

void init(){
    fill(dist, dist+MAXN, -1);
    fill(visited, visited+MAXN, false);
    dist[1] = 0;
}

void bfs(int i){
    for (int j = 1; j <= n; ++j) {
        if (graph[i][j] == 1){
            if (visited[j]) continue;
            q.push(j);
            visited[j] = true;
            dist[j] = dist[j] >= 0 ? min(dist[j], dist[i] + 1): dist[i] + 1;
        }
    }
    while (!q.empty()){
        int next = q.front();
        q.pop();
        bfs(next);
    }
}

int main(){
    scanf("%d", &n);
    int u, k;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &u, &k);
        int node;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &node);
            graph[u][node] = 1;
        }
    }
    init();
    bfs(1);
    for (int l = 1; l <= n; ++l) {
        printf("%d %d\n", l, dist[l]);
    }
}
/*
5
1 2 2 4
2 1 4
3 0
4 1 3
5 1 4
 */