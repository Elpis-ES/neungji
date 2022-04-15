#include<bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string orig, target;
    cin >> orig >> target;

    int cpy_cnt = 0;
    int target_idx = 0;

    while(target_idx < target.length()){
        int max_len = 0;
        for(int i = 0; i < orig.length(); i++){
            if(orig[i] == target[target_idx]){
                int cur_len = 0;
                for(int j = 0; j + i < orig.length(); j++){
                    if(orig[i + j] != target[target_idx + j]){
                        break;
                    }
                    cur_len++;
                }
                max_len = max(max_len, cur_len);
            }
        }
        cpy_cnt++;
        target_idx += max_len;
    }
    cout << cpy_cnt << "\n";
}
