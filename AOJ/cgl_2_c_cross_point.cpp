//
// Created by 李青坪 on 2018/12/5.
//

#include <cmath>
#include <cstdio>
#include <algorithm>

#define EPSLON 1e-10
#define equals(a, b) (fabs((a) - (b)) < EPSLON)

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

double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

Point getCrossPoint(Segment s1, Segment s2) {
    Vector base = s2.b - s2.a;
    double d1 = abs(cross(base, s1.a - s2.a)) / base.absVector();
    double d2 = abs(cross(base, s1.b - s2.b)) / base.absVector();
    double t = d1 / (d1 + d2);
    return s1.a + (s1.b - s1.a) * t;
}

int n;


int main() {
    Segment s[2];
    Point p[4];
    scanf("%d", &n);
    Point point;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            point = Point(x, y);
            p[j] = point;
        }
        s[0].a = p[0];
        s[0].b = p[1];
        s[1].a = p[2];
        s[1].b = p[3];
        Point re = getCrossPoint(s[0], s[1]);
        printf("%.10lf %.10lf\n", re.x, re.y);
    }
}
/*
3
0 0 2 0 1 1 1 -1
0 0 1 1 0 1 1 0
0 0 1 1 1 0 0 1

 */