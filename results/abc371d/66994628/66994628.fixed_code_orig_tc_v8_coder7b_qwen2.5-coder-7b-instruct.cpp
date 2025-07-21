#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Adjust indices to be zero-based for binary search
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        
        int idx_l = distance(x + 1, it_l);
        int idx_r = distance(x + 1, it_r);
        
        if (idx_l > n || idx_r > n) continue; // Skip invalid queries
        
        cout << sum[idx_r - 1] - sum[idx_l - 1] << endl;
    }
    return 0;
}