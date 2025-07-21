#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    
    // Create a list of indices sorted based on x[i]
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 1);
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return x[i] < x[j];
    });
    
    // Build prefix sum array based on sorted order
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + p[indices[i - 1]];
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Find the first x >= l in the sorted array
        int l1 = 1, r1 = n;
        while (l1 <= r1) {
            int mid = (l1 + r1) / 2;
            if (x[indices[mid - 1]] >= l) r1 = mid - 1;
            else l1 = mid + 1;
        }
        
        // Find the last x <= r in the sorted array
        int l2 = 1, r2 = n;
        while (l2 <= r2) {
            int mid = (l2 + r2) / 2;
            if (x[indices[mid - 1]] <= r) l2 = mid + 1;
            else r2 = mid - 1;
        }
        
        // l1 is the first index >= l, r2 is the last index <= r
        if (l1 > n || r2 < 1 || l1 > r2) {
            cout << 0 << endl;
        } else {
            cout << a[r2] - a[l1 - 1] << endl;
        }
    }
    return 0;
}