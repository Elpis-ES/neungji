#include <bits/stdc++.h>

using namespace std;

struct edge{
    int f, t, w;
    bool operator < (const edge& rhs) const {
        return w < rhs.w;
    }
};

struct dset{

    vector<int> g;
    dset(int N): g(N){
        for(int i=0; i<N; i++){
            g[i]=i;
        }
    }

    int find(int n){
        if(n==g[n]){
            return n;
        }
        return g[n]=find(g[n]);
    }

    bool merge(int p, int q){
        p=find(p);
        q=find(q);
        if(p!=q){
            g[p]=q;
            return true;
        }
        return false;
    }
};

int main(void){
    int v, e, i;
    scanf("%d %d", &v, &e);
    dset d = dset(v+1);
    vector<edge> ev;
    int weight=0;

    for(i=0; i<e; i++){
        ev.push_back(edge());
        scanf("%d %d %d", &(ev[i].f), &(ev[i].t), &(ev[i].w));
    }
    sort(ev.begin(), ev.end());

    for(i=0; i<e; i++){
        if(d.merge(ev[i].f, ev[i].t)){
            weight+=ev[i].w;
        }
    }
    printf("%d\n", weight);
}
