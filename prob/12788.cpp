#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v (n);
    for (auto &i : v){
        cin >> i;
    }
    sort(v.begin(), v.end(), greater<int>());
    int cnt = 0;
    int t = m * k;
    int cur = 0;
    bool found = false;
    for(auto i : v){
        cur += i;
        cnt++;
        if(cur >= t){
            found = true;
            break;
        }
    }
    if(found){
        cout << cnt << "\n";
    }
    else{
        cout << "STRESS\n";
    }
}
