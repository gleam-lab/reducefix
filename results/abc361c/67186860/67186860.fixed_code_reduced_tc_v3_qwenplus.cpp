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
    
    // We are removing exactly K elements, so we keep (n - k) elements
    int keep = n - k;
    if (keep == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    long long ans = 1e18;
    // Try all possible contiguous segments of length 'keep'
    // We can remove some from left and some from right
    for (int left_removed = 0; left_removed <= k; left_removed++) {
        int right_removed = k - left_removed;
        if (left_removed + right_removed > n || left_removed >= n || right_removed >= n) continue;
        if (left_removed + keep > n) continue;
        
        int right_index = n - 1 - right_removed;
        int left_index = left_removed;
        if (right_index - left_index + 1 == keep) {
            ans = min(ans, (long long)(a[right_index] - a[left_index]));
        }
    }
    
    cout << ans << endl;
    return 0;
}