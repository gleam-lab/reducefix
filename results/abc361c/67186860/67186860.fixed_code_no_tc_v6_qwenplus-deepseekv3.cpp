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
    
    int ans = INT_MAX;
    for (int l = 0; l <= k; l++) {
        int r = k - l;
        if (r >= 0 && l + r <= n) {
            ans = min(ans, a[n - 1 - r] - a[l]);
        }
    }
    cout << ans << endl;
    return 0;
}