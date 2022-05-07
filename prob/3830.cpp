#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct disjoint_set{
    vector<int> group;
    vector<ll> weight;
    vector<ll> pending;

    disjoint_set(int n): group(n + 1), weight(n + 1, 0), pending(n + 1, 0){
        for(int i = 1; i <= n; i++){
            group[i] = i;
        }
    }

    void merge(int i, int j, ll diff){
        auto [g_i, w_i] = find(i);
        cout << g_i << " " << w_i << "\n";
        auto [g_j, w_j] = find(j);
        cout << g_j << " " << w_j << "\n";
        if(g_i != g_j){
            pending[g_j] += diff;
            weight[g_j] = w_i;
            group[g_j] = g_i;
        }
    }

    pair<int, ll> find(int i){
        if(i == group[i]){
            return make_pair(i, weight[i]);
        }
        auto[g, w] = find(group[i]);
        group[i] = g;
        weight[i] = w;
        return make_pair(group[i], weight[i] + pending[i]);
    }
    void p(){
        cout << "G: ";
        for(auto i : group){
            cout << i << " ";
        }
        cout << "\nW: ";
        for(auto i : weight){
            cout << i << " ";
        }
        cout << "\nP: ";
        for(auto i : pending){
            cout << i << " ";
        }
        cout << "\n";

    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        disjoint_set ds(n);
        for(int i = 0; i < m; i++){
            char c;
            cin >> c;
            if(c == '!'){
                int a, b;
                ll d;
                cin >> a >> b >> d;
                ds.merge(a, b, d);
            }
            else{
                int a, b;
                cin >> a >> b;
                auto [g_a, w_a] = ds.find(a);
                auto [g_b, w_b] = ds.find(b);
                if(g_a != g_b){
                    cout << "UNKNOWN\n";
                }
                else{
                    cout << w_b - w_a << "\n";
                }
            }
            ds.p();
        }
    }
}
