#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    
    // Initialize the prefix sum array
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        
        int l1 = 1, r1 = n, l2 = 1, r2 = n;
        
        // Binary search to find the left boundary
        while (l1 < r1) {
            int mid = l1 + (r1 - l1 + 1) / 2;
            if (x[mid] >= l) {
                r1 = mid;
            } else {
                l1 = mid;
            }
        }
        
        // Binary search to find the right boundary
        while (l2 < r2) {
            int mid = l2 + (r2 - l2 + 1) / 2;
            if (x[mid] <= r) {
                l2 = mid;
            } else {
                r2 = mid - 1;
            }
        }
        
        // Output the result for the current query
        cout << a[l2] - a[l1 - 1] << endl;
    }
    
    return 0;
}