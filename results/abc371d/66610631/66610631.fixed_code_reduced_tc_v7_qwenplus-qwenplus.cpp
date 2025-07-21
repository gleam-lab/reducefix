#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        c[i] = c[i - 1] + b[i];
    }

    // Ensure the a array is sorted for binary search
    // As per problem description, assuming a is already strictly increasing

    cin >> m;
    while (m--) {
        ll l, r;
        cin >> l >> r;

        // Find first index where a[i] >= l
        int left = lower_bound(a.begin() + 1, a.end(), l) - a.begin();

        // Find first index where a[i] > r
        int right = upper_bound(a.begin() + 1, a.end(), r) - a.begin();

        cout << c[right - 1] - c[left - 1] << '\n';
    }

    return 0;
}