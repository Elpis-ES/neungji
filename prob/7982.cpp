#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cur_max = INT_MIN;
    int target_min = 1;

    vector<pair<int, int>> v;
    bool min_reached = false;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        cnt++;
        cur_max = max(cur_max, tmp);
        if(tmp == target_min){
            min_reached = true;
        }
        if(min_reached && cnt == cur_max - target_min + 1){
            min_reached = false;
            cnt = 0;
            v.emplace_back(target_min, cur_max);
            target_min = cur_max + 1;
            cur_max = INT_MIN;
        }
    }

    cout << v.size() << "\n";
    for (auto [start, end] : v){
        cout << end - start + 1 << " ";
        for(int i = start; i <= end; i++){
            cout << i << " ";
        }
        cout << "\n";
    }

}
