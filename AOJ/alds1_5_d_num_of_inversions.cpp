//
// Created by 李青坪 on 2018/10/14.
//

#include "cstdio"
using namespace std;
typedef long long llong;

int a[200001];
int MAXINT = 2000000000;
llong count = 0;

int merge(int low, int mid, int high){
    int lenLow = mid - low;
    int lenHigh = high - mid;
    int lowNum[lenLow+1], highNum[lenHigh+1];
    for (int i = 0; i < lenLow; ++i) {
        lowNum[i] = a[i+low];
    }
    for (int j = 0; j < lenHigh; ++j) {
        highNum[j] = a[j+mid];
    }
    lowNum[lenLow] = MAXINT;
    highNum[lenHigh] = MAXINT;
    int i=0, j=0;
    for (int k = low; k < high; ++k) {
        if (lowNum[i] <= highNum[j]){
            a[k] = lowNum[i];
            ++i;
        }
        else{
            a[k] = highNum[j];
            count += (lenLow - i);
            ++j;
        }
    }
}
int countInversion(int low, int high){
    if (low + 1 < high){
        int mid = (low + high)/2;
        countInversion(low, mid);
        countInversion(mid, high);
        merge(low, mid, high);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    countInversion(0, n);
    printf("%ld\n", count);
}
/*
5
3 5 2 1 4
 */