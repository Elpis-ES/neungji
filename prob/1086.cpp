#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll dp_arr[1<<15][100];
string num_arr[15];
int mod_arr[15];
int digit_arr[15];

ll fact(int i){
    return i == 1 ? 1 : i * fact(i-1);
}

int mod10(int pow, int k){
    if(pow == 0){
        return 1;
    }
    else if(pow == 1){
        return 10 % k;
    }
    else{
        int cur = mod10(pow >> 1, k);
        int ret = (cur * cur) % k;
        if(pow % 2 == 1){
            ret = (ret * 10) % k;
        }
        return ret;
    }
}

ll gcd(ll a, ll b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    int n, k;
    memset(dp_arr, 0, sizeof(ll) * (1<<15)*100);
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
        cin >> num_arr[i];
    }
    scanf(" %d", &k);
    int digit;
    int num;

    for(int i = 0; i < n; i++){
        num = 0;
        digit = 0;
        for(auto it = num_arr[i].begin(); it != num_arr[i].end(); it++){
            num = (num * 10 + (int)(*it - '0')) % k;
            digit++;
        }
        mod_arr[i] = num;
        digit_arr[i] = mod10(digit, k);
        dp_arr[1 << i][num] = 1;
    }
    int current_bit;
    int current_mod;
    for(int bit = 1; bit < (1 << n); bit++){
        for(int target = 0; target < n; target++){
            if(bit & (1 << target)){
                continue;
            }
            else{
                current_bit = bit | (1 << target);
                for(int j = 0; j < k; j++){
                    current_mod = (j * digit_arr[target] + mod_arr[target]) % k;
                    dp_arr[current_bit][current_mod] += dp_arr[bit][j];
                }
            }
        }
    }
    ll f = fact(n);
    ll is_0 = dp_arr[(1 << n) - 1][0];
    if(is_0 == 0){
        printf("0/1\n");
    }
    else if(is_0 == f){
        printf("1/1\n");
    }
    else{
        ll g = gcd(is_0, f);
        printf("%lld/%lld\n", is_0/g, f/g);
    }

}
