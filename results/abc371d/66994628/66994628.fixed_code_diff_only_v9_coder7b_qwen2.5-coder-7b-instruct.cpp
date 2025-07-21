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
        
        if (it_l == x + n + 1 || *it_l != l) --it_l; // Find the largest x[j] <= l
        if (it_r == x + n + 1 || *it_r != r) --it_r; // Find the smallest x[j] >= r
        
        int idx_l = it_l - x;
        int idx_r = it_r - x;
        
        // Calculate the result using prefix sums
        cout << sum[idx_r] - sum[idx_l] << endl;
    }
    return 0;
}