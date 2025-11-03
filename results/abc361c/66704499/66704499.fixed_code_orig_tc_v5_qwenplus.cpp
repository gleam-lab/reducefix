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
    // The optimal strategy is to remove some prefix and suffix such that
    // the remaining segment has minimum range (max - min).
    int ans = a[n - 1] - a[0];
    int keep = n - k;
    
    // Try all possible contiguous segments of length 'keep'
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        ans = min(ans, a[j] - a[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}