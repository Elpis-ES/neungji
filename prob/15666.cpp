#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> v;
int arr[8];

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
        for(int j = i; j < n; j++){
            construct(digit + 1, j);
        }
        return;
    }
}

int main(){
    scanf(" %d %d", &n, &m);
    vector<int> tmp;
    int num;
    for(int i = 0; i < n; i++){
        scanf(" %d", &num);
        tmp.push_back(num);
    }
    int prev = -1;
    sort(tmp.begin(), tmp.end());
    for(auto it = tmp.begin(); it !=tmp.end(); it++){
        if(*it == prev){
            continue;
        }
        else{
            prev = *it;
            v.push_back(*it);
        }
    }
    n = v.size();
    for(int i = 0; i < n; i++){
        construct(0, i);
    }


}
