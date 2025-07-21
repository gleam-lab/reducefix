#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n + 1), p(n + 1), a(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Find the first x[i] >= l
        int left = 1, right = n, l1 = n + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x[mid] >= l) {
                l1 = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // Find the last x[i] <= r
        left = 1, right = n;
        int l2 = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x[mid] <= r) {
                l2 = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if (l1 <= l2) {
            cout << a[l2] - a[l1 - 1] << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}