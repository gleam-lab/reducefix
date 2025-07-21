#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> x(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // Compute prefix sums for cumulative population counts
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + p[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Binary search to find the first index where x[index] >= l
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x[mid] >= l) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // Binary search to find the last index where x[index] <= r
        left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (x[mid] <= r) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        // Calculate the result using prefix sums
        cout << a[left] - a[max(0, left - 1)] << endl;
    }

    return 0;
}