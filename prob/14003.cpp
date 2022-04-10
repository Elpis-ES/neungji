#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v;
    vector<int> num(n);
    vector<int> size(n);
    int max_size = INT_MIN;
    int max_idx;
    for(int i = 0; i < n; i++){
        int cur_size;
        cin >> num[i];
        auto t = lower_bound(v.begin(), v.end(), num[i]);
        if(t == v.end()){
            v.emplace_back(num[i]);
            cur_size = v.size();
        }
        else{
            *t = num[i];
            cur_size = t - v.begin() + 1;
        }
        if(cur_size > max_size){
            max_size = cur_size;
            max_idx = i;
        }
        size[i] = cur_size;
    }

    cout << max_size << "\n";

    vector<int> lcs_arr;
    lcs_arr.emplace_back(num[max_idx]);
    int cur_max = num[max_idx];
    max_size--;
    for(int i = max_idx - 1; i >= 0; i--){
        if(max_size == 0){
            break;
        }
        if(size[i] == max_size && num[i] < cur_max){
            cur_max = num[i];
            max_size--;
            lcs_arr.emplace_back(cur_max);
        }
    }
    for(auto it = lcs_arr.rbegin(); it != lcs_arr.rend(); it++){
        cout << *it << " ";
    }
    cout << "\n";

}
