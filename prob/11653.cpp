#include <bits/stdc++.h>

int main(){
    int n;
    scanf(" %d", &n);
    bool found;
    while(n != 1){
        found = false;
        for(int i = 2; i*i <=n; i++){
            if(n % i == 0){
                printf("%d\n", i);
                n = n/i;
                found = true;
                break;
            }
        }
        if(!found){
            break;
        }
    }
    if(n != 1){
        printf("%d\n", n);
    }
}

