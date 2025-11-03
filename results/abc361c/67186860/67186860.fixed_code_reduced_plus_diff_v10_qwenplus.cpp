#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    int keep = n - k;
    int ans = a[keep - 1] - a[0]; // Initial candidate: remove last k
    
    // Try all possible ways to remove x from left and (k - x) from right
    for (int left_remove = 0; left_remove <= k; left_remove++) {
        int right_remove = k - left_remove;
        if (left_remove + right_remove > n) continue;
        if (left_remove + right_remove == 0) continue;
        
        int remaining_left = left_remove;
        int remaining_right = n - 1 - right_remove;
        
        if (remaining_left <= remaining_right) {
            ans = min(ans, a[remaining_right] - a[remaining_left]);
        }
    }
    
    cout << ans << endl;
    return 0;
}