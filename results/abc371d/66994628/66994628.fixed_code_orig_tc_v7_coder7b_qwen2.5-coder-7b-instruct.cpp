#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n;
    vector<long long> x(n + 1), p(n + 1), prefix_sum(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Adjusting indices for zero-based indexing used internally
        --l, --r;
        
        long long result = prefix_sum[r] - prefix_sum[l];
        cout << result << '\n';
    }
    
    return 0;
}