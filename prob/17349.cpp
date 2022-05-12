#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

int verify(int liar){
    vector<int> cur(10, -1);

    if(v[liar].first == 0){
        cur = vector<int> (10, 0);
        cur[v[liar].second] = 1;
    }
    else{
        cur[v[liar].second] = 0;
    }

    for(int i = 1; i <= 9; i++){
        if(i == liar){
            continue;
        }

        int stat = v[i].first;
        int target = v[i].second;

        if(stat == 0){
            if(cur[target] == -1){
                cur[target] = 0;
            }
            else if(cur[target] != 0){
                    return -1;
            }
        }
        else{
            for(int j = 1; j <= 9; j++){
                if(j == target){
                    if(cur[j] == -1){
                        cur[j] = 1;
                    }
                    else if(cur[j] != 1){
                            return -1;
                    }
                }
                else{
                    if(cur[j] == -1){
                        cur[j] = 0;
                    }
                    else if(cur[j] != 0){
                            return -1;
                    }
                }
            }
        }
    }
    vector<int> target;
    vector<int> unknown;
    for(int i = 1; i <= 9; i++){
        if(cur[i] == 1){
            target.emplace_back(i);
        }
        else if(cur[i] == -1){
            unknown.emplace_back(i);
        }
    }
    int ret = -2;

    if(target.size() == 1){
        ret = target[0];
    }
    else if(target.size() == 0 && unknown.size() == 1){
        ret = unknown[0];
    }
    return ret;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    v.emplace_back(-1, -1);

    for(int i = 0; i < 9; i++){
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    int cur = -1;
    for(int i = 1; i <= 9; i++){
        int tmp = verify(i);
        if(tmp == -2){
            cur = -1;
            break;
        }
        else if (tmp == -1){
            continue;
        }
        else{
            if(cur == -1){
                cur = tmp;
            }
            else if(cur != tmp){
                cur = -1;
                break;
            }
        }
    }
    cout << cur << "\n";
}
