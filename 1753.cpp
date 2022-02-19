#include <bits/stdc++.h>

using namespace std;

list<pair<int, int> > li[20001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<pair<int, int> > pq;

    int v, e, k;
    cin >> v >> e >> k;

    int f, t, l;
    for(int i = 0; i < e; i++){
        cin >> f >> t >> l;
        li[f].push_back(make_pair(t, l));
    }
    vector<int> d(v+1, INT_MAX);
    d[k] = 0;
    pq.push(make_pair(0, k));

    while(!pq.empty()){
        int cur_dist = -1 * pq.top().first;
        int cur_pt = pq.top().second;
        pq.pop();
        if(d[cur_pt] < cur_dist){
            continue;
        }
        for(auto it = li[cur_pt].begin(); it != li[cur_pt].end(); it++){
            if(d[it->first] > cur_dist + it->second){
                d[it->first] = cur_dist + it->second;
                pq.push(make_pair(d[it->first] * -1, it->first));
            }
        }
    }

    for(int i = 1; i <= v; i++){
        if(d[i] == INT_MAX){
            cout << "INF\n";
        }
        else{
            cout << d[i] << "\n";
        }
    }

}
