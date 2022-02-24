#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int money, days;

int dp_arr[1001][201][11];

int dp(int day, int left_money, int prev_money){
    if(dp_arr[day][left_money][prev_money] != -1){
        return dp_arr[day][left_money][prev_money];
    }
    int ret = INT_MAX;

    for(int i = 0; i <= left_money; i++){
        if(i + v[day] > 10){
            break;
        }
        int diff = (v[day] + i) - (v[day - 1] + prev_money);
        if(diff >= 0){
            diff = 0;
        }
        int cur = day == days ? diff * diff : diff * diff + dp(day + 1, left_money - i, i);
        ret = min(ret, cur);
    }
    dp_arr[day][left_money][prev_money] = ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp_arr, -1, sizeof(dp_arr));

    cin >> days >> money;

    int tmp;
    v.emplace_back(0);
    for(int i = 0; i < days; i++){
        cin >> tmp;
        v.emplace_back(tmp);
    }
    cout << dp(1, money, 0) << "\n";
}
