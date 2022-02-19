#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int> > > w;
int powered[1001];
int n;
int cnt;

int find(int i){
    if(powered[i] == -1){
        powered[i] = i;
    }
    return powered[i];
}

void do_union(int p, int q){
    int a = find(p);
    int b = find(q);
    if(a == b){
        return;
    }
    int from, to;
    if(a == 0 && b!= 0){
        from = b;
        to = 0;
    }
    else if(a != 0 && b == 0){
        from = a;
        to = 0;
    }
    else{
        from = a;
        to = b;
    }
    for(int i = 1; i <= n; i++){
        if(powered[i] == from){
            powered[i] = to;
            if(to == 0){
                cnt++;
            }
        }
    }

}

int main(){
    int m, k, num;
    int f, t, c;
    memset(powered, -1, sizeof(int)*1001);
    scanf(" %d %d %d", &n, &m, &k);
    powered[0] = 0;
    cnt = k;
    for(int i = 0; i < k; i++){
        scanf(" %d", &num);
        powered[num] = 0;
    }
    for(int i = 0; i < m; i++){
        scanf(" %d %d %d", &f, &t, &c);
        w.push_back(make_pair(c, make_pair(f, t)));
    }
    sort(w.begin(), w.end());
    int weight = 0;

    for(auto it = w.begin(); it != w.end(); it++){
        if(find(it->second.first) != find(it->second.second)){
            do_union(it->second.first, it->second.second);
            weight += it->first;

        }
        if(cnt == n){
            break;
        }
    }


    printf("%d\n", weight);
}
