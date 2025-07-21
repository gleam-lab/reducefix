#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    
    // Pair x[i] and p[i], then sort based on x[i]
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; i++) {
        vec.emplace_back(x[i], p[i]);
    }
    sort(vec.begin(), vec.end());
    
    // Rebuild x and p arrays after sorting
    for (int i = 0; i < n; i++) {
        x[i + 1] = vec[i].first;
        p[i + 1] = vec[i].second;
    }
    
    // Compute prefix sums
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + p[i];
    }
    
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        
        // Find the first x[i] >= l using lower_bound
        int l1 = lower_bound(x + 1, x + n + 1, l) - x;
        
        // Find the last x[i] <= r using upper_bound
        int r2 = upper_bound(x + 1, x + n + 1, r) - x - 1;
        
        if (l1 > r2) {
            cout << 0 << endl; // No elements in the range
        } else {
            cout << a[r2] - a[l1 - 1] << endl;
        }
    }
    return 0;
}