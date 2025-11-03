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

    int ans = a[n - 1] - a[0];
    // We remove exactly k elements, so we keep (n - k) elements.
    // Try all possible contiguous subarrays of length (n - k)
    for (int i = 0; i + (n - k) - 1 < n; i++) {
        int j = i + (n - k) - 1;
        ans = min(ans, a[j] - a[i]);
    }

    cout << ans << endl;

    return 0;
}