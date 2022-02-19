#include <bits/stdc++.h>

using namespace std;

vector< pair <int, int> > v;
int dp[101][100001];

int do_dp(int i, int w, int n){
    if(w <= 0 || i >= n){
        return 0;
    }
    if(dp[i][w] != 0){
        return dp[i][w];
    }

    int a;
    if(w - v[i].second < 0){
        a = 0;
    }
    else{
        a = v[i].first + do_dp(i+1, w - v[i].second, n);
    }
    int b = do_dp(i+1, w, n);

    dp[i][w] = max(a, b);
    return dp[i][w];

}


int main(void){
    int N, K, i;
    int w, val;
    scanf(" %d %d", &N, &K);
    for(i = 0; i < N; i++){
        scanf(" %d %d", &w, &val);
        v.push_back(make_pair(val, w));
    }
    printf("%d\n", do_dp(0, K, N));


    return 0;
}
