#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n + 2), b(n + 2), prefix_b(n + 2, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        prefix_b[i] = prefix_b[i - 1] + b[i];
    }

    int m;
    cin >> m;

    while (m--) {
        ll l, r;
        cin >> l >> r;

        // Find first index where a[i] >= l
        int left = lower_bound(a.begin() + 1, a.end(), l) - a.begin();

        // Find first index where a[i] > r
        int right = upper_bound(a.begin() + 1, a.end(), r) - a.begin();

        if (left == n + 1 || right == 1) {
            cout << 0 << '\n';
        } else {
            cout << prefix_b[right - 1] - prefix_b[left - 1] << '\n';
        }
    }

    return 0;
}