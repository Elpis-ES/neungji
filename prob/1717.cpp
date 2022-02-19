// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

struct dset{

    vector<int> g;
    dset(int N): g(N){
        for(int i=0; i<N; i++){
            g[i]=i;
        }
    }

    int find(int n){
        if(n==g[n]){
            return n;
        }
        return g[n]=find(g[n]);
    }

    bool merge(int p, int q){
        p=find(p);
        q=find(q);
        if(p!=q){
            g[p]=q;
            return true;
        }
        return false;
    }
};

int main(void){
    int n, m, i, op, p, q;
    scanf("%d %d", &n, &m);
    dset d = dset(n+1);
    for(i=0; i<m; i++){
        scanf("%d %d %d", &op, &p, &q);
        if(op==0){
            d.merge(p, q);
        }
        else{
            if(d.find(p)==d.find(q)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
}
