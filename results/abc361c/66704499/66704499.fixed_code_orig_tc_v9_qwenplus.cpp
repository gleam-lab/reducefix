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

    // We are removing exactly K elements
    // So we keep (n - k) elements
    int keep = n - k;
    long long ans = 1e18;

    // Try all possible contiguous subarrays of length 'keep'
    // After sorting, the optimal remaining sequence will be a contiguous segment
    // because we want to minimize (max - min)
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        ans = min(ans, (long long)(a[j] - a[i]));
    }

    cout << ans << endl;

    return 0;
}