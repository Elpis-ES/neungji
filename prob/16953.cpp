#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    queue<pair<int, int>> q;
    q.emplace(b, 1);

    int op = INT_MAX;
    while(!q.empty()){
        auto [cur_num, cur_op] = q.front();
        q.pop();

        if(cur_num < a)
            continue;
        else if(cur_num == a){
            op = min(op, cur_op);
        }
        else{
            if(cur_num % 10 == 1){
                q.emplace((cur_num - 1) / 10, cur_op + 1);
            }
            if(cur_num % 2 == 0){
                q.emplace(cur_num >> 1, cur_op + 1);
            }
        }
    }

    if(op == INT_MAX){
        op = -1;
    }
    cout << op << "\n";
}
