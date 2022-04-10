#include <bits/stdc++.h>

using namespace std;

int n;
vector<bool> from;
vector<bool> to;

int greedy(bool flip){
    vector<bool> tmp = from;
    int cnt = 0;

    if(flip){
        tmp[0] = !tmp[0];
        if(n != 1){
            tmp[1] = !tmp[1];
        }
        cnt++;
    }

    for(int idx = 1; idx < n; idx++){
        if(tmp[idx - 1] != to[idx - 1]){
            tmp[idx - 1] = !tmp[idx -1];
            tmp[idx] = !tmp[idx];
            if(idx + 1 < n){
                tmp[idx + 1] = !tmp[idx + 1];
            }
            cnt++;
        }
    }
    if(tmp[n - 1] != to[n - 1]){
        cnt = -1;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    char tmp;
    from = vector<bool> (n);
    to = vector<bool> (n);
    for(int i = 0; i < n; i++){
        cin >> tmp;
        from[i] = tmp == '0' ? false : true;
    }
    for(int i = 0; i < n; i++){
        cin >> tmp;
        to[i] = tmp == '0' ? false : true;
    }

    int a = greedy(false);
    int b = greedy(true);
    int ret;
    if(a != -1 && b != -1){
        ret = min(a, b);
    }
    else if(a == -1 && b == -1){
        ret = -1;
    }
    else{
        ret = max(a, b);
    }
    cout << ret << "\n";
}
