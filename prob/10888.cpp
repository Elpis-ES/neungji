#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline ll get_pair(int i, int j){
    ll n = j - i;
    return 1ll * n * (n + 1) / 2;

}

inline ll get_route(int i, int j){
    ll n = j - i;
    return 1ll * n * (n + 1) * (n + 2) / 6;
}

class ds{
    private:
    vector<int> front;
    vector<int> end;
    ll pair_cnt;
    ll route_cnt;

    int find_front(int i){
        if (front[i] == i){
            return i;
        }
        return front[i] = find_front(front[i]);
    }
    int find_end(int i){
        if (end[i] == i){
            return i;
        }
        return end[i] = find_end(end[i]);
    }


    public:
    ds(int n) : front(n + 1), end(n + 1){
        pair_cnt = 0;
        route_cnt = 0;
        for(int i = 1; i <= n; i++){
            front[i] = i;
            end[i] = i;
        }
    }

    pair<int, int> find(int i){
        int f = find_front(i);
        int e = find_end(i);
        return make_pair(f, e);
    }

    void merge(int i, int j){

        auto[fi, ei] = find(i);
        auto[fj, ej] = find(j);
        if(fi < fj){
            front[fj] = fi;
        }
        else if(fi > fj){
            front[fi] = fj;
        }

        if(ei > ej){
            end[ej] = ei;
        }
        else if(fi < fj){
            end[ei] = ej;
        }
        pair_cnt -=get_pair(fi, ei) + get_pair(fj, ej);
        route_cnt -= get_route(fi, ei) + get_route(fj, ej);
        pair_cnt += get_pair(fi, ej);
        route_cnt += get_route(fi, ej);

    }

    pair<ll, ll> get_stat(){
        return make_pair(pair_cnt, route_cnt);
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ds d(n);

    for(int i = 1; i < n; i++){
        int tmp;
        cin >> tmp;
        d.merge(tmp, tmp + 1);
        auto [p, r] = d.get_stat();
        cout << p << " " << r << "\n";
    }
}
