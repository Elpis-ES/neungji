#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    priority_queue<tuple<int, int>> pq;
    vector<int> v(k);

    for(int i = 0; i < n; i++){
        int m, v;
        cin >> m >> v;
        pq.emplace(-m, v);
    }

    for(int i = 0; i < k; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    ll total = 0;
    priority_queue<int> s;
    for(int i = 0; i < k; i++){
        while(!pq.empty()){
            auto [mass, val] = pq.top();
            mass = -mass;
            if(mass > v[i]){
                break;
            }
            pq.pop();
            s.emplace(val);
        }
        if(!s.empty()){
            total += s.top();
            s.pop();
        }
    }
    cout << total << "\n";
}

