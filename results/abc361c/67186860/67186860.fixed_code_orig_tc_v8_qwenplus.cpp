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
    if (keep == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    // Try all possible contiguous segments of length 'keep' in the sorted array.
    // Since we want to minimize (max - min) of the remaining sequence,
    // and we can choose any K elements to remove, the optimal strategy is
    // to leave a contiguous block in the sorted array (because otherwise we could
    // get a smaller range by shifting).
    long long ans = 1e18;
    for (int i = 0; i + keep - 1 < n; i++) {
        ans = min(ans, (long long)(a[i + keep - 1] - a[i]));
    }
    
    cout << ans << endl;
    return 0;
}