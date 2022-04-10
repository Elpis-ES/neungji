#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if(n == 1){
        cout << "1\n";
        return 0;
    }
    vector<int> v;
    for(int i = 0 ; i < n; i++){
        int tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }

    vector<int> fighters;
    for(int i = 0; i < n; i++){
        int cur_pow = v[i];
        int prev = 0;
        if (i - 1 >= 0){
            if(cur_pow > v[i - 1]){
                cur_pow += i - prev;
                prev = i;
            }
            else{
                continue;
            }
            while(true){
                int nxt = (lower_bound(v.begin(), v.end(), cur_pow) - v.begin()) - 1;
                if(cur_pow > v[nxt]){
                    if(nxt == n-1){
                        fighters.emplace_back(i + 1);
                        break;
                    }
                    else{
                        if(nxt - prev == 0){
                            break;
                        }
                        cur_pow += (nxt - prev);
                        prev = nxt;
                    }
                }
                else{
                    break;
                }
            }

        }
        else{
            continue;
        }
    }
    if(fighters.size() == 0){
        fighters.emplace_back(-1);
    }
    for(auto a : fighters){
        cout << a << " ";
    }
    cout << "\n";
    return 0;
}
