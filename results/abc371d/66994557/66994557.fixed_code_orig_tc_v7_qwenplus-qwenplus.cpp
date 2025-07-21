#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n;
    
    vector<long long> x(n + 2); // 1-based indexing
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    vector<long long> p(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    
    // Prefix sum of p
    vector<long long> sum(n + 2);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;
        
        // Find first index >= L using lower_bound
        int l = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();
        
        // Find last index <= R using upper_bound
        int r = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin() - 1;
        
        cout << sum[r] - sum[l - 1] << "\n";
    }
    
    return 0;
}