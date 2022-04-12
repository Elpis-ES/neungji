#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        v.emplace_back(make_pair(t, -1));
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < k;  i++){
        int cur;
        cin >> cur;
        auto it = upper_bound(v.begin(), v.end(), make_pair(cur, INT_MAX));
        int search_idx = it - v.begin();

        while(v[search_idx].second != -1){
            search_idx = v[search_idx].second;
        }


        v[search_idx].second = search_idx + 1;
        it->second = search_idx + 1;

        cout << v[search_idx].first << "\n";

    }
}
