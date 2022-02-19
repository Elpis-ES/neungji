#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

ull gcd(ull a, ull b, ull res){
    if (a == b){
        return res * a;
    }

    ull bin_a = a % 2;
    ull bin_b = b % 2;

    if(bin_a == 0 && bin_b == 0){
        return gcd(a >> 1, b >> 1, res << 1);
    }
    else if (bin_a == 0){
        return gcd(a >> 1, b , res);
    }
    else if (bin_b == 0){
        return gcd(a, b >> 1, res);
    }
    else{
        return a > b ? gcd(a-b, b, res) : gcd(a, b-a, res);
    }
}

int main(void){
    int d, m, i;
    ull gcd_val = 0;
    ull target;
    ull lcm_val = 0;

    scanf(" %d %d", &d, &m);

    for(i = 0; i < d; i++){
        scanf(" %llu", &target);
        if(lcm_val == 0){
            lcm_val = target;
        }
        else{
            lcm_val = target * lcm_val / gcd(target, lcm_val, 1);
        }
    }

    for(i = 0; i < m; i++){
        scanf(" %llu", &target);
        if(gcd_val == 0){
            gcd_val = target;
        }
        else{
            gcd_val = gcd(gcd_val, target, 1);
        }
    }

    ull cnt = 0;
    ull j;
    for(j = 1; j*j < gcd_val; j++){
        if(gcd_val % j == 0){
            if(j % lcm_val == 0){
                cnt++;
            }
            if(((gcd_val / j) % lcm_val) ==0){
                cnt++;
            }
        }
    }
    if(j*j == gcd_val && j % lcm_val == 0){
        cnt++;
    }

    printf("%llu\n", cnt);
}
