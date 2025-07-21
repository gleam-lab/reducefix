#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n), b(q), k(q);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
        --k[i];  // Adjusting to zero-based index for easier handling
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < q; ++i) {
        auto& bi = b[i];
        auto& ki = k[i];

        auto lb = lower_bound(a.begin(), a.end(), bi);
        int left = lb - a.begin();
        int right = n - left;

        if (ki < left) {
            // k-th smallest distance is within the range of a
            cout << *lb - bi << '\n';
        } else if (ki < left + right) {
            // k-th smallest distance is the difference between two consecutive points
            cout << a[left + ki] - a[left + ki - 1] << '\n';
        } else {
            // k-th smallest distance is greater than the last element minus the first element
            cout << bi - a[0] << '\n';
        }
    }

    return 0;
}