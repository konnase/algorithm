//
// Created by 李青坪 on 2018/11/28.
//

#include <cmath>
#include <cstdio>
#include <algorithm>

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

Point projection(Segment s, Point point) {
    Vector base = s.b - s.a;
    double t = dot(point - s.a, base) / base.absVector();
    double r = t / base.absVector();
    Point y = base * r;
    Point x = s.a + y;
    return x;
}

Point reflection(Segment s, Point point) {
    return point + (projection(s, point) - point) * 2.0;
}

double getDistance(Point a, Point b) {
    return (a - b).absVector();
}

double getDistance(Line l, Point point) {
    return cross(l.b-l.a, point-l.a) / (l.b-l.a).absVector();
}

int n;


int main() {
    Segment s;
    Point p[2];
    scanf("%lf %lf %lf %lf", &p[0].x, &p[0].y, &p[1].x, &p[1].y);
    s.a = p[0];
    s.b = p[1];
    scanf("%d", &n);
    Point point;
    for (int i = 0; i < n; ++i) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        point = Point(x, y);
//        Point re = projection(s, point);
//        printf("%.10f %.10f\n", re.x, re.y);
        Point re = reflection(s, point);
        printf("%.10f %.10f\n", re.x, re.y);
    }
}
/*
0 0 3 4
3
2 5
1 4
0 3

 */