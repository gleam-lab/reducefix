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
    int keep = n - k;
    int ans = a[keep - 1] - a[0]; // Initial candidate: first 'keep' elements
    
    // Try all possible windows of length 'keep'
    for (int i = 1; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        ans = min(ans, a[j] - a[i]);
    }
    
    cout << ans << endl;
    return 0;
}