#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, b, s, r;
vector<ll> dist;
vector<ll> reverse_dist;
vector<ll> weight;
vector<ll> psum;

vector<ll> dp_prev;
vector<ll> dp_cur;

ll cost(int i, int j){
    return (psum[j + 1] - psum[i]) * (j - i);
}

void compute(int l, int r, int optl, int optr){
    if(l > r)
        return;

    int mid = (l + r) >> 1;
    pair<ll, int> best = {LLONG_MAX, -1};

    for(int k = optl; k <= min(mid, optr); k++){
        best = min(best, {(k ? dp_prev[k - 1] : 0) + cost(k, mid), k});
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> b >> s >> r;

    vector<vector<pair<int, ll>>> m (n, vector<pair<int, ll>>());
    vector<vector<pair<int, ll>>> m_reverse (n, vector<pair<int, ll>>());
    dist = vector<ll> (n, LLONG_MAX);
    reverse_dist = vector<ll> (n, LLONG_MAX);
    dist[b] = 0;
    reverse_dist[b] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, b);

    int from, to;
    ll ddd;

    for(int i = 0; i < r; i++){
        cin >> from >> to >> ddd;
        m[from - 1].emplace_back(to - 1, ddd);
        m_reverse[to - 1].emplace_back(from - 1, ddd);
    }

    while(!pq.empty()){
        auto [cur_dist, cur_pos] = pq.top();
        cur_dist = -cur_dist;
        pq.pop();

        if(cur_dist > dist[cur_pos])
            continue;
        for(const auto &[nxt_pos, nxt_dist] : m[cur_pos]){
            if(dist[nxt_pos] > nxt_dist + cur_dist){
                dist[nxt_pos] = nxt_dist + cur_dist;
                pq.emplace(-dist[nxt_pos], nxt_pos);
            }
        }
    }

    pq.emplace(0, b);
    while(!pq.empty()){
        auto [cur_dist, cur_pos] = pq.top();
        cur_dist = -cur_dist;
        pq.pop();

        if(cur_dist > reverse_dist[cur_pos])
            continue;
        for(const auto &[nxt_pos, nxt_dist] : m_reverse[cur_pos]){
            if(reverse_dist[nxt_pos] > nxt_dist + cur_dist){
                reverse_dist[nxt_pos] = nxt_dist + cur_dist;
                pq.emplace(-reverse_dist[nxt_pos], nxt_pos);
            }
        }
    }

    for(int i = 0; i < b; i++){
        weight.emplace_back(dist[i] + reverse_dist[i]);
    }

    sort(weight.begin(), weight.end());

    ll ps = 0;
    psum.emplace_back(0);
    for(int i = 0; i < b; i++){
        ps += weight[i];
        psum.emplace_back(ps);
    }

    dp_prev = vector<ll> (b);
    dp_cur = vector<ll> (b);

    for(int i = 0; i < b; i++){
        dp_prev[i] = cost(0, i);
    }

    for(int i = 1; i < s; i++){
        compute(0, b - 1, 0, b - 1);
        dp_prev = dp_cur;
    }

    cout << dp_prev[b - 1] << "\n";
}
