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
    
    // We need to remove exactly K elements, so we keep (n - k) elements
    int keep = n - k;
    int ans = a[keep - 1] - a[0]; // Initial candidate: first 'keep' elements
    
    // Try all possible contiguous segments of length 'keep'
    // We can remove some from left and some from right
    for (int left_removed = 0; left_removed <= k; left_removed++) {
        int right_removed = k - left_removed;
        int right_kept = n - right_removed - 1;
        int left_kept = left_removed;
        
        if (right_kept >= left_kept) {
            ans = min(ans, a[right_kept] - a[left_kept]);
        }
    }
    
    cout << ans << endl;
    return 0;
}