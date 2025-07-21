#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    
    vector<long long> x(n + 2); // 1-based indexing
        x[0] = -2e18;         // sentinel for lower_bound
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    x[n + 1] = 2e18; // sentinel for upper_bound

    vector<long long> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // prefix sums of p
    vector<long long> sum(n + 2);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;

        // Find first index where x[i] >= L
        int l = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();
        
        // Find first index where x[i] > R
        int r = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin();

        cout << sum[r - 1] - sum[l - 1] << "\n";
    }

    return 0;
}