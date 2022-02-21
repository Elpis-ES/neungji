#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, num;
    vector<int> v;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
        scanf(" %d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int ret = 0;
    int diff, target_min, target_max, val;
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            diff = v[j] - v[i];
            target_min = v[j] + diff;
            target_max = v[j] + diff * 2;
            val = (upper_bound(v.begin(), v.end(), target_max) - lower_bound(v.begin(), v.end(), target_min));
            ret += val;
        }
    }
    printf("%d\n", ret);
}
