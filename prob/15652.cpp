#include <bits/stdc++.h>

int n, m;
int arr[8];

void make_arr(int digit, int i){
    arr[digit] = i;
    if(digit == m-1){
        for(int j = 0; j < m; j++){
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
    else{
        for(int j = i; j <=n; j++){
            make_arr(digit + 1, j);
        }
    }
}

int main(){
    scanf(" %d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        make_arr(0, i);
    }
}
