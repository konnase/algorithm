//
// Created by 李青坪 on 2018/10/12.
//

#include "cstdio"

using namespace std;

int a[2000001];
int b[2000001];
int c[10001];
int MAXK = 10001;

void countingSort(int n){
    for (int i = 0; i < MAXK; ++i) {
        c[i] = 0;
    }
    for (int j = 1; j <= n; ++j) {
        ++c[a[j]];
    }
    for (int k = 1; k < MAXK; ++k) {
        c[k] = c[k] + c[k-1];
    }
    for (int l = n; l > 0; --l) {
        int index = c[a[l]];
        b[index] = a[l];
        --c[a[l]];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    countingSort(n);
    for (int j = 1; j <= n; ++j) {
        if (j-1) printf(" ");
        printf("%d", b[j]);
    }
    printf("\n");
}
/*
15
43 2131 435 6654 12 435 567 345 212 5 87 43 123 34  678
 */