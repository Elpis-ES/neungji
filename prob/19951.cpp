#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int psum_arr[100001];

int main(){
    int n, m, n_i, m_i, h_i;
    scanf(" %d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf(" %d", &arr[i]);
    }
    for(int i = 0; i < m; i++){
        scanf(" %d %d %d", &n_i, &m_i, &h_i);
        psum_arr[n_i] += h_i;
        if(m_i < n){
            psum_arr[m_i+1] -= h_i;
        }
    }
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        tmp += psum_arr[i];
        printf("%d ", tmp + arr[i]);
    }
    printf("\n");
    return 0;
}
