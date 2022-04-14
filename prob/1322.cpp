#include <stdio.h>
#include <stdint.h>

using namespace std;

int main(){
    uint64_t x, k;

    scanf(" %llu %llu", &x, &k);

    uint64_t inv = ~x;
    uint64_t lsh = 64 - __builtin_clzll(x);
    uint64_t remainder_mask = ~(0xffffffffffffffff << lsh);

    uint64_t divisor_num = remainder_mask & inv;
    uint64_t divisor = (1 << __builtin_popcountll(divisor_num));

    uint64_t quot = k / divisor;
    uint64_t rem = k % divisor;

    uint64_t result = (quot << lsh);

    uint64_t lsh_count = 0;

    for(uint64_t i = 0; i < __builtin_popcountll(remainder_mask); i++){
        uint64_t cur = (divisor_num >> i) & 1;
        if(cur == 1){
            uint64_t is_1 = (rem >> lsh_count) & 1;
            if(is_1 == 1){
                result += (1 << i);
            }
            lsh_count++;
        }
    }

    printf("%llu\n", result);
}
