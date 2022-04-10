#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> s;
    vector<pair<int, int>> v(10, make_pair(-1, false));

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string ss;
        cin >> ss;
        s.emplace_back(ss);
        for(int j = 0; j < ss.length(); j++){
            int target_idx = ss[j] - 'A';
            int cur_digit = ss.length() - j - 1;
            v[target_idx].first = max(v[target_idx].first, cur_digit);
            if(cur_digit == 0){
                v[target_idx].second = 1;
            }
        }
    }
    for(auto [p, q] : v){
        cout << "(" << p << ", " << q << ") ";
    }

    cout << "\n";
}
