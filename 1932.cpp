#include <bits/stdc++.h>

using namespace std;

int dp_arr[500][500];

int main(){
    int n;
    scanf(" %d", &n);

    int num;
    int max_num = -1;
    int left;
    int right;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <=i; j++){
            scanf(" %d", &num);
            if(i == 0){
                left = 0;
                right = 0;
            }
            else{
                left = j-1 >= 0 ? dp_arr[i-1][j-1] : 0;
                right = j <= i-1 ? dp_arr[i-1][j] : 0;
            }
            dp_arr[i][j] = max(dp_arr[i-1][j-1], dp_arr[i-1][j]) + num;
            if(i == n-1 && max_num < dp_arr[i][j]){
                max_num = dp_arr[i][j];
            }
        }
    }

    printf("%d\n", max_num);
}
