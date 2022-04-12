#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<bool> b(n + 1, true);
    vector<int> prime;
    for(int i = 2; i * i <= n; i++){
        if(b[i]){
            for(int j = i * i; j <= n; j+= i){
                b[j] = false;
            }
        }
    }
    int sum = 0;
    prime.emplace_back(sum);
    for(int i = 2; i <= n; i++){
        if(b[i]){
            sum += i;
            prime.emplace_back(sum);
        }
    }
    int start = 0;
    int cnt = 0;
    for(int end = 0; end < prime.size(); end++){
        int cur = prime[end] - prime[start];
        if(cur == n){
            cnt++;
            start++;
        }
        else if(cur > n){
            while(end != start && prime[end] - prime[start] > n){
                start++;
            }
            if(prime[end] - prime[start] == n){
                cnt++;
            }
        }
    }
    cout << cnt << "\n";

}
