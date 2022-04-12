#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v;
    vector<pair<int, int>> p(n);
    vector<int> size(n);

    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());

    int max_size = INT_MIN;
    int max_idx;

    for(int i = 0; i < n; i++){
        int cur_size;
        auto t = lower_bound(v.begin(), v.end(), p[i].second);
        if(t == v.end()){
            v.emplace_back(p[i].second);
            cur_size = v.size();
        }
        else{
            *t = p[i].second;
            cur_size = t - v.begin() + 1;
        }
        if(cur_size > max_size){
            max_size = cur_size;
            max_idx = i;
        }
        size[i] = cur_size;
    }


    cout << p.size() - max_size << "\n";

    vector<int> lcs_arr;
    lcs_arr.emplace_back(p[max_idx].first);
    int cur_max = p[max_idx].second;
    max_size--;
    for(int i = max_idx - 1; i >= 0; i--){
        if(max_size == 0){
            break;
        }
        if(size[i] == max_size && p[i].second < cur_max){
            cur_max = p[i].second;
            max_size--;
            lcs_arr.emplace_back(p[i].first);
        }
    }

    sort(lcs_arr.begin(), lcs_arr.end());

    int c = 0;
    for(int i = 0; i < n; i++){
        if(p[i].first == lcs_arr[c]){
            c++;
        }
        else{
            cout << p[i].first << "\n";
        }
    }


}
