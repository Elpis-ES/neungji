#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> v;
bool checked[8];
int arr[8];

void make_arr(int digit, int i){
    checked[i] = true;
    arr[digit] = v[i];
    if(digit == m-1){
        for(int j = 0; j < m; j++){
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
    else{
        for(int j = 0; j < n; j++){
            if(!checked[j]){
                make_arr(digit + 1, j);
            }
        }
    }
    checked[i] = false;
}


int main(){
    scanf(" %d %d", &n, &m);
    int num;
    for(int i = 0; i < n; i++){
        scanf(" %d" , &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        make_arr(0, i);
    }
}
