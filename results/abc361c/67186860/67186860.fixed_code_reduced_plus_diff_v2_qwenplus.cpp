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
    
    // We remove exactly K elements, so we keep (n - k) elements.
    // The optimal way is to remove some number of smallest and largest elements.
    // Try all possible ways: remove i from left and (k - i) from right, for i in [0, k]
    long long ans = 1e18;
    for (int i = 0; i <= k; i++) {
        int left_removed = i;
        int right_removed = k - i;
        if (left_removed + right_removed > n || n - k == 0) continue;
        int min_val = a[left_removed];
        int max_val = a[n - 1 - right_removed];
        ans = min(ans, (long long)(max_val - min_val));
    }
    
    cout << ans << endl;
    return 0;
}