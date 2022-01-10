#include <bits/stdc++.h>
using namespace std;

int ss[100001];
int arr[100001];

void s(int* a, int n){
    int i;
    int t = -1;
    int tmp;
    for(i = 0; i<n; i++){
        if(ss[i] == t){
            a[ss[i]] = tmp;
        }
        else{
            t = i;
            tmp = a[i];
            a[ss[i]] = a[i];
        }
    }
}

int main(void){
    int N, M, Q;
    int i;
    int m;
    scanf(" %d %d %d", &N, &M, &Q);
    for(i = 0; i < M; i++){
        scanf(" %d", &m);
        ss[i] = m - 1;
    }
    for(i = 0; i < 100000; i++){
        arr[i] = i+1;
    }
    for(i = 0; i < N-M; i++ ){
        s(&arr[i], M);
    }
    for(i = 0; i< N; i++){
        printf("%d\n", arr[i]);
    }

}

