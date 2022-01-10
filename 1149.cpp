#include <bits/stdc++.h>

using namespace std;

int r[2001];
int g[2001];
int b[2001];

int dp(int i, int N, int color){
    int ret;
    if(i >= N){
        return 0;
    }
    switch(color){
        case 0:
            if(r[1000+i] != 0){
                ret = r[1000+i];
            }
            else{
                ret = r[i] + min(dp(i+1, N, 1), dp(i+1, N, 2));
                r[1000+i] = ret;
            }
            break;
        case 1:
            if(g[1000+i] != 0){
                ret = g[1000+i];
            }
            else{
                ret = g[i] + min(dp(i+1, N, 0), dp(i+1, N, 2));
                g[1000+i] = ret;
            }
            break;
        case 2:
            if(b[1000+i] != 0){
                ret = b[1000+i];
            }
            else{
                ret = b[i] + min(dp(i+1, N, 0), dp(i+1, N, 1));
                b[1000+i] = ret;
            }
            break;
    }
    return ret;
}

int main(void){
    int N, i;
    scanf(" %d", &N);
    for(i = 0; i < N; i++){
        scanf(" %d %d %d", &r[i], &g[i], &b[i]);
    }
    printf("%d\n", min(min(dp(0, N, 0), dp(0, N, 1)), dp(0, N, 2)));

    return 0;

}
