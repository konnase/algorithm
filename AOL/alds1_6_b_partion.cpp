//
// Created by 李青坪 on 2018/10/11.
//

#include "cstdio"

using namespace std;

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partion(int a[], int low, int high){
    int x = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (a[j] <= x){
            ++i;
            swap(a, i, j);
        }
    }
    swap(a, i+1, high);
    return i+1;
}

int main(){
    int n ;
    scanf("%d", &n);
    int a[100000];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int index = partion(a, 0, n-1);
    for (int j = 0; j < n; ++j) {
        if (j) printf(" ");
        if (j == index){
            printf("[%d]", a[j]);
        }
        else{
            printf("%d",a[j]);
        }
    }
    printf("\n");
}