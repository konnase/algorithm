//
// Created by 李青坪 on 2018/10/11.
//

#include <string>
#include "cstdio"
using namespace std;

struct Card{
    int index;
    char ch;
    int num;
};

void swap(Card c[], int i, int j){
    Card temp = c[i];
    c[i] = c[j];
    c[j] = temp;
}

int partion(Card c[], int low, int high){
    Card x = c[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (c[j].num <= x.num){
            ++i;
            swap(c, i, j);
        }
    }
    swap(c, i+1, high);
    return i+1;
}

int quickSort(Card c[], int low, int high){
    if (low < high){
        int index = partion(c, low, high);
        quickSort(c, low, index-1);
        quickSort(c, index+1, high);
    }
}

void print(Card c[], int n){
    int stable = 1;
    for (int i = 0; i < n; ++i) {
        if (i) {
            if (c[i].num == c[i-1].num && c[i].index < c[i-1].index){
                stable = 0;
            }
        }
    }
    if (stable) printf("Stable\n");
    else printf("Not stable\n");

    for (int i = 0; i < n; ++i) {
        if (i) {
            printf("\n");
            if (c[i].num == c[i-1].num && c[i].index < c[i-1].index){
                stable = 0;
            }
        }

        printf("%c %d", c[i].ch, c[i].num);
    }
    printf("\n");
}

int main(){
    int n ;
    scanf("%d", &n);
    Card c[n];
    for (int i = 0; i < n; ++i) {
        char ch;
        int in;
        scanf("%c", &ch);
        if (ch == '\n') {
            --i;
            continue;
        }
        scanf("%d", &in);
        c[i].index = i;
        c[i].ch = ch;
        c[i].num = in;
//        printf("%c %d\n", c[i].ch, c[i].num);
    }
//    print(c, n);
    quickSort(c, 0, n-1);
    print(c, n);
}