//
// Created by 李青坪 on 2018/11/27.
//

#ifndef CLION_GEOMETRY_H
#define CLION_GEOMETRY_H

#endif //CLION_GEOMETRY_H

#include <cmath>

#define EPSLON 1e-10
#define equals(a, b) (fabs((a) - (b)) < EPSLON)

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

// 圆
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