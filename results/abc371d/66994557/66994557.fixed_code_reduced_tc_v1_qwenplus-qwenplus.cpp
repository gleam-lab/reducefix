#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    
    vector<long long> x(n + 2), p(n + 2);  // Using long long to avoid overflow in prefix sums
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        p[i] += p[i - 1];  // Compute prefix sum
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;

        // Find first index where x[i] >= L
        int left = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();

        // Find first index where x[i] > R
        int right = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin();

        cout << p[right - 1] - p[left - 1] << '\n';
    }

    return 0;
}