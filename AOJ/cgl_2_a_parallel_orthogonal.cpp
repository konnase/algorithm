//
// Created by 李青坪 on 2018/11/27.
//

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define EPSLON 1e-10
#define equals(a, b) (fabs((a) - (b)) < EPSLON)

#define MAXN 10000
#define NIL -1
using namespace std;

// 点
class Point {
public:
    double x;
    double y;

    Point(){}
    Point(double x, double y) : x(x), y(y) {}

    Point operator+(Point &a) {
        return Point(x + a.x, y + a.y);
    }

    Point operator-(Point &a) {
        return Point(x - a.x, y - a.y);
    }

    Point operator*(Point &a) {
        return Point(x * a.x, y * a.y);
    }

    Point operator/(Point &a) {
        return Point(x / a.x, y / a.y);
    }

    double norm() {
        return x * x + y * y;
    }

    double absVector() {
        return sqrt(norm());
    }

    bool operator==(Point &a) const {
        return equals(x, a.x) && equals(y, a.y);
    }
};

typedef Point Vector;

// 线段
class Segment {
public:
    Point a, b;
};

double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

int n;

bool isParallel(Segment s1, Segment s2) {
    return equals(cross(s1.a - s1.b, s2.a - s2.b), 0.0);
}

bool isOrthogonal(Segment s1, Segment s2){
    return equals(dot(s1.a - s1.b, s2.a - s2.b), 0.0);
}

int main() {
    scanf("%d", &n);
    Segment s[2];
    Point p[4];
    for (int i = 0; i < n; ++i) {
        double x, y;
        for (int j = 0; j < 4; ++j) {
            scanf("%lf %lf", &x, &y);
            p[j] = Point(x, y);
        }
        s[0].a = p[0];
        s[0].b = p[1];
        s[1].a = p[2];
        s[1].b = p[3];
        if (isParallel(s[0], s[1])){
            printf("%d\n", 2);
        } else if (isOrthogonal(s[0], s[1])){
            printf("%d\n", 1);
        } else{
            printf("%d\n", 0);
        }
    }
}