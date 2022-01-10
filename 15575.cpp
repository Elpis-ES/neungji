#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

vector< pair <ll, ll> > v;
int i;

ld dp_arr[1000001];
int dp_top[1000001];
int dp_bottom[1000001];

ld dist(int n, int m){
    ld dy = v[m].second - v[n].second;
    ld dx = v[m].first - v[n].first;
    return sqrt(dy*dy + dx*dx);
}

ld dp(int n){
    if(dp_arr[n] != -1){
        return dp_arr[n];
    }

    int top_idx = dp_top[n];
    int bottom_idx = dp_bottom[n];

    if(top_idx == -1 && bottom_idx == -1){
        dp_arr[n] = 0;
    }
    else if(top_idx == bottom_idx){
        dp_arr[n] = dp(top_idx) + dist(n, top_idx);
    }
    else{
        dp_arr[n] = max((dp(top_idx) + dist(n, top_idx)), (dp(bottom_idx) + dist(n, bottom_idx)));
    }
    return dp_arr[n];
}

int main(){
    ll x, y;
    scanf(" %d", &i);
    fill_n(dp_arr, i, -1);
    for(int n = 0; n < i; n++){
        scanf(" %lld %lld", &x, &y);
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());

    int cur_idx = 0;
    int nxt_bottom;
    int nxt_top;

    while(cur_idx != i){
        nxt_bottom = distance(v.begin(), lower_bound(v.begin(), v.end(), make_pair(v[cur_idx].first+1, numeric_limits<ll>::min())));
        nxt_top = distance(v.begin(), lower_bound(v.begin(), v.end(), make_pair(v[nxt_bottom].first+1, numeric_limits<ll>::min()))) - 1;
        if(nxt_bottom == i){
            fill(dp_bottom + cur_idx, dp_bottom + i, -1);
            fill(dp_top + cur_idx, dp_top + i, -1);
            break;
        }
        fill(dp_bottom + cur_idx, dp_bottom + nxt_bottom, nxt_bottom);
        fill(dp_top + cur_idx, dp_top + nxt_bottom, nxt_top);
        cur_idx = nxt_bottom;
    }

    ld max = -1;
    ld tmp = dp(0);
    ld tmp2 = dp(dp_bottom[0] - 1);
    printf("%.9Lf\n", tmp > tmp2 ? tmp : tmp2);
    return 0;
}
