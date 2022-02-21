#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int main(){
    int n, a, b, c;
    int g;
    int grad_x, grad_y;
    unordered_map<pair<int, int>, ull, hash_pair> m;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
        scanf(" %d %d %d", &a, &b, &c);
        if(a == 0){
            grad_x = 0;
            grad_y = 1;
        }
        else if(b == 0){
            grad_x = 1;
            grad_y = 0;
        }
        else{
            g = gcd(abs(a), abs(b));
            grad_x = a / g;
            grad_y = b / g;
            if(grad_x < 0){
                grad_x = grad_x * -1;
                grad_y = grad_y * -1;
            }
        }
        auto it = m.find(make_pair(grad_x, grad_y));
        if(it != m.end()){
            it->second ++;
        }
        else{
            m.insert({make_pair(grad_x, grad_y), 1});
        }

    }
    ull res = 0;
    ull prev_psum = 0;
    vector<ull> psum_arr;
    psum_arr.push_back(0);
    for(auto it2 = m.begin(); it2 != m.end(); it2++){
        prev_psum += it2->second;
        psum_arr.push_back(prev_psum);
    }
    for(int i = 1; i < psum_arr.size(); i++){
        int cur_mult = psum_arr[i] - psum_arr[i-1];
        int mult_val = psum_arr[psum_arr.size() - 1] - psum_arr[i];
        res += mult_val * cur_mult;
    }
    printf("%llu\n", res);

}
