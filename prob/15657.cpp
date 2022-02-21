#include <bits/stdc++.h>

using namespace std;

int arr[8];
int m;
vector<int> v;

void array_print(int digit, int idx, int n){
    arr[digit] = v[idx];
    if(digit + 1 == m){
        for(int j = 0; j < m; j++){
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
    else{
        for(int i = idx; i < n; i++){
            array_print(digit + 1, i, n);
        }
    }
}

int main(){
    int n, num;
    scanf(" %d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf(" %d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        array_print(0, i, n);
    }
}
