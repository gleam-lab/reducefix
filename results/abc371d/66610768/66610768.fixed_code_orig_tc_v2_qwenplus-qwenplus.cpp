#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n + 1, 0), b(n + 1, 0), prefix_b(n + 1, 0);
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

        auto left = lower_bound(a.begin() + 1, a.end(), l);
        auto right = upper_bound(a.begin() + 1, a.end(), r);

        int left_idx = left - a.begin();
        int right_idx = right - a.begin();

        cout << prefix_b[right_idx - 1] - prefix_b[left_idx - 1] << '\n';
    }

    return 0;
}