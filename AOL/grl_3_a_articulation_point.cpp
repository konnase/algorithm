//
// Created by 李青坪 on 2018/11/23.
//

//
// Created by 李青坪 on 2018/11/22.
//

#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#define MAXN 100000
#define INFINITY 1<<30
#define NIL -1
using namespace std;

int n, e;
vector<int> graph[MAXN];
vector<int> tree[MAXN];
set<int> result;
int preOrder[MAXN];
int parent[MAXN];
int lowestOrder[MAXN];
bool visited[MAXN];
int orderCount = 0;

void init(){
    fill(visited, visited+n, false);
    fill(preOrder, preOrder+n, INFINITY);
    fill(parent, parent+n, NIL);
    fill(lowestOrder, lowestOrder+n, INFINITY);
}

// 构建dfs tree
void dfsTree(int node){
    preOrder[node] = ++orderCount;
    visited[node] = true;
    vector<int>::iterator it;
    for (it = graph[node].begin(); it != graph[node].end(); ++it){
        if (!visited[*it]){
            tree[node].push_back(*it);
            parent[*it] = node;
            dfsTree(*it);
        }
    }
}

// 求得每个结点的最小遍历序列号
int dfs(int node){
    int prt = parent[node];
    int minBack = preOrder[node];
    vector<int>::iterator it1;
    for (it1 = graph[node].begin(); it1 != graph[node].end(); ++it1){ //对node中每条不属于tree的边(node --> *it1)
        if (prt == NIL) break;
        if (*it1 != prt && preOrder[prt] < minBack){
            minBack = preOrder[*it1];
        }
    }
    vector<int>::iterator it;
    for (it = tree[node].begin(); it != tree[node].end(); ++it){ //对node的每个子结点
        minBack = min(minBack, dfs(*it));
    }
    return lowestOrder[node] = minBack;
}

void getArtiPoint(int node){
    if (node == 0){
        if (tree[node].size() >= 2){
            result.insert(node);
        }
    } else{
        int prt = parent[node];
        if (preOrder[prt] <= lowestOrder[node] && prt != 0){  //注意prt为根结点的时候这里不适用
            result.insert(prt);
        }
    }
    vector<int>::iterator it;
    for (it = tree[node].begin(); it != tree[node].end(); ++it){ //对node的每个子结点
        getArtiPoint(*it);
    }
}

int main(){
    scanf("%d %d", &n, &e);
    init();
    int u, v;
    for (int i = 0; i < e; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfsTree(0);
    dfs(0);
    getArtiPoint(0);
    set<int>::iterator it;
    for (it = result.begin(); it != result.end(); ++it){
        printf("%d\n", *it);
    }
}
/*
4 4
0 1
0 2
1 2
2 3

6 6
0 1
1 2
3 1
3 4
4 5
5 2
 */