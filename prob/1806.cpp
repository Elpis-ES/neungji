#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;
    vector<int> v(n);

    int psum_len = INT_MAX;
    int start = 0;
    int end = 0;
    int cur_sum = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        cur_sum += v[i];
        end++;
        if(cur_sum >= s){
            psum_len = min(psum_len, end - start);
        }
        while(cur_sum >= s && start < end){
            cur_sum -= v[start];
            start++;
            if(cur_sum >= s){
                psum_len = min(psum_len, end - start);
            }
        }
    }

    if(psum_len == INT_MAX){
        psum_len = 0;
    }
    cout << psum_len << "\n";
}
