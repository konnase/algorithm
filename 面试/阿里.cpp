//评测题目: n个数字，写一个c++函数实现topk
#include<iostream>
#include<vector>

using namespace std;


int partition(int l, int r, vector<int> array){
    int i = -1;
    int t = array[r];
    for (int j = 0; j <= r; ++j){
        if (array[j] >= t){
            int temp = array[j];
            array[j] = array[++i];
            array[i] = temp;
        }
    }
    int temp = array[r];
    array[r] = array[++i];
    array[i] = temp;
    return i;
}

vector<int> topK(int l, int r, int k,vector<int> array){
    int mid = (l+r)/2;
    int i = partition(l, r, array);
    
    if (i == k-1){
        vector<int> temp(array.begin(), array.begin()+i);
        return temp;
    }
    else if (i > k-1){
        return topK(0, i-1, k, array);
    }
    else {
        vector<int> right = topK(i+1, r, k, array);
        right.insert(right.end(), array.begin(), array.begin()+i+1);
        return right;
    }
    
}

vector<int> findTopK(vector<int> a, int k){
    int len = a.size();
    if (len == 0 || k == 0){
        return vector<int>();
    }
    vector<int> array = a;
    vector<int> result = topK(0, len-1, k, array);
    return result;
}


int main(){
    vector<int> arr({12,3,2,43,2,5});
    vector<int> result = findTopK(arr, 2);
    for (auto item: result){
        cout << item << endl;
    }
}
