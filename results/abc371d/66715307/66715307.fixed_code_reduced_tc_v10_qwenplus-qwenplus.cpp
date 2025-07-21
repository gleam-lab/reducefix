#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> x(n + 2), p(n + 2);
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];
    
    // Build prefix sum of p
    vector<long long> a(n + 2, 0LL);
    for (int i = 1; i <= n; ++i) a[i] = a[i - 1] + p[i];
    
    int q;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Binary search to find the first position where x[i] >= l
        int left1 = 1, right1 = n;
        int idx1 = n + 1; // Start with invalid index
        while (left1 <= right1) {
            int mid = (left1 + right1) / 2;
            if (x[mid] >= l) {
                idx1 = mid;
                right1 = mid - 1;
            } else {
                left1 = mid + 1;
            }
        }
        
        // Binary search to find the last position where x[i] <= r
        int left2 = 1, right2 = n;
        int idx2 = 0; // Start with invalid index
        while (left2 <= right2) {
            int mid = (left2 + right2) / 2;
            if (x[mid] <= r) {
                idx2 = mid;
                left2 = mid + 1;
            } else {
                right2 = mid - 1;
            }
        }
        
        if (idx1 > idx2) {
            cout << 0 << endl;
        } else {
            cout << a[idx2] - a[idx1 - 1] << endl;
        }
    }

    return 0;
}