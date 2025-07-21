#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, a[n - 1 - (k - i)] - a[i]);
    }
    cout << ans << endl;
    return 0;
}