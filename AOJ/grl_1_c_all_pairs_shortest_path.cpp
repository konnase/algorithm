//
// Created by 李青坪 on 2018/11/14.
//

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define INFINITY 1<<21
#define NIL -1
#define MAXN 10000

using namespace std;
struct Node{
    int id;
    int weight;
};

struct cmp{
    bool operator ()(Node &a, Node &b){
        return a.weight > b.weight;
    }
};

vector<Node> graph[MAXN];
priority_queue<Node, vector<Node>, cmp> V_S;
int n, e;
int d[MAXN];
bool visited[MAXN];

void init(int start){
    fill(d, d+MAXN, INFINITY);
    d[start] = 0;
    fill(visited, visited+MAXN, false);
    Node node;
    node.id = start;
    node.weight = 0;
    V_S.push(node);
}

void updateMinWeight(Node u){
    vector<Node>::iterator it;
    for (it = graph[u.id].begin(); it != graph[u.id].end(); ++it){ //遍历与u相连的所有结点，看有没有结点到S的距离减小了
        if (visited[(*it).id]) continue;  //与u相连的结点如果已经在S中了，就跳过
        if (d[(*it).id] > d[u.id] + (*it).weight){
            d[(*it).id] = d[u.id] + (*it).weight;
            Node node;
            node.id = (*it).id;
            node.weight = d[(*it).id];
            V_S.push(node);
        }
    }
}

void dijkstra(){
    while (!V_S.empty()){
        Node u = V_S.top();
        V_S.pop();
        visited[u.id] = true;
        updateMinWeight(u);
    }
}


int main() {
    scanf("%d %d", &n, &e);
    int u, v, w;
    for (int i = 0; i < e; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        Node node;
        node.id = v;
        node.weight = w;
        graph[u].push_back(node);
    }
    for (int m = 0; m < n; ++m) {
        init(m);
        dijkstra();
        for (int l = 0; l < n; ++l) {
            if (l != 0) printf(" ");
            if (d[l] == INFINITY) printf("INF");
            else{
                printf("%d", d[l]);
            }
        }
        printf("\n");
    }
}