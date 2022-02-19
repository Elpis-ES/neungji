#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int dp_arr[1001][1001];

int dp(int s, int e){
    if(dp_arr[s][e] != -1){
        return dp_arr[s][e];
    }
    if(s == e){
        dp_arr[s][e] = 0;
        return 0;
    }
    if(e - s == 1){
        int val = arr[s] > arr[e] ? arr[s] - arr[e] : arr[e] - arr[s];
        dp_arr[s][e] = val;
        return val;
    }
    int vmax = -1;
    int vmin = 10001;
    for(int i = s; i <=e; i++){
        if(arr[i] > vmax){
            vmax = arr[i];
        }
        if(arr[i] < vmin){
            vmin = arr[i];
        }
    }
    int max = vmax - vmin;
    int cur_max;
    for(int i = s; i < e; i++){
        cur_max = dp(s, i) + dp(i+1, e);
        if(cur_max > max){
            max = cur_max;
        }
    }
    dp_arr[s][e] = max;
    return max;
}

int main(){
    int n;
    memset(dp_arr, -1, sizeof(int) * 1001 * 1001);
    scanf(" %d", &n);

    for(int i = 0; i < n; i++){
        scanf(" %d" , &arr[i]);
    }
    printf("%d\n", dp(0, n-1));

}
