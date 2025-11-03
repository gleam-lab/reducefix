#include <bits/stdc++.h>
using namespace std;

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
    
    long long ans = 1e18;
    // Try removing k elements: left l elements and right (k-l) elements
    for (int l = 0; l <= k; l++) {
        int r = k - l;
        if (l + r > n) continue;
        int remaining_left = l;
        int remaining_right = n - 1 - r;
        if (remaining_left <= remaining_right) {
            ans = min(ans, (long long)a[remaining_right] - a[remaining_left]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}