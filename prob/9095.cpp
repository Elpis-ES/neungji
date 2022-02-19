#include <bits/stdc++.h>

int a[12] = {0, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504};

int main(void){
    int n, i, j;
    scanf(" %d", &n);
    for(i = 0; i < n; i++){
        scanf(" %d", &j);
        printf("%d\n", a[j]);
    }
}
