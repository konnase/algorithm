//
// Created by 李青坪 on 2018/12/12.
//
/*
 * 关键：1.定义EndPoint类：Point，point type，belong to which segment
 *      2.求一条水平线段与垂直线段的交点时，直接使用stl中set.lower_bound和set.upper_bound方法，
 *      再计算这两个方法返回的迭代器之间的距离即可知道这条水平线段与几条垂直线段有交点
 *      3.在y相等时，端点排列的顺序应当是：下端点，左端点，右端点，上端点。否则可能出现扫描到左端点的时候，下端点还未添加到二叉搜索树中
 */

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

#define EPSLON 1e-10
#define equals(a, b) (fabs((a) - (b)) < EPSLON)

using namespace std;

// 点
class Point {
public:
    int x;
    int y;

    Point() {}

    Point(int x, int y) : x(x), y(y) {}

    Point operator+(Point a) {
        return Point(x + a.x, y + a.y);
    }

    Point operator-(Point a) {
        return Point(x - a.x, y - a.y);
    }

    Point operator*(int a) {
        return Point(x * a, y * a);
    }

    Point operator/(int a) {
        return Point(x / a, y / a);
    }

    int norm() {
        return x * x + y * y;
    }

    int absVector() {
        return sqrt(norm());
    }

    bool operator==(Point a) const {
        return equals(x, a.x) && equals(y, a.y);
    }
};

typedef Point Vector;

// 线段
class Segment {
public:
    Point a, b;

    Segment(Point a, Point b) : a(a), b(b) {}
};

int dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

int cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

class EndPoint {
public:
    Point p;
    int seg;
    int tp; //点类型
    EndPoint() {}

    EndPoint(Point p, int s, int tp) : p(p), seg(s), tp(tp) {}

    bool operator<(EndPoint ep) const {
        if (p.y == ep.p.y) {
            return tp < ep.tp;
        } else {
            return p.y < ep.p.y;
        }
    }
};

#define DOWN 0
#define LEFT 1
#define RIGHT 2
#define UP 3
vector<Segment> s;
int n;

int manhattanIntersection(vector<Segment> s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i].a.y == s[i].b.y) {
            if (s[i].a.x > s[i].b.x) swap(s[i].a, s[i].b);
        } else if (s[i].a.y > s[i].b.y) swap(s[i].a, s[i].b);
    }

    EndPoint ep[2 * n];  //构建endpoint
    for (int i = 0; i < n; ++i) {
        if (s[i].a.y == s[i].b.y) {
            ep[2 * i] = EndPoint(s[i].a, i, LEFT);
            ep[2 * i + 1] = EndPoint(s[i].b, i, RIGHT);
        } else if (s[i].a.x == s[i].b.x) {
            ep[2 * i] = EndPoint(s[i].a, i, DOWN);
            ep[2 * i + 1] = EndPoint(s[i].b, i, UP);
        }
    }
    sort(ep, ep + 2 * n);
//    for (int i = 0; i < 2 * n; ++i) {
//        printf("%d %d %d\n", ep[i].p.x, ep[i].p.y, ep[i].tp);
//    }

    set<int> bst;
    int count = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (ep[i].tp == DOWN) {
            bst.insert(ep[i].p.x);
        } else if (ep[i].tp == UP) {
            bst.erase(ep[i].p.x);
        } else if (ep[i].tp == LEFT) {
            set<int>::iterator l = bst.lower_bound(s[ep[i].seg].a.x);
            set<int>::iterator u = bst.upper_bound(s[ep[i].seg].b.x);
            count += distance(l, u);
        }
    }
    return count;
}

int main() {
    scanf("%d", &n);
    int x1, y1, x2, y2;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        Segment s1 = Segment(Point(x1, y1), Point(x2, y2));
        s.push_back(s1);
    }
    printf("%d\n", manhattanIntersection(s));
}
/*
6
2 2 2 5
1 3 5 3
4 1 4 4
5 2 7 2
6 1 6 3
6 5 6 7

 */