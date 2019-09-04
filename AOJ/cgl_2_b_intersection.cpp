//
// Created by 李青坪 on 2018/12/3.
//

#include <cmath>
#include <cstdio>
#include <algorithm>

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

double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

int ccw(Segment s, Point p) {
    Vector v1 = s.b - s.a;
    Vector v2 = p - s.a;
    if (cross(v1, v2) > 0) return COUNTER_CLOCKWISE;
    if (cross(v1, v2) < 0) return CLOCKWISE;
    if (dot(v1, v2) < 0) return ONLINE_BACK;
    if (v1.norm() < v2.norm()) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersection(Segment s1, Segment s2){
    return (ccw(s1, s2.a) * ccw(s1, s2.b) <= 0 && ccw(s2, s1.a) * ccw(s2, s1.b) <= 0);
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
        printf("%d\n", intersection(s[0], s[1]));
    }
}