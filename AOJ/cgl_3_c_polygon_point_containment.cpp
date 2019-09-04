//
// Created by 李青坪 on 2018/12/9.
//

#include <cmath>
#include <cstdio>
//#include <assert.h>
#include <algorithm>
#include <vector>

#define EPSLON 1e-10
#define equals(a, b) (fabs((a) - (b)) < EPSLON)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK -2
#define ONLINE_FRONT 2
#define ON_SEGMENT 0

using namespace std;

// 点
class Point {
public:
    double x;
    double y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    Point operator+(Point a) {
        return Point(x + a.x, y + a.y);
    }

    Point operator-(Point a) {
        return Point(x - a.x, y - a.y);
    }

    Point operator*(double a) {
        return Point(x * a, y * a);
    }

    Point operator/(double a) {
        return Point(x / a, y / a);
    }

    double norm() {
        return x * x + y * y;
    }

    double absVector() {
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
};

typedef Segment Line;

typedef vector<Point> Polygon;

double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

int contains(Polygon g, Point p) {
    int n = g.size();
    bool contain = false;
    for (int i = 0; i < n; ++i) {
        Vector a = g[i] - p;
        Vector b = g[(i + 1) % n] - p;
        if (abs(cross(a, b)) < EPSLON && dot(a, b) < EPSLON) return 1;
        if (a.y > b.y) swap(a, b);
        if (a.y < EPSLON && b.y > EPSLON && cross(a, b) > EPSLON) contain = !contain;
    }
    return contain ? 2 : 0;
}

int n;

int main() {
    Polygon g;
    scanf("%d", &n);
    double x, y;
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &x, &y);
        g.push_back(Point(x, y));
    }
    int q;
    scanf("%d", &q);
    for (int j = 0; j < q; ++j) {
        scanf("%lf %lf", &x, &y);
        Point p = Point(x, y);
        printf("%d\n", contains(g, p));
    }
}