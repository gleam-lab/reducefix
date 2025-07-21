#include<bits/stdc++.h>
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
        
        // Adjusting indices to be zero-based for binary search
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        
        l = distance(x + 1, it_l);
        r = distance(x + 1, it_r);
        
        if (l == n && x[n] < l) ++l; // If l is out of bounds, adjust
        if (r == n && x[n] > r) --r; // If r is out of bounds, adjust
        
        long long result = sum[min(r, n)] - sum[max(l - 1, 0)];
        cout << result << endl;
    }
    return 0;
}