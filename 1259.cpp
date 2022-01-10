#include <bits/stdc++.h>

using namespace std;

void solve(char* a){
    int len = strlen(a);
    int i;
    for(i = 0; i < len / 2; i++){
      if(a[i] != a[len-1-i]){
          printf("no\n");
          return;
      }

    }
    printf("yes\n");
}

int main(){
    char a[6];
    while(true){
        scanf(" %s", a);
        if(strcmp(a, "0") == 0)
            break;
        solve(a);
    }
    return 0;
}
