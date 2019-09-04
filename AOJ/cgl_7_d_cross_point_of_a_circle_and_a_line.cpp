//
// Created by 李青坪 on 2018/12/5.
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

Point projection(Segment s, Point point) {
    Vector base = s.b - s.a;
    double t = dot(point - s.a, base) / base.absVector();
    double r = t / base.absVector();
    Point y = base * r;
    Point x = s.a + y;
    return x;
}

pair<Point, Point> getCrossPoints(Circle circle, Line line) {
    Point pro = projection(line, circle.c);
    Vector pr = pro - circle.c;
//    assert(pr.absVector() <= circle.r);
    Vector e = (line.b - line.a) / (line.b - line.a).absVector();
    double base = sqrt(circle.r * circle.r - pr.norm());
    return make_pair(pro - e * base, pro + e * base);
}

int n;


int main() {
    Circle circle;
    double x, y, r;
    scanf("%lf %lf %lf", &x, &y, &r);
    circle.c.x = x;
    circle.c.y = y;
    circle.r = r;
    scanf("%d", &n);
    Point point[2];
    double x1, y1, x2, y2;
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
        point[0].x = x1;
        point[0].y = y1;
        point[1].x = x2;
        point[1].y = y2;
        Line l;
        l.a = point[0];
        l.b = point[1];
        pair<Point, Point> re = getCrossPoints(circle, l);
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
}
/*
2 1 1
2
0 1 4 1
3 0 3 3

 */