#include <bits/stdc++.h>

using namespace std;

int dp[5002][100];
bool pushed[5002][100];
int main(){
    int tc, n, m;
    vector<int> v;
    queue<int> q;
    int cur;
    int cur_num;
    int round;
    scanf(" %d", &tc);
    for(int i = 0; i < tc; i++){;
        memset(dp, -1, sizeof(int)*5002*100);
        memset(pushed, 0, sizeof(bool)*5002*100);
        v = vector<int>();
        q = queue<int> ();
        scanf(" %d %d", &n, &m);
        for(int j = 0; j < m; j++){
            scanf(" %d", &cur);
            v.push_back(cur);
        }
        q.push(n);
        q.push(-1);
        pushed[n][0] = true;
        round = 100;
        for(int i = 1; i < round; i++){
            while(!q.empty()){
                cur_num = q.front();
                q.pop();
                if(cur_num == -1){
                    q.push(-1);
                    break;
                }
                for(int j = 0; j < m; j++){
                    if(cur_num - i*v[j] >=0){
                        if(!pushed[cur_num - i*v[j]][i]){
                            q.push(cur_num - i*v[j]);
                            pushed[cur_num - i*v[j]][i] = true;
                        }
                        if(dp[cur_num - i*v[j]][i] == -1){
                            dp[cur_num - i*v[j]][i] = v[j] + dp[cur_num][i-1];
                        }
                        else{
                            dp[cur_num - i*v[j]][i] = max(v[j] + dp[cur_num][i-1], dp[cur_num - i*v[j]][i]);
                        }
                    }
                }
            }
        }
        int max = -1;
        for(int j = 0; j < 100; j++){
            if(dp[0][j] > max){
                max = dp[0][j];
            }
        }
        printf("%d\n", max == -1? max : max + 1);

    }
}
