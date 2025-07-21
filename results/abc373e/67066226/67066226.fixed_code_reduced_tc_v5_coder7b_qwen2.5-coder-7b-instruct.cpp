#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort the votes in ascending order
    sort(a.begin(), a.end());

    // Calculate prefix sums for quick access to cumulative vote counts
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        // If the current candidate already has enough votes to win
        if (a[i] > pref[n - 1] - pref[i]) {
            ans[i] = 0;
            continue;
        }

        // Binary search for the minimum additional votes needed
        ll l = 0, r = k + 1;
        while (l < r) {
            ll mid = (l + r) / 2;
            // Calculate the number of candidates that would have more votes than the current candidate
            ll count = 0;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] + mid > a[i]) {
                    count++;
                } else {
                    break;
                }
            }
            // If count is less than M, the current candidate can win
            if (count < m) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans[i] = l;
    }

    // Output the results
    for (ll x : ans) {
        cout << x << " ";
    }
    return 0;
}