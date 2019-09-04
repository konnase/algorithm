//
// Created by 李青坪 on 2018/12/1.
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
        int re = ccw(s, point);
        switch (re){
            case COUNTER_CLOCKWISE:
                printf("%s\n", "COUNTER_CLOCKWISE");
                break;
            case CLOCKWISE:
                printf("%s\n", "CLOCKWISE");
                break;
            case ONLINE_BACK:
                printf("%s\n", "ONLINE_BACK");
                break;
            case ONLINE_FRONT:
                printf("%s\n", "ONLINE_FRONT");
                break;
            default:
                printf("%s\n", "ON_SEGMENT");
        }
    }
}