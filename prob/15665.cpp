#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> v;
int arr[7];

void construct(int digit, int i){
    arr[digit] = v[i];
    if(digit == m-1){
        for(int j = 0; j < m; j++){
            printf("%d ", arr[j]);
        }
        printf("\n");
        return;
    }
    else{
        for(int j = 0; j < n; j++){
            construct(digit + 1, j);
        }
        return;
    }
}

int main(){
    scanf(" %d %d", &n, &m);
    int num;
    for(int i = 0; i < n; i++){
        scanf(" %d", &num);
        v.push_back(num);
    }
    int prev = -1;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();
    for(int i = 0; i < n; i++){
        construct(0, i);
    }
}
