#include <bits/stdc++.h>

using namespace std;
vector<int> price_arr;
vector<pair<pair<int, int>, int> > ore;
int dp_arr[10001];

int dp(int target){
    if(dp_arr[target] != -1){
        return dp_arr[target];
    }
    if(target >= ore.size()){
        return 0;
    }

    int cur_max = ore[target].second;
    for(int i = target + 1; i < ore.size(); i++){
        if(ore[i].first.first >= ore[target].first.second){
            cur_max = max(cur_max, ore[target].second + dp(i));
        }
    }
    dp_arr[target] = cur_max;
    return cur_max;
}

int main(){
    int m, n;
    int tmp;
    int f, t, type;

    memset(dp_arr, -1, sizeof(dp_arr));

    scanf(" %d %d", &m, &n);
    for(int i = 0; i < m; i++){
        scanf(" %d", &tmp);
        price_arr.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        scanf(" %d %d %d", &f, &t, &type);
        ore.push_back(make_pair(make_pair(f, t), (t-f)*price_arr[type - 1]));
    }

    sort(ore.begin(), ore.end());

    int start, end, price;

    int max_price = -1;
    for(int i = 0; i < ore.size(); i++){
        max_price = max(max_price, dp(i));
    }
    printf("%d\n", max_price);
}
