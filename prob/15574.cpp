#include <bits/stdc++.h>

using namespace std;

#define ll long long
vector< pair <ll, ll> > v;
int i;

long double dp_arr[1001];

long double dp(int n){
    if(dp_arr[n] != -1){
        return dp_arr[n];
    }
    ll cur_x = v[n].first;
    ll cur_y = v[n].second;
    long double cur_max = 0;
    long double tmp;
    ll dx, dy;
    for(int j = n+1; j < i; j++){
        if(v[j].first != cur_x){
            dy = v[j].second - cur_y;
            dx = v[j].first - cur_x;
            tmp = dp(j) + sqrt(dx * dx + dy * dy);
            if(cur_max < tmp){
                cur_max = tmp;
            }
        }
    }
    dp_arr[n] = cur_max;
    return cur_max;
}

int main(){
    ll x, y;
    fill_n(dp_arr, 1001, -1);
    scanf(" %d", &i);
    for(int n = 0; n < i; n++){
        scanf(" %lld %lld", &x, &y);
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    long double max = -1;
    long double tmp;
    for(int n = 0; n < i; n++){
        tmp = dp(n);
        if(tmp > max){
            max = tmp;
        }
    }
    printf("%Lf\n", max);
    return 0;
}
