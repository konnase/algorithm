//
// Created by 李青坪 on 2018/10/15.
//

#include "cstdio"
#include "algorithm"
using namespace std;
#define MAXN 1000
#define MAXV 10000

int a[MAXN], b[MAXN];
int T[MAXV+1]; //记录排序过后原来的元素应该移动到的位置
int m = MAXV;

int findMinimumCost(int n){
    bool v[n];
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
        v[i] = false;
    }
    sort(b, b+n);
    for (int j = 0; j < n; ++j) {
        T[b[j]] = j;
    }
    int S = 0;
    for (int k = 0; k < n; ++k) {
        if (v[k]) continue;
        int cur = k;
        int nn = 0; //记录圆中有多少个元素
        int sm = MAXV; //记录圆中的最小元素
        int sum = 0; //记录圆中各元素的和
        while (true){
            v[cur] = true;
            int value = a[cur];
            ++nn;
            sum += value;
            sm = min(sm, value);
            cur = T[value];
            if (cur == k) break;
        }
        S += min(sum + (nn-2)*sm, sum + sm + (nn+1)*m); //是圆内交换代价更小还是借用外来元素的代价更小
    }
    return S;
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        m = min(m, a[i]);
    }
    int ans = findMinimumCost(n);
    printf("%d\n", ans);
}
/*
5
1 5 3 4 2
 */