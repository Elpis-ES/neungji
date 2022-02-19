#include <bits/stdc++.h>

using namespace std;

int dp_arr[1001][31][2];
vector <int> v;
int t;

int dp(int cur, int w, int pos){
    if(cur == t){
        return 0;
    }
    if(dp_arr[cur][w][pos] != -1){
        return dp_arr[cur][w][pos];
    }
    int ret;
    if(w <= 0){
        w = 0;
        ret = dp(cur + 1, 0, pos);
        if(pos == v[cur]){
            ret++;
        }
    }
    else{
        if(pos == v[cur]){
            ret = max(dp(cur + 1, w, pos) + 1, dp(cur + 1, w - 1, (pos + 1) % 2));
        }
        else{
            ret = max(dp(cur + 1, w, pos), dp(cur + 1, w - 1, (pos + 1) % 2) + 1);
        }
    }
    dp_arr[cur][w][pos] = ret;
    return ret;
}

int main(){
    memset(dp_arr, -1, sizeof(dp_arr));
    int w, tmp;
    scanf(" %d %d", &t, &w);
    for(int i = 0; i < t; i++){
        scanf(" %d", &tmp);
        v.push_back(tmp - 1);
    }
    printf("%d\n", max(dp(0, w, 0), dp(0, w-1, 1)));
}
