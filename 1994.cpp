#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> v;

int dp_arr[2001];
vector <ll> dp_list[2001];

int global_max = 1;

int dp(int idx){
    if(dp_arr[idx] != -1){
        return dp_arr[idx];
    }
    if(idx == 0){
        return 1;
    }
    else{

        int cur_max = 1;
        int cur_dp;
        vector <ll> cur_list;
        bool new_list;
        int cur_diff;
        int prev_diff = -1;

        for(int i = idx - 1; i >= 0; i--){
            new_list = false;
            cur_dp = dp(i);
            if(cur_dp < cur_max){
                continue;
            }
            else if(cur_dp > cur_max){
                new_list = true;
            }
            cur_diff = v[idx] - v[i];
            if(cur_diff == prev_diff){
                continue;
            }
            if(binary_search(dp_list[i].begin(), dp_list[i].end(), cur_diff) == true){
                if(new_list){
                    cur_max = cur_dp;
                    cur_list = vector <ll> ();
                    cur_list.push_back(cur_diff);
                }
                else{
                    cur_list.push_back(cur_diff);
                }
            }
            else{
                if(cur_max == 1){
                    cur_list.push_back(cur_diff);
                }
            }
            prev_diff = cur_diff;
        }
        dp_list[idx] = cur_list;
        dp_arr[idx] = cur_max + 1;
        if(cur_max + 1 > global_max){
            global_max = cur_max + 1;
        }
        return cur_max + 1;
    }
}


int main(){
    int n;
    ll num;
    memset(dp_arr, -1, sizeof(int) * 2001);
    dp_arr[0] = 1;
    scanf(" %d" , &n);

    for(int i = 0; i < n; i++){
        scanf(" %lld", &num);
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    dp(n-1);
    printf("%d\n", global_max);
}
