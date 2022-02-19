#include <bits/stdc++.h>

using namespace std;

int arr[1001];
pair<int, int> exclusive_dp[1001];
pair<int, int> inclusive_dp[1001];

pair<pair<int, int>, pair<int, int> > dp(int i){
    if(i == 1){
        return make_pair(make_pair(0, 0), make_pair(arr[1], arr[1]));
    }
    if(exclusive_dp[i]!=make_pair(0, 0) && inclusive_dp[i]!=make_pair(0, 0)){
        return make_pair(exclusive_dp[i], inclusive_dp[i]);
    }
    int excl_val, excl_max, incl_val, incl_max;
    excl_val = -1;
    excl_max = -1;
    incl_max = -1;
    incl_val = -1;
    pair<int, int> dp_incl_max;
    pair<int, int> dp_excl_max;
    pair<pair<int, int>, pair<int, int> >cur;
    for(int j = 1; j < i; j++){
        cur = dp(j);
        dp_excl_max = max(cur.first, cur.second);
        if(dp_excl_max.first > excl_max){
            excl_max = dp_excl_max.first;
            excl_val = dp_excl_max.second;
        }

        if(cur.first.second < arr[i]){
            dp_incl_max.second = arr[i];
            dp_incl_max.first = cur.first.first + arr[i];
        }
        if(cur.second.second < arr[i]){
            if(dp_incl_max.first < cur.second.first + arr[i]){
                dp_incl_max.first = cur.second.first + arr[i];
                dp_incl_max.second = arr[i];
            }
        }
        if(dp_incl_max.first > incl_max){
            incl_max = dp_incl_max.first;
            incl_val = dp_incl_max.second;
        }
    }

    exclusive_dp[i].first = excl_max;
    exclusive_dp[i].second = excl_val;
    inclusive_dp[i].first = incl_max;
    inclusive_dp[i].second = incl_val;

    return make_pair(exclusive_dp[i], inclusive_dp[i]);
}

int main(){
    int n;
    scanf(" %d", &n);
    for(int i = 1; i <= n; i++){
        scanf(" %d", &arr[i]);
    }
    printf("%d\n", max(dp(n).first, dp(n).second).first);
}
