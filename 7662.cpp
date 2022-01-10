#include <bits/stdc++.h>

using namespace std;


class dpqueue{
    private:
        multiset<int> q;
    public:
        void init(void){
            q.clear();
        }
        void insert(int n){
            q.insert(n);
        }
        int get_min(void){
            return *(q.begin());
        }
        int get_max(void){
            auto it = q.end();
            it--;
            return *it;
        }
        void erase(int n){
            auto it = q.find(n);
            if(it != q.end()){
                q.erase(it);
            }
        }
        int size(void){
            return q.size();
        }
};



int main(void){
    int t, i, j, n, k;
    char c;
    dpqueue q;
    scanf(" %d", &t);
    for(j = 0; j < t; j++){
        q.init();
        scanf(" %d", &k);
        for(int cmd = 0; cmd < k; cmd++){
            scanf(" %c %d", &c, &n);
            switch(c){
                case 'I':
                    q.insert(n);
                    break;
                case 'D':
                    if(q.size() != 0){
                        if(n == -1){
                            q.erase(q.get_min());
                        }
                        else{
                            q.erase(q.get_max());
                        }
                    }
                    break;
            }
        }
        if(q.size() == 0){
            printf("EMPTY\n");
        }
        else{
            printf("%d %d\n", q.get_max(), q.get_min());
        }
    }
}
