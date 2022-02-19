#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int arr[100];
ull total;

void brute(int i, ull cnt, int n, int const_cnt, int vowel_cnt, int l_present){
    if(i == n && l_present){
        total += cnt;
    }
    if(arr[i] == -1){
        if(const_cnt != 2){
            if(l_present == false){
                brute(i+1, cnt, n, const_cnt + 1, 0, true);
                brute(i+1, cnt * 20, n, const_cnt + 1, 0, l_present);
            }
            else{
                brute(i+1, cnt * 21, n, const_cnt + 1, 0, l_present);
            }
        }
        if(vowel_cnt != 2){
            brute(i+1, cnt * 5, n, 0, vowel_cnt + 1, l_present);
        }
    }
    else{
        if(arr[i] == 1){
            if(vowel_cnt == 2){
                return;
            }
            else{
                brute(i+1, cnt, n, 0, vowel_cnt + 1, l_present);
            }
        }
        else{
            if(const_cnt == 2){
                return;
            }
            else{
                brute(i+1, cnt, n, const_cnt + 1, 0, l_present);
            }
        }
    }
}


int main(){
    string s;
    cin >> s;
    bool l_present = false;
    total = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '_'){
            arr[i] = -1;
            continue;
        }
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            arr[i] = 1;
        }
        else{
            if(s[i] == 'L'){
                l_present = true;
            }
            arr[i] = 0;
        }
    }

    brute(0, 1, s.length(), 0, 0, l_present);
    printf("%llu\n", total);

}
