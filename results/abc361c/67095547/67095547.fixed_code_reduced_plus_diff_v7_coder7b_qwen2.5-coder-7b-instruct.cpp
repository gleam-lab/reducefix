#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans = LLONG_MAX;
    for (int i = 0; i <= n - k; ++i) {
        ans = min(ans, a[i + k - 1] - a[i]);
    }

    cout << ans << '\n';

    return 0;
}