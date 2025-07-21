#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 200000 + 10;

i64 a[N], b[N], sm[N];

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    
    if (m == n) {
        for(i64 i = 1; i <= n; ++i)
            cout << 0 << " ";
        cout << "\n";
        return;
    }
    
    for(i64 i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    
    i64 remaining = k;
    for(i64 i = 1; i <= n; ++i)
        remaining -= a[i];
    
    sort(b + 1, b + n + 1);
    for(i64 i = n; i >= 1; --i)
        sm[i] = sm[i + 1] + b[i];
    
    auto check = [&](i64 x, i64 d) -> bool {
        // Candidate x gets d additional votes
        i64 total = x + d;
        
        // Find how many candidates have more votes than x currently
        i64 *ptr = upper_bound(b + 1, b + n + 1, total);
        i64 idx = ptr - b;
        i64 above = n - idx + 1;
        
        if(above >= m) return false;
        
        i64 need = m - above;
        i64 cutoff = b[n - need + 1];
        
        // If current candidate's value is already enough to make top M
        if(total > cutoff) return true;
        
        // Calculate sum of the top M-1 excluding this candidate
        i64 sum_top = sm[idx] - sm[idx + need];
        i64 threshold = sm[idx] - sm[idx + need] + total;
        
        // Check if even with maximum allocation to others, we can't beat them
        return total * need > sum_top;
    };
    
    for(i64 i = 1; i <= n; ++i) {
        i64 l = 0, r = remaining, ans = -1;
        
        while(l <= r) {
            i64 mid = (l + r) / 2;
            if(check(a[i], mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        cout << (ans != -1 ? ans : -1) << " ";
    }
    
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    
    return 0;
}