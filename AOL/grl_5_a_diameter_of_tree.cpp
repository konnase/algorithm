//
// Created by 李青坪 on 2018/11/24.
//

#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 100000
using namespace std;

struct Node{
    int id;
    int w;
};

int n;
int d[MAXN];
bool visited[MAXN];
vector<Node> graph[MAXN];

void getFarestX(int cur){
    visited[cur] = true;
    vector<Node>::iterator it;
    for (it = graph[cur].begin(); it != graph[cur].end(); ++it){
        if (!visited[(*it).id]){
            d[(*it).id] = d[cur] + (*it).w;
            getFarestX((*it).id);
        }
    }
}

pair<int, int> getDiameter(int cur){
    fill(visited, visited+n, false);
    d[cur] = 0;
    getFarestX(cur);
    int maxX = d[0];
    int maxXIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (d[i] > maxX){
            maxX = d[i];
            maxXIndex = i;
        }
    }
    return make_pair(maxX, maxXIndex);
}

int main(){
    scanf("%d", &n);
    int s, t, w;
    Node node;
    for (int i = 0; i < n-1; ++i) {
        scanf("%d %d %d", &s, &t, &w);
        node.id = t;
        node.w = w;
        graph[s].push_back(node);
        node.id = s;
        node.w = w;
        graph[t].push_back(node);
    }
    pair<int, int > x = getDiameter(0);
    pair<int, int> result = getDiameter(x.second);
    printf("%d\n", result.first);
}
/*
10
0 1 7
0 2 5
0 3 8
1 4 3
1 5 9
3 6 2
3 7 5
7 8 3
7 9 1
 */