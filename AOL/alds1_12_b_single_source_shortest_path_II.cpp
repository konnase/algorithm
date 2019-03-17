//
// Created by 李青坪 on 2018/11/8.
//
/*
 * 定义结构体Node表示结点编号和某结点到该结点的权重
 * 由于优先级队列默认优先取最大值，所以要自定义Compare类，priority_queue<Node, vector<Node>, cmp> V_S;
 * 需要visited数组来记录结点是否被访问过
 */
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

bool comp(Node a, Node b){
    return a.weight > b.weight;
}

vector<Node> graph[MAXN];
priority_queue<Node, vector<Node>, cmp> V_S;
int n;
int d[MAXN];
bool visited[MAXN];

void init(){
    fill(d, d+MAXN, INFINITY);
    d[0] = 0;
    fill(visited, visited+MAXN, false);
    Node node;
    node.id = 0;
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

int main(){
    scanf("%d", &n);
    int u, k;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &u, &k);
        int v, w;
        Node node;
        for (int j = 0; j < k; ++j) {
            scanf("%d %d", &v, &w);
            node.id = v;
            node.weight = w;
            graph[u].push_back(node);
        }
    }
    init();
    dijkstra();
    for (int l = 0; l < n; ++l) {
        printf("%d %d\n", l, d[l]);
    }
//    Node node1, node2;
//    node1.id = 0; node1.weight = 5;
//    node2.id = 1; node2.weight = 3;
//    cmp cmp1;
//    printf("%d", cmp1.operator()(node1, node2));
// 测试升序优先级队列
//    Node l[6];
//    l[0].id = 0; l[0].weight = 3;
//    l[1].id = 1; l[1].weight = 2;
//    l[2].id = 2; l[2].weight = 5;
//    l[3].id = 3; l[3].weight = 3;
//    l[4].id = 4; l[4].weight = 4;
//    l[5].id = 5; l[5].weight = 2;
//    for (int i = 0; i < 6; ++i) {
//        V_S.push(l[i]);
//    }
//    for (int j = 0; j < 6; ++j) {
//        printf("id: %d weight: %d\n", V_S.top().id, V_S.top().weight);
//        V_S.pop();
//    }

}
/*
5
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3
 */
