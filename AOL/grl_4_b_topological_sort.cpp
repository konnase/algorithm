//
// Created by 李青坪 on 2018/11/22.
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 10000
using namespace std;

int n, e;
vector<int> graph[MAXN];
queue<int> q;
vector<int> out;
bool visited[MAXN];
int indegree[MAXN];

void init(){
    fill(visited, visited+n, false);
    find(indegree, indegree+n, 0);
}

void bfs(int node){
    q.push(node);
    visited[node] = true;
    out.push_back(node);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); ++it){
            visited[*it] = true;
            indegree[*it]--;
            if (!indegree[*it]){
                out.push_back(*it);
                q.push(*it);
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &e);
    init();
    int u, v;
    for (int i = 0; i < e; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        indegree[v]++;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && !indegree[i]){
            bfs(i);
        }
    }
    vector<int>::iterator it;
    for (it = out.begin(); it != out.end(); ++it){
        printf("%d\n", *it);
    }
}
/*
6 6
0 1
1 2
3 1
3 4
4 5
5 2
 */