#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
long long sum[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Find the first village greater than or equal to L
        auto it_l = lower_bound(x + 1, x + n + 1, L);
        if (it_l == x + n + 1) continue; // No village found in the range
        
        int c = it_l - x;
        
        // Find the first village greater than R
        auto it_r = upper_bound(x + 1, x + n + 1, R);
        if (it_r == x + n + 1) continue; // No village found in the range
        
        int d = it_r - x;
        
        cout << sum[d - 1] - sum[c - 1] << endl;
    }
    
    return 0;
}