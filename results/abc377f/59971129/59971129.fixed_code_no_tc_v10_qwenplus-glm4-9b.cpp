#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 1005

ll n, m, a[N], b[N], ans;

set<int> s, t, u, v; // s for rows, t for columns, u for diagonals a+b, v for diagonals a-b 

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%lld%lld", &a[i], &b[i]);
        s.insert(a[i]);
        t.insert(b[i]);
        u.insert(a[i] + b[i]);
        v.insert(a[i] - b[i]);
    }
    
    // Start with total number of squares minus the size of the set of occupied rows and columns
    ans = n * n - s.size() * t.size();
    
    // Subtract the squares that can be attacked from the first half of the grid
    for (auto x : u) {
        ll max_val = min(n - 1, x + 1);
        for (int i = max_val / 2; i <= max_val; ++i) {
            if (s.find(i) == s.end() && t.find(max_val - i) == t.end()) {
                --ans;
            }
        }
    }
    
    for (auto x : v) {
        ll max_val = min(n - 1, abs(x) + 1);
        for (int i = 1; i <= max_val; ++i) {
            if (s.find(i) == s.end() && t.find(max_val - i) == t.end()) {
                --ans;
            }
        }
    }
    
    // Subtract the squares that can be attacked from the second half of the grid
    for (auto x : u) {
        ll min_val = max(0LL, x - (n - 1));
        for (int i = min_val; i <= min_val + (n - 1) / 2; ++i) {
            if (s.find(i) == s.end() && t.find(n - i) == t.end()) {
                --ans;
            }
        }
    }
    
    for (auto x : v) {
        ll min_val = max(0LL, abs(x) - (n - 1));
        for (int i = min_val; i <= min_val + (n - 1) / 2; ++i) {
            if (s.find(i) == s.end() && t.find(n - i) == t.end()) {
                --ans;
            }
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}