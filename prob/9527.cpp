#include <bits/stdc++.h>

using namespace std;

vector<int64_t> v (65, 0);

int64_t cnt(int64_t num){
    int64_t round_nearest = 57;
    int64_t sum = 0;
    int64_t one_cnt = 0;
    for(int64_t i = round_nearest; i >= 0; i--){
        if(num & ((int64_t)1 << i)){
            sum += (one_cnt * ((int64_t)1 << i)) + v[i];
            one_cnt++;
        }

    }
    sum += one_cnt;
    return sum;
}


int main(){
    int64_t a, b;
    cin >> a >> b;

    v[1] = 1;

    int64_t sum = 1;
    for(int64_t i = 2; i < 57; i++){
        v[i] = (((int64_t)1 << i) - ((int64_t)1 << (i - (int64_t)1))) + sum;
        sum += v[i];
        v[i] = sum;
    }
    cout << cnt(b) - cnt(a - 1) << "\n";
}
