#include <bits/stdc++.h>

#define ull unsigned long long
#define uint unsigned int

using namespace std;

ull dp_arr[101][101];

ull dp_cnt(uint a, uint z){
    if(a == 0 && z == 0){
        return 0;
    }
    else if(a == 0 || z == 0){
        return 1;
    }
    if(dp_arr[a][z] != 0){
        return dp_arr[a][z];
    }
    dp_arr[a][z] = dp_cnt(a-1, z) + dp_cnt(a, z-1);
    return dp_arr[a][z];
}

void dp(uint a, uint z, ull cnt){
    if(a == 0 && z != 0){
        for(uint i = 0; i < z; i++)
            printf("z");
        printf("\n");
        return;
    }
    else if(a != 0 && z == 0){
        for(uint i = 0; i < a; i++)
            printf("a");
        printf("\n");
        return;
    }
    else if(a == 0 && z == 0){
        return;
    }
    ull cur = dp_cnt(a-1, z);
    if(cur >= cnt){
        printf("a");
        dp(a-1, z, cnt);
    }
    else{
        printf("z");
        dp(a, z-1, cnt - cur);
    }
}

int main(){
    memset(dp_arr, 0, sizeof(ull) * 101 * 101);
    uint m, n, k;
    scanf(" %u %u %u", &n, &m, &k);
    if(dp_cnt(n, m) < k){
        printf("-1\n");
    }
    else{
        dp(n, m, k);
    }
}
