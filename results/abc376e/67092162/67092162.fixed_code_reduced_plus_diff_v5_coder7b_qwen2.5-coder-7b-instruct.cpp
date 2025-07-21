#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long minProduct = LLONG_MAX;

        // Use sliding window to find the minimum product
        for (int i = 0; i <= n - k; ++i) {
            long long currentMax = a[n - k + i];
            long long currentSum = 0;
            for (int j = 0; j < k; ++j) {
                currentSum += b[i + j];
            }
            minProduct = min(minProduct, currentMax * currentSum);
        }

        cout << minProduct << "\n";
    }
    return 0;
}