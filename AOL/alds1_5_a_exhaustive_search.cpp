//
// Created by 李青坪 on 2018/10/7.
//
/*
 * 搜索加剪枝
 */

#include <math.h>
#include "cstdio"
#define MAXN 100

using namespace std;

int a[MAXN];

int findSolution(int target, int sum, int low, int high){
    if (low > high) return 999999999;
    if (a[low] + sum == target) return target;
    for (int i = low; i <= high; ++i) {
        int temp = sum + a[i];
        if (temp == target) return temp;
        if (temp > target) continue;
        temp = findSolution(target, temp, i+1, high);
        if (temp == target) return temp;
    }
    return 999999999;
}

void search(int m[], int n, int q){
    for (int i = 0; i < q; ++i) {
        bool found = false;
        for (int j = 0; j < n; ++j) {
            if (a[j] == m[i]){
                found = true;
                printf("yes\n");
                break;
            }
            if (a[j] > m[i]) {
                continue;
            }
            int sum = findSolution(m[i], a[j], j+1, n-1);
            if (sum == m[i]){
                found = true;
                printf("yes\n");
                break;
            }
        }
        if (!found)
            printf("no\n");
    }
}

int main(){
    int n,q;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    int m[q];
    for (int j = 0; j < q; ++j) {
        scanf("%d", &m[j]);
    }
    search(m, n, q);
}

/*
5
1 5 7 10 21
8
2 4 17 8 22 21 100 35

20
28 16 43 6 12 34 62 54 5 12 43 54 73 46 23 26 47 2 65 83
8
2 4 9 8 22 21 100 1

 */