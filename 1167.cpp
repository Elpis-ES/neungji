#include <bits/stdc++.h>

using namespace std;

vector<pair <int, int> > v[100001];
bool b[100001];

pair <int, int> dfs_exec(int n){
    b[n] = true;
    int tmp;
    int max = 0;
    int target;
    pair<int, int> cur_max;
    pair<int, int> cur_dfs;
    bool expanded = false;
    for(int i = 0; i < v[n].size(); i++){
        target = v[n][i].first;
        if(b[target] == false){
            expanded = true;
            cur_dfs = dfs_exec(target);
            tmp = cur_dfs.second + v[n][i].second;
            if(tmp > max){
                max = tmp;
                cur_max = cur_dfs;
            }
        }
    }

    if(expanded){
        return make_pair(cur_max.first, max);
    }
    else{
        return make_pair(n, 0);
    }

}

pair <int, int> max_dfs(int n){
    memset(b, 0, sizeof(bool)* 100001);
    return dfs_exec(n);
}



int main(){
    int i, src, dst, len;
    scanf(" %d", &i);
    for(int n = 0; n < i; n++){
        scanf(" %d", &src);
        while(true){
            scanf(" %d", &dst);
            if(dst == -1){
                break;
            }
            scanf(" %d", &len);
            v[src].push_back(make_pair(dst, len));
        }
    }

    int res = -1;
    pair <int, int>  tmp;
    tmp = max_dfs(1);
    res = max_dfs(tmp.first).second;

    printf("%d\n", res);

    return 0;
}
