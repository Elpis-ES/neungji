#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int min_idx = INT_MAX;
    int max_idx = INT_MIN;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        min_idx = min(min_idx, tmp);
        max_idx = max(max_idx, tmp);
        auto target = m.find(tmp);
        if(target == m.end()){
            m[tmp] = 1;
        }
        else{
            target->second++;
        }

    }

    if(m.find(min_idx + 1) == m.end()){
        cout << "-1\n";
        return 0;
    }
    m[min_idx]--;
    m[min_idx + 1]--;
    for(int i = (m[min_idx] == 0 ? min_idx + 1 : min_idx); i < max_idx; i++){
        auto cur = m.find(i);
        auto nxt = m.find(i + 1);
        if(cur == m.end() || nxt == m.end() || cur->second <= 0){
            cout << "-1\n";
            return 0;
        }
        nxt->second -= cur->second;
        cur->second = 0;

    }
    if (m[max_idx] != 0){
        cout << "-1\n";
    }
    else{
        cout << "1\n";
    }

    return 0;

}
