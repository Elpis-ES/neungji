#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> >v[10001];
bool visited[10001];
int n;
int max_node = 0;
int max_len = 0;

void dfs(int root, int cur_len){
    if(visited[root]){
        return;
    }
    visited[root] = true;
    if(cur_len > max_len){
        max_node = root;
        max_len = cur_len;
    }

    int idx;
    int len;
    for(auto it = v[root].begin(); it!= v[root].end(); it++){
        idx = it->first;
        len = it->second;
        if(!visited[idx]){
            dfs(idx, cur_len + len);
        }
    }
    return;
}

int main(void){
    int f, t, w;
    int i;
    scanf(" %d", &n);
    for(i = 0; i < n - 1; i++){
        scanf (" %d %d %d", &f, &t, &w);
        v[f].push_back(make_pair(t, w));
        v[t].push_back(make_pair(f, w));
    }
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    max_len = 0;
    dfs(max_node, 0);
    printf("%d\n", max_len);
    return 0;

}
