//
// Created by 李青坪 on 2019-03-26.
//

#include <vector>
#include <iostream>

using namespace std;

const int MAXN = int(1e9);

class Solution {
private:
    long long count = 0;
    vector<int> a;
public:
    void mergeA(int l, int mid, int r) {
        int len1 = mid-l+1;
        int len2 = r-mid;
        int a1[len1+1], a2[len2+1];
        a1[len1] = MAXN;
        a2[len2] = MAXN;
        for (int i = 0; i < len1; ++i) {
            a1[i] = a[i+l];
        }
        for (int i = 0; i < len2; ++i) {
            a2[i] = a[i+mid+1];
        }
        int i = 0, j = 0;
        for (int k = l; k <= r; ++k) {
            if (a1[i] > a2[j]) {
                a[k] = a2[j++];

            } else {
                a[k] = a1[i++];
                count += j;
            }
        }

    }

    void mergeSort(int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = (l+r)/2;
        mergeSort(l, mid);
        mergeSort(mid+1, r);
        mergeA(l, mid, r);
    }

    int InversePairs(vector<int> data) {
        a = data;
        mergeSort(0, data.size()-1);
//        for (auto i : a) {
//            cout << i << " ";
//        }
//        cout << endl;
        return count%1000000007;
    }
};

int main(){
    Solution s;
    vector<int> a = vector<int>({1,2,3,4,5,6,7,0});
    cout << s.InversePairs(a);
}