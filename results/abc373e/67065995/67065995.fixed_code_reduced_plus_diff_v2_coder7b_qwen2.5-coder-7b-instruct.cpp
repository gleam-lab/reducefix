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

    // Sort the votes in descending order
    sort(a.rbegin(), a.rend());

    // Calculate the prefix sum array
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        // The candidate needs more votes than the Mth most popular candidate
        // after accounting for the remaining votes
        ll target = pref[min(i + m, n)] - pref[i + 1];
        if (target < k) {
            ans[i] = target - k;
        } else {
            ans[i] = 0;
        }
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}