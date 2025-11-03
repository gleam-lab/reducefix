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
    int ans = a[keep - 1] - a[0]; // initial candidate: remove last k elements
    
    // Try all possible ways to remove x from left and (k - x) from right
    for (int left_removed = 0; left_removed <= k; left_removed++) {
        int right_removed = k - left_removed;
        if (left_removed + right_removed > n || right_removed < 0) continue;
        
        int left_idx = left_removed;
        int right_idx = n - 1 - right_removed;
        
        if (left_idx <= right_idx) {
            ans = min(ans, a[right_idx] - a[left_idx]);
        }
    }
    
    cout << ans << endl;
    return 0;
}