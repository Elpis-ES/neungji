#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int, int> > v;
    int n, f, t;
    int max_mosquito = 0;
    int max_time_start = -1;
    int max_time_end = -1;
    int cur_mosquito = 0;
    int prev_time = -1;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
        scanf(" %d %d", &f, &t);
        v.push_back(make_pair(f, 1));
        v.push_back(make_pair(t, -1));
    }
    sort(v.begin(), v.end());
    int prev_t = -1;
    vector<int> time;
    vector<int> psum;
    for(auto it = v.begin(); it != v.end(); it++){
        if(prev_t != it->first){
            prev_t = it->first;
            time.push_back(it->first);
            psum.push_back(it->second);
        }
        else{
            psum[psum.size() - 1] += it->second;
        }
    }
    bool max_entered = false;
    for(int i = 0; i < time.size(); i++){
        if(psum[i] != 0){
            cur_mosquito += psum[i];
            if(cur_mosquito > max_mosquito){
                max_entered = true;
                max_mosquito = cur_mosquito;
                max_time_start = time[i];
            }
            else if(max_entered && cur_mosquito < max_mosquito){
                max_time_end = time[i];
                max_entered = false;
            }
        }
    }
    printf("%d\n%d %d\n", max_mosquito, max_time_start, max_time_end);
}
