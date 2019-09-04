//
// Created by 李青坪 on 2018/11/13.
//
/*
 * 注意：
 * 1. 由于要输出的是点的编号，所以Point类中需要定义id属性
 * 2. 由于make2DTree的时候需要对P进行排序，故需要另外开一个vector result记录find的结果，每次find完后需要把result清空
 * 3. make2DTree的时候递归结束条件是l>=r
 */
#include <cstdio>
#include <vector>
#include <algorithm>

#define NIL -1
using namespace std;

class Node {
public:
    int location;
    int p, l, r;

    Node(int p, int l, int r) {
        this->p = NIL;
        this->l = NIL;
        this->r = NIL;
    }
};

class Point {
public:
    int id, x, y;

    Point() {}

    Point(int id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    bool operator < (const Point &point) const {
        return id < point.id;
    }
};


bool cmpX(Point &point1, Point &point2){
    return point1.x < point2.x;
}
bool cmpY(Point &point1, Point &point2){
    return point1.y < point2.y;
}

int position = 0;
int n, q;
vector<Point> P;
vector<Point> result;


class KDTree {
private:
    vector<Node> tree;  //构建二叉搜索树，将排序之后的P中的点的下标构建成一颗二叉搜索树，这样根结点左边的结点对应的P中的值都小于根结点对应的P中的值
public:
    KDTree() {}

    void insertNode(Node node) {
        tree.push_back(node);
    }

    int make2DTree(int l, int r, int depth) {
        if (!(l < r)) return NIL;
        if (depth % 2 == 0) {
            sort(P.begin()+l, P.begin()+r, cmpX);
        } else {
            sort(P.begin()+l, P.begin()+r, cmpY);
        }
        int mid = (l + r) / 2;
        int t = position++;  //二叉树的第t个结点
        tree[t].location = mid;  //第t个结点在P中对应的位置
        tree[t].l = make2DTree(l, mid, depth + 1);
        tree[t].r = make2DTree(mid + 1, r, depth + 1);
        return t;
    }
    void findPoint(int v, int sx, int tx, int sy, int ty, int depth){
        // v表示二叉树中的某个结点
        int x = P[tree[v].location].x;
        int y = P[tree[v].location].y;
        if (sx <= x && x <= tx && sy <= y && y <= ty){
            result.push_back(P[tree[v].location]);
        }
        if (depth %2 ==0){
            if (tree[v].l != NIL && sx <= x){
                findPoint(tree[v].l, sx, tx, sy, ty, depth+1);
            }
            if (tree[v].r != NIL && x <= tx){
                findPoint(tree[v].r, sx, tx, sy, ty, depth+1);
            }
        } else{
            if (tree[v].l != NIL && sy <= y){
                findPoint(tree[v].l, sx, tx, sy, ty, depth+1);
            }
            if (tree[v].r != NIL && y <= ty){
                findPoint(tree[v].r, sx, tx, sy, ty, depth+1);
            }
        }
    }
};

int main() {
    KDTree kdTree;
    scanf("%d", &n);
    int x, y;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        P.push_back(Point(i, x, y));
        kdTree.insertNode(Node(NIL, NIL, NIL));
    }
    kdTree.make2DTree(0, n, 0);
    scanf("%d", &q);
    int sx, tx, sy, ty;
    for (int j = 0; j < q; ++j) {
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        kdTree.findPoint(0, sx, tx, sy, ty, 0);
        sort(result.begin(), result.end());
        vector<Point>::iterator it;
        for (it = result.begin(); it != result.end(); ++it){
            printf("%d\n", (*it).id);
        }
        result.erase(result.begin(), result.end());
        printf("\n");
    }
}/*
6
2 1
2 2
4 2
6 2
3 3
5 4
2
2 4 0 4
4 10 2 5

 */