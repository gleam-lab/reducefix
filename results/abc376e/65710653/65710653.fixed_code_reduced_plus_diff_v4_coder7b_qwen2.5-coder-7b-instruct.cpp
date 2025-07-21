#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        
        // Read input arrays
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Sort A in descending order
        sort(a.begin(), a.end(), greater<int>());
        // Sort B in ascending order
        sort(b.begin(), b.end());

        long long result = 0;
        // Calculate the result as described
        for (int i = 0; i < k; ++i) {
            result += 1LL * a[i] * b[n - k + i];
        }

        cout << result << '\n';
    }
    return 0;
}