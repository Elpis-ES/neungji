#include <bits/stdc++.h>

using namespace std;

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
    int price[10001];

    int n, m, k, i;
    scanf("%d %d %d", &n, &m, &k);
    dset d = dset(n+1);

    for(i=1; i<n+1; i++){
        scanf("%d", &price[i]);
    }

    int p, q;
    for(i=0; i<m; i++){
        scanf("%d %d", &p, &q);
        if(price[p] < price[q]){
            d.merge(q, p);
        }
        else{
            d.merge(p, q);
        }
    }
    int prev=-1;
    int money=0;
    for(i=1; i<n+1; i++){
        if(d.find(i)!=prev){
            printf("%d %d\n", d.find(i), prev);
            prev=d.find(i);
            money+=price[prev];
        }
    }
    if(money < k){
        printf("Oh no\n");
    }
    else{
        printf("%d\n", money);
    }

}
