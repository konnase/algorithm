//
// Created by 李青坪 on 2018/10/8.
//

#include "cstdio"

using namespace std;

#define INFINITY 2000000000;

int a[500000];
int cnt = 0;

void merge(int a[], int low, int mid, int high){
    int l1 = mid - low;
    int l2 = high - mid;
    int s1[l1+1];
    int s2[l2+1];
    for (int i = 0; i < l1; ++i) {
        s1[i] = a[i+low];
    }
    for (int j =0; j < l2; ++j) {
        s2[j] = a[j+mid];
    }
    s1[l1] = s2[l2] = INFINITY;
    int i=0, j=0;
    for (int k = low; k < high; ++k) {
        ++cnt;
        if (s2[j] >= s1[i]) {
            a[k] = s1[i];
            ++i;
        }
        else{
            a[k] = s2[j];
            ++j;
        }
    }
}

void mergeSort(int a[], int low, int high){
    if (low+1 < high){
        int mid = (low + high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid, high);
        merge(a, low, mid, high);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n);
    printf("%d", a[0]);
    for (int j = 1; j < n; ++j) {
        printf(" %d", a[j]);
    }
    printf("\n%d\n", cnt);
}
/*
10
8 5 9 2 6 3 7 1 10 4
 */