#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    // Calculate prefix sums of sorted votes
    vector<ll> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end());
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = sorted_a[i] + pref[i];
    }

    // Determine the minimum number of additional votes needed for each candidate
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++) {
        ll target = sorted_a[n - m - 1] + 1;
        if (target > a[i]) {
            ll need = target - a[i];
            if (need <= k) {
                ans[i] = need;
            } else {
                ans[i] = -1;
            }
        }
    }

    // Output the results
    for (auto i : ans) cout << i << ' ';
    return 0;
}