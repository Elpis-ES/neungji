#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, f, t;
    vector<pair<int, int> > v;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
        scanf(" %d %d", &f, &t);
        v.push_back(make_pair(t, f));
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int cur_end = -1;
    for(auto it = v.begin(); it!= v.end(); it++){
        if(cur_end <= it->second){
            cur_end = it->first;
            cnt++;
        }

    }
    printf("%d\n", cnt);
}
