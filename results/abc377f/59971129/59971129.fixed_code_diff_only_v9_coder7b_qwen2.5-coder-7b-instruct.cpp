#include <bits/stdc++.h>
using namespace std;

#define N 1000005

long long n, m, a[N], b[N];
unordered_set<long long> s, t, u, v;
unordered_map<long long, bool> vis;

int main() {
    scanf("%lld %lld", &n, &m);
    for(long long i = 1; i <= m; ++i) {
        scanf("%lld %lld", &a[i], &b[i]);
        s.insert(a[i]);
        t.insert(b[i]);
        u.insert(a[i] - b[i]);
        v.insert(a[i] + b[i]);
    }
    
    // Calculate non-capturable positions
    long long ans = (n - s.size()) * (n - t.size());
    for(auto& x : u) {
        long long tmp = n - abs(x);
        for(auto& y : s) {
            if(abs(y - x) == 1 && !vis[y]) {
                --tmp;
                vis[y] = true;
            }
        }
        for(auto& y : t) {
            if(abs(x + y) == 1 && !vis[y]) {
                --tmp;
                vis[y] = true;
            }
        }
        ans -= tmp;
        vis.clear();
    }

    for(auto& x : v) {
        long long tmp = n - abs(x - n);
        for(auto& y : s) {
            if(abs(x - y) == 1 && !vis[y]) {
                --tmp;
                vis[y] = true;
            }
        }
        for(auto& y : t) {
            if(abs(x - y) == 1 && !vis[y]) {
                --tmp;
                vis[y] = true;
            }
        }
        for(auto& y : u) {
            long long p = x + y, q = x - y;
            if((p % 2 == 0 || q % 2 == 0) && p / 2 >= 1 && p / 2 <= n && q / 2 >= 1 && q / 2 <= n) {
                p /= 2; q /= 2;
                if(!vis[p]) {
                    --tmp;
                    vis[p] = true;
                }
            }
        }
        ans -= tmp;
        vis.clear();
    }

    printf("%lld\n", ans + 1);

    return 0;
}