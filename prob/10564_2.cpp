#include <bits/stdc++.h>

using namespace std;

int dp_arr[5002][21];
bool pushed[5002];

int main(){
    int tc, n, m;
    scanf(" %d", &tc);
    vector<int> v;
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i = 0; i < tc; i++){
        memset(dp_arr, -1, sizeof(int) * 5002 * 21);
        memset(pushed, 0, sizeof(bool)*5002);
        q = priority_queue<int, vector<int>, greater<int> >();
        v = vector<int>();
        int a;
        scanf(" %d %d", &n, &m);
        for(int j = 0; j < m; j++){
            scanf(" %d", &a);
            dp_arr[a][a] = a;
            dp_arr[a][0] = a;
            v.push_back(a);
            q.push(a);
            pushed[a] = true;
        }
        sort(v.begin(), v.end());
        int cur_target;
        int nxt_pushup;
        int cur_i;
        while(!q.empty()){
            cur_i = q.top();
            q.pop();
            for(int j = 0; j < m; j++){
                cur_target = v[j];
                if(dp_arr[cur_i][cur_target] == -1){
                    continue;
                }
                else{
                    if(dp_arr[cur_i][cur_target] > dp_arr[cur_i][0]){
                        dp_arr[cur_i][0] = dp_arr[cur_i][cur_target];
                    }
                    for(int k = 0; k < m; k++){
                        nxt_pushup = dp_arr[cur_i][cur_target] + v[k] + cur_i;
                        if(nxt_pushup <= n){
                            if(dp_arr[nxt_pushup][v[k]] < dp_arr[cur_i][cur_target] + v[k]){
                                dp_arr[nxt_pushup][v[k]] = dp_arr[cur_i][cur_target] + v[k];
                            }
                            if(!pushed[nxt_pushup]){
                                pushed[nxt_pushup] = true;
                                q.push(nxt_pushup);
                            }
                        }
                    }
                }
            }
        }

        printf("%d\n", dp_arr[n][0]);
    }
}
