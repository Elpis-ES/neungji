#include <bits/stdc++.h>

using namespace std;

int main(void){
    int N, i, n;
    vector<int> v1;
    vector<int> v2;
    int idx, spc;

    scanf(" %d", &N);
    for(i = 0; i < N; i++){
        scanf( "%d", &n);
        v1.push_back(n);
        v2.push_back(n);
    }


    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for(i = 0; i < N; i++){
        auto target = lower_bound(v2.begin(), v2.end(), v1[i]);
        printf("%ld ", distance(v2.begin(), target));
    }
    printf("\n");



}
