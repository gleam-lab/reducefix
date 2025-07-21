#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    vector<pair<ll, int>> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = {a[i], i};
    }
    sort(all(b));
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = b[i].first + pref[i];
    }
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        auto [ votes, idx ] = b[i];
        ll votes_needed = pref[n - m] - votes; // votes needed to surpass M-1
        if (votes + k >= votes_needed) {
            ans[idx] = 0; // already guaranteed victory
        } else {
            ll required_votes = votes_needed - votes - k;
            if (required_votes > 0) {
                ans[idx] = required_votes;
            } else {
                ans[idx] = 0;
            }
        }
    }
    for (auto vote : ans) cout << vote << ' ';
    cout << '\n';
    return 0;
}