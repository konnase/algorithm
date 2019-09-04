//
// Created by 李青坪 on 2018/11/10.
//
/*
 * 将集合写成类，方便复用n<10000, q<100000
 * findSet方法如果不对树进行路径压缩或者遍历数组判断两个树是否在一个集合中的话会超时
 */

#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 10000
#define NIL -1
using namespace std;

int n, q;

class DisjointSet{
private:
    int p[MAXN];
    int height[MAXN];
public:
    DisjointSet(){
        fill(p, p+n, NIL);
        fill(height, height+n, NIL);
    }
    void makeSet(int x){
        p[x] = x;
        height[x] = 0;
    }
    int findSet(int x){
        if (p[x] != x){
            int t = findSet(p[x]);
            p[x] = t;
            return t;
        }
        else{
            return x;
        }
    }
    void unite(int x, int y){
        int r_x = findSet(x);
        int r_y = findSet(y);
        if (height[r_x] < height[r_y]){
            p[r_x] = r_y;
        }
        else{
            p[r_y] = r_x;
            if (height[r_x] == height[r_y]){
                ++height[r_x];
            }
        }
    }
    bool same(int x, int y){
        return findSet(x) == findSet(y);
    }
};

int main(){
    scanf("%d %d", &n, &q);
    DisjointSet set = DisjointSet();
    for (int j = 0; j < n; ++j) {
        set.makeSet(j);
    }
    for (int i = 0; i < q; ++i) {
        int com, x, y;
        scanf("%d %d %d", &com, &x, &y);
        if (com){
            printf("%d\n", set.same(x, y));
        }
        else{
            set.unite(x, y);
        }
    }
}
/*
5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0
 */