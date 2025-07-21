#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_castio(false);
    cin.tie(NULL);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort the votes in descending order
    sort(a.rbegin(), a.rend());

    // Calculate the prefix sum array
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    vector<ll> res(n, -1);
    for (int i = 0; i < n; ++i) {
        // Calculate the number of votes needed to surpass the top M candidates
        ll needed = (m - 1) * (a[i] + 1) - pref[m];

        if (needed <= k) {
            res[i] = needed;
        } else {
            res[i] = -1;
        }
    }

    // Adjust the results based on the actual votes needed
    for (int i = 0; i < n; ++i) {
        if (res[i] != -1) {
            res[i] = max(res[i], 0LL);
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    return 0;
}