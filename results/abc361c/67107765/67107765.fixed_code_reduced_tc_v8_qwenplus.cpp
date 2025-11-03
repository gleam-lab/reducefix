#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define chmin(x, y) x = min(x, y)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    int keep = n - k;
    if (keep <= 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // Try all possible contiguous segments of length 'keep' in the sorted array
    // because the optimal remaining sequence must be contiguous in sorted order
    // (since we want to minimize max - min, and non-contiguous would only increase range)
    int ans = a[keep - 1] - a[0]; // initial candidate: first 'keep' elements
    for (int i = 1; i + keep - 1 < n; i++) {
        chmin(ans, a[i + keep - 1] - a[i]);
    }
    
    cout << ans << endl;
}