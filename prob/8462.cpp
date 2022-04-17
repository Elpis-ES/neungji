#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<int> v;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }

    vector<int> cnt (1000001);

    int s_prev, e_prev;
    s_prev = 0;
    e_prev = 0;
    int res = v[0];

    vector<tuple<int, int, int>> queries;

    for(int i = 0; i < t; i++){
        int s, e;
        cin >> s >> e;
        s--;
        e--;
        queries.emplace_back(s, e, i);
    }

    vector<int> rr(t);

    int chunk_size = sqrt(1000001) + 1;

    sort(queries.begin(), queries.end(), [&](auto &i, auto &j){
                int i_chunk = get<0>(i) / chunk_size;
                int j_chunk = get<0>(j) / chunk_size;
                if(i_chunk != j_chunk){
                    return i_chunk < j_chunk;
                }
                else{
                    return get<1>(i) < get<1>(j);
                }
            });

    for(auto[s, e, idx] : queries){

        if(e > e_prev){
            for(int i = e_prev + 1; i <= e; i++){
                cnt[v[i]]++;
                res += (2 * cnt[v[i]] - 1) * v[i];
            }
        }
        else if (e < e_prev){
            for(int i = e_prev; i > e; i--){
                res -= (2 * cnt[v[i]] - 1) * v[i];
                cnt[v[i]]--;
            }
        }

        if(s < s_prev){
            for(int i = s; i < s_prev; i++){
                cnt[v[i]]++;
                res += (2 * cnt[v[i]] - 1) * v[i];
            }
        }
        else if (s > s_prev){
            for(int i = s_prev; i < s; i++){
                res -= (2 * cnt[v[i]] - 1) * v[i];
                cnt[v[i]]--;
            }
        }
        rr[idx] = res;

        s_prev = s;
        e_prev = e;
    }
    for(auto i : rr){
        cout << i << "\n";
    }
}
