#include <bits/stdc++.h>

using namespace std;

int main(){
    int d, v;
    int penalty = 0;
    vector<int> vec;
    for(int i = 0; i < 11; i++){
        scanf(" %d %d", &d, &v);
        vec.push_back(d);
        penalty += v* 20;

    }
    sort(vec.begin(), vec.end());

    int cur_time = 0;

    for(auto it = vec.begin(); it != vec.end(); it++){
        cur_time += *it;
        penalty += cur_time;
    }

    printf("%d\n", penalty);

}
