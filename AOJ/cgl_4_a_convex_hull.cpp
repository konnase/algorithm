//
// Created by 李青坪 on 2018/12/11.
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

const int INF = 1 << 30;

using namespace std;

// 点
class Point {
public:
    int x;
    int y;

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

    Segment(Point a, Point b) : a(a), b(b) {}
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


int n;
vector<Point> polygon;
vector<Point> up;
vector<Point> down;
vector<Point> result;

bool cmp(Point a, Point b) {
    if (a.x < b.x) return true;
    else if (a.x > b.x) return false;
    else {
        return a.y < b.y;
    }
}

void constructConvexHull() {
    vector<Point>::iterator it;
    for (it = polygon.begin(); it != polygon.end(); ++it) {
        if (up.size() < 2) {
            up.push_back(*it);
        } else {
            while (up.size() >= 2) {
                Point s1 = *(up.end() - 1);
                Point s2 = *(up.end() - 2);
                Segment s = Segment(s2, s1);
                //如果在逆时针方向，则删除up中的最后一个点
                if (ccw(s, *it) == COUNTER_CLOCKWISE) {
                    up.pop_back();
                } else break;
            }
            up.push_back(*it);
        }
    }

    for (it = polygon.end() - 1; it != polygon.begin() - 1; --it) {
        if (down.size() < 2) {
            down.push_back(*it);
        } else {
            while (down.size() >= 2) {
                Point s1 = *(down.end() - 1);
                Point s2 = *(down.end() - 2);
                Segment s = Segment(s2, s1);

                if (ccw(s, *it) == COUNTER_CLOCKWISE) {
                    down.pop_back();
                } else break;
            }
            down.push_back(*it);
        }
    }
}

int main() {
    scanf("%d", &n);
    int x, y;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        polygon.push_back(Point(x, y));
    }
    sort(polygon.begin(), polygon.end(), cmp);
    constructConvexHull();
    vector<Point>::iterator it;
//    for (it = polygon.begin(); it != polygon.end(); ++it){
//        printf("%d %d\n", (*it).x, (*it).y);
//    }
    printf("%d\n", up.size() + down.size() - 2);
    vector<Point>::iterator flag;
    int minY = INF;
    for (it = down.end() - 1; it != down.begin(); --it) {
        if (minY > (*it).y) {
            minY = (*it).y;
            flag = it;
        }
    }
    for (it = flag; it != down.begin(); --it) {
        printf("%d %d\n", (*it).x, (*it).y);
    }
    for (it = up.end() - 1; it != up.begin(); --it) {
        printf("%d %d\n", (*it).x, (*it).y);
    }
    for (it = down.end() - 1; it != flag; --it) {
        printf("%d %d\n", (*it).x, (*it).y);
    }

}