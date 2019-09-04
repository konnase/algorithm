//
// Created by 李青坪 on 2018/11/25.
//
/*
 * 并查集应该构建成一个单独的数据结构，而不是放在Graph类里面，切记
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define MAXN 10000
#define NIL -1
using namespace std;

int n, e;

class Edge {
public:
    int s;
    int t;
    int w;

    Edge() {}

    Edge(int s, int t, int w) : s(s), t(t), w(w) {}
};

class Compare {
public:
    bool operator()(Edge a, Edge b) {
        return a.w > b.w;
    }
};


class Graph {
public:
    vector<Edge> G[MAXN];
    priority_queue<Edge, vector<Edge>, Compare> q;
    vector<Edge> tree;
    int parent[MAXN];
    int rank[MAXN];

    Graph() {}

    void addEdge(int cur, Edge node) {
        G[cur].push_back(node);
    }

    void makeQueue() {
        vector<Edge>::iterator it;
        for (int i = 0; i < n; ++i) {
            for (it = G[i].begin(); it != G[i].end(); ++it) {
                q.push(*it);
            }
        }
    }

    void makeSet(){
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findSet(int a){
        if (parent[a] != a){
            return findSet(parent[a]);
        }
        return a;
    }

    void unite(int a, int b){
        int r_a = findSet(a);
        int r_b = findSet(b);
        if (r_a == r_b) return;
        if (rank[r_a] > rank[r_b]){
            parent[r_b] = r_a;
        } else{
            parent[r_a] = r_b;
            if (rank[r_a] == r_b){
                rank[r_b]++;
            }
        }
    }

    bool same(int a, int b){
        return findSet(a) == findSet(b);
    }

    void kruskal(){
        while (!q.empty()){
            Edge edge = q.top();
            q.pop();
            if (!same(edge.s, edge.t)){
                unite(edge.s, edge.t);
                tree.push_back(edge);
            }
        }
    }
};


int main() {
    Graph g = Graph();
    scanf("%d %d", &n, &e);
    int s, t, w;
    Edge edge;
    for (int i = 0; i < e; ++i) {
        scanf("%d %d %d", &s, &t, &w);
        edge = Edge(s, t, w);
        g.addEdge(s, edge);
    }
    g.makeQueue();
    g.makeSet();
    g.kruskal();
    int sum = 0;
    vector<Edge>::iterator it;
    for (it = g.tree.begin(); it != g.tree.end(); ++it){
        sum += (*it).w;
//        printf("%d %d %d\n", (*it).s, (*it).t, (*it).w);
    }
    printf("%d\n", sum);
}
/*
4 6
0 1 2
1 2 1
2 3 1
3 0 1
0 2 3
1 3 5
 */