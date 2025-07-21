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

    // Sort indices based on the current vote counts
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });

    // Calculate the prefix sum of sorted vote counts
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[ord[i]];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll target = a[ord[i]] + 1; // Minimum vote needed to ensure victory
        int pos = upper_bound(pref.begin() + i + 1, pref.end(), target * (n - i)) - pref.begin();

        if (pos - i < n - m) {
            ans[ord[i]] = target * (n - i) - pref[pos];
        } else if (pos == n) {
            ans[ord[i]] = 0;
        }
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}