#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005], sum[2000005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = (i == 1) ? p[i] : sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Ensure that the indices are within the proper range
        l = max(1, min(l, n));
        r = max(1, min(r, n));
        
        // Calculate the sum using the prefix sum array
        cout << sum[r - 1] - sum[l - 1] << endl;
    }

    return 0;
}