#include <bits/stdc++.h>

using namespace std;

char tree[26][2];

void preorder(char i){
    if(i == -1){
        return;
    }
    printf("%c", 'A' + i);
    preorder(tree[i][0]);
    preorder(tree[i][1]);
}

void inorder(char i){
    if(i == -1){
        return;
    }
    inorder(tree[i][0]);
    printf("%c", 'A'+i);
    inorder(tree[i][1]);
}

void postorder(char i){
    if(i == -1){
        return;
    }
    postorder(tree[i][0]);
    postorder(tree[i][1]);
    printf("%c", 'A'+i);
}

int main(){
    int n;
    scanf(" %d", &n);
    char c, l, r;
    for(int i = 0; i < n; i++){
        scanf(" %c %c %c", &c, &l, &r);
        tree[c - 'A'][0] = (l == '.' ? -1 : l - 'A');
        tree[c - 'A'][1] = (r == '.' ? -1 : r - 'A');
    }
    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    printf("\n");
}

