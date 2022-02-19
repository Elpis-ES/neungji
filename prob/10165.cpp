#include <bits/stdc++.h>

using namespace std;

int main(){
    map<int, pair<int, int> > arr;

    int n, m;
    int f, t, l;
    scanf(" %d", &n);
    scanf(" %d", &m);
    for(uint i = 0; i < m; i++){
        scanf(" %d %d", &f, &t);
        if(t < f){
            t += n;
        }
        l = t - f;
        auto it = arr.find(f);
        if(it == arr.end()){
            arr.emplace(f, make_pair(l, i));
        }
        else{
            if(it->second.first < l){
                it->second.first = l;
                it->second.second = i;
            }
        }
    }

    int cur_start = arr.begin()->first;
    int cur_end = cur_start + arr.begin()->second.first;

    bool overflowed = false;

    vector<int> v;
    v.push_back(arr.begin()->second.second);

    for(auto it = arr.begin(); it != arr.end(); it++){
        if(!overflowed && ((it->first + it->second.first) >= n)){
            overflowed = true;
        }

        if(it->first >= cur_start && (it->first + it->second.first) <= cur_end){
        }
        else{
            v.push_back(it->second.second);
            cur_start = it->first;
            cur_end = cur_start + it->second.first;
        }
    }

    if(overflowed){
        cur_end = cur_end % n;
        for(auto it = arr.begin(); it != arr.end(); it++){
            if(it->first >= n){
                break;
            }
            if(it->first + it->second.first <= cur_end){
                auto target = find(v.begin(), v.end(), it->second.second);
                if(target != v.end()){
                    v.erase(target);
                }
            }
        }
    }

    sort(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); it++){
        printf("%d ", *it + 1);
    }
    printf("\n");

}
