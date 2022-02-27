#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, na, nb;
    cin >> t >> na;
    vector<int> a;
    vector<int> b;
    unordered_map<int,ll > ma;
    unordered_map<int, ll> mb;

    int psum = 0;
    int tmp;
    int target;
    for(int i = 0; i < na; i++){
        cin >> tmp;
        psum += tmp;
        a.emplace_back(psum);
        auto e = ma.find(psum);
        if(e != ma.end()){
            e->second++;
        }
        else{
            ma.insert({psum, 1});
        }
        for(int j = 1; j <= i; j++){
            target = psum - a[j - 1];
            auto elem = ma.find(target);
            if(elem != ma.end()){
                elem->second++;
            }
            else{
                ma.insert({target, 1});
            }
        }
    }

    cin >> nb;
    psum = 0;
    for(int i = 0; i < nb; i++){
        cin >> tmp;
        psum += tmp;
        b.emplace_back(psum);
        auto e = mb.find(psum);
        if(e != mb.end()){
            e->second++;
        }
        else{
            mb.insert({psum, 1});
        }
        for(int j = 1; j <= i; j++){
            target = psum - b[j - 1];
            auto elem = mb.find(target);
            if(elem != mb.end()){
                elem->second++;
            }
            else{
                mb.insert({target, 1});
            }
        }
    }

    ll ret = 0;
    for(const auto &[cur_num, cur_cnt] : ma){
        auto e = mb.find(t - cur_num);
        if(e != mb.end()){
            ret += cur_cnt * e->second;
        }
    }
    cout << ret << "\n";
}
