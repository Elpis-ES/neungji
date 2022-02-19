#include <bits/stdc++.h>

using namespace std;

int a[10001];
int ptr = -1;

int main(void){
    int n;
    char q[6];
    int k;
    scanf(" %d\n", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", q);
        switch(q[0]){
            case 'p':
                if(q[1]=='u'){
                    scanf(" %d\n", &k);
                    ptr++;
                    a[ptr]=k;
                }
                else{
                    if(ptr == -1)
                        printf("-1\n");
                    else{
                        printf("%d\n", a[ptr]);
                        ptr--;
                    }
                }
                break;
            case 's':
                printf("%d\n", ptr+1);
                break;
            case 'e':
                if(ptr == -1)
                    printf("1\n");
                else
                    printf("0\n");
                break;
            case 't':
                if(ptr == -1)
                    printf("-1\n");
                else
                    printf("%d\n", a[ptr]);
                break;
        }
    }
}
