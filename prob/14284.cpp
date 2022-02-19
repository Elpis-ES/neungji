#include <bits/stdc++.h>

using namespace std;

int main(){
    list<pair<int, int> > g[5001];
    int dist[5001];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    int v, e;
    int f, t, d;
    scanf(" %d %d", &v, &e);
    fill(dist, dist+v+1, INT_MAX);
    for(int i = 0; i < e; i++){
        scanf(" %d %d %d", &f, &t, &d);
        g[f].push_back(make_pair(t, d));
        g[t].push_back(make_pair(f, d));
    }
    scanf(" %d %d", &f, &t);
    pq.push(make_pair(0, f));
    dist[f] = 0;
    int cur_v;
    int cur_l;
    while(!pq.empty()){
        cur_v = pq.top().second;
        cur_l = pq.top().first;
        if(cur_v == t){
            break;
        }
        pq.pop();
        for(auto it = g[cur_v].begin(); it!=g[cur_v].end(); it++){
            if(cur_l + it->second < dist[it->first]){
                dist[it->first] = cur_l + it->second;
                pq.push(make_pair(dist[it->first], it->first));
            }
        }
    }
    printf("%d\n", dist[t]);
}
