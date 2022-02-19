#include <bits/stdc++.h>

int queen[14] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596};

int main(){
    int n;
    scanf(" %d", &n);
    printf("%d\n", queen[n-1]);
}
