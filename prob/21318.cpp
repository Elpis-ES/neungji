#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main(){
    int n;
    int cur, prev;
    scanf(" %d", &n);
    arr[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf(" %d", &cur);
        if(i == 0){
            cur = prev;
        }
        if(prev > cur){
            arr[i] = arr[i-1] + 1;
        }
        else{
            arr[i] = arr[i-1];
        }
        prev = cur;

    }
    int q, f, t;
    scanf(" %d", &q);
    for(int i = 0; i < q; i++){
        scanf(" %d %d", &f, &t);
        printf("%d\n", arr[t] - arr[f]);
    }

}
