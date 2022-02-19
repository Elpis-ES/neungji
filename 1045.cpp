#include <bits/stdc++.h>

using namespace std;

vector<int> map_arr[51];
int cnt[51];
bool visited[51][51];
int union_arr[51];

int find(int i){
    if(union_arr[i] == -1){
        union_arr[i] = i;
    }
    return union_arr[i];
}

void do_union(int i, int j, int n){
    int a = find(i);
    int b = find(j);

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
    for(int i = 0; i < n; i++){
        if(union_arr[i] == from){
            union_arr[i] = to;
        }
    }
}

int mst(int i, int n){
    int ret = 0;
    visited[i][i] = true;
    find(0);
    for(int i = 0; i < n; i++){
        for(auto it = map_arr[i].begin(); it != map_arr[i].end(); it++){
            if(*it > i && find(i) != find(*it)){
                do_union(i, *it, n);
                visited[i][*it] = true;
                visited[*it][i] = true;
                visited[*it][*it] = true;
                cnt[i]++;
                cnt[*it]++;
                ret++;
                if(ret == n-1){
                    break;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(union_arr[i] != 0){
            return -1;
        }
    }
    return ret;
}

int add_to_graph(int i, int n, int remainder){
    int ret = 0;
    for(auto it = map_arr[i].begin(); it != map_arr[i].end(); it++){
        if (!visited[i][*it] && i < *it){
            visited[i][*it] = true;
            visited[*it][i] = true;
            ret++;
            cnt[i]++;
            cnt[*it]++;
            if(ret == remainder){
                return remainder;
            }
        }
    }
    return ret;
}

int main(){
    int n, m;
    char c;
    scanf(" %d %d\n", &n, &m);
    memset(cnt, 0, sizeof(int)*51);
    memset(visited, 0, sizeof(bool)*51*51);
    vector<int> v;
    int total_len = 0;
    bool is_connected = true;
    int len;
    for(int i = 0; i < n; i++){
        v = vector<int> ();
        for(int j = 0; j < n; j++){
            scanf(" %c", &c);
            if (c == 'Y'){
                v.push_back(j);
                if(i < j){
                    total_len++;
                }
            }
        }
        map_arr[i] = v;
    }

    if(total_len < m){
        printf("-1\n");
        return 0;
    }

    memset(union_arr, -1, sizeof(int)* 51);

    int cur = mst(0, n);
    if(cur == -1){
        printf("-1\n");
        return 0;
    }

    int remainder = m - cur;
    if(cur != n-1 || remainder < 0){
        printf("-1\n");
        return 0;
    }

    if(remainder == 0){
        for(int j = 0; j < n; j++){
            printf("%d ", cnt[j]);
        }
        printf("\n");
        return 0;
    }

    for(int i = 1; i < n; i++){
        if(remainder == 0){
            for(int j = 0; j < n; j++){
                printf("%d ", cnt[j]);
            }
            printf("\n");
            return 0;
        }
        remainder = remainder - add_to_graph(i, n, remainder);
        if(remainder < 0){
            printf("-1\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
