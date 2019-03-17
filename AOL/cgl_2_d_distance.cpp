//
// Created by 李青坪 on 2018/11/29.
//

#include <cmath>
#include <cstdio>
#include <algorithm>

#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK -2
#define ONLINE_FRONT 2
#define ON_SEGMENT 0
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

double getDistanceLine(Line l, Point point) {
    return abs(cross(l.b - l.a, point - l.a) / (l.b - l.a).absVector());
}

double getDistanceSeg(Segment s, Point point) {
    if (dot(s.b - s.a, point - s.a) < 0.0) return (point - s.a).absVector();
    if (dot(s.a - s.b, point - s.b) < 0.0) return (point - s.b).absVector();
    return getDistanceLine(s, point);
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

bool intersection(Segment s1, Segment s2) {
    return (ccw(s1, s2.a) * ccw(s1, s2.b) <= 0 && ccw(s2, s1.a) * ccw(s2, s1.b) <= 0);
}

double getDistance(Segment s1, Segment s2) {
    if (intersection(s1, s2)) return 0.0;
    return min(min(getDistanceSeg(s1, s2.a), getDistanceSeg(s1, s2.b)),
               min(getDistanceSeg(s2, s1.a), getDistanceSeg(s2, s1.b)));
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
        printf("%.10lf\n", getDistance(s[0], s[1]));
    }
}