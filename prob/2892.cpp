#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, num;
    scanf(" %d" , &n);
    for(int i = 0; i < n; i++){
        scanf(" %x", &num);
        if(num >= 16 && num <= 31){
            printf(".");
        }
        else{
            printf("-");
        }
    }
    printf("\n");
}
