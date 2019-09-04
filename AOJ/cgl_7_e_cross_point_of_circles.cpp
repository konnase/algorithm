//
// Created by 李青坪 on 2018/12/7.
//

#include <cmath>
#include <cstdio>
//#include <assert.h>
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

class Circle {
public:
    Point c;
    double r;
};

double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

double arg(Vector p) {
    return atan2(p.y, p.x);
}

Vector polar(double a, double r) {
    return Point(a * cos(r), a * sin(r));
}

pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
    double d = (c2.c - c1.c).absVector();
    double t = arg(c2.c - c1.c);
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

int main() {
    Circle c1, c2;
    double x, y, r;
    scanf("%lf %lf %lf", &x, &y, &r);
    c1.c.x = x;
    c1.c.y = y;
    c1.r = r;
    double x1, y1, r1;
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    c2.c.x = x1;
    c2.c.y = y1;
    c2.r = r1;
    pair<Point, Point> re = getCrossPoints(c1, c2);
    if (re.first.x == re.second.x && re.first.y == re.second.y) {
        printf("%.8lf %.8lf %.8lf %.8lf\n", re.first.x, re.first.y, re.second.x, re.second.y);
    } else if (re.first.x < re.second.x) {
        printf("%.8lf %.8lf %.8lf %.8lf\n", re.first.x, re.first.y, re.second.x, re.second.y);
    } else {
        if (re.first.x == re.second.x) {
            if (re.first.y < re.second.y) {
                printf("%.8lf %.8lf %.8lf %.8lf\n", re.first.x, re.first.y, re.second.x, re.second.y);
            } else {
                printf("%.8lf %.8lf %.8lf %.8lf\n", re.second.x, re.second.y, re.first.x, re.first.y);
            }
        } else {
            printf("%.8lf %.8lf %.8lf %.8lf\n", re.second.x, re.second.y, re.first.x, re.first.y);
        }
    }
}