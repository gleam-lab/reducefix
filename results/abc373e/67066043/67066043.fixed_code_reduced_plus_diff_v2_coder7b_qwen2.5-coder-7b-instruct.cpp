#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

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

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        int idx = ord[i];
        ll left_votes = k;
        int remaining_candidates = n - i - 1;

        // Calculate the maximum number of votes another candidate can get
        ll max_other_votes = pref[n] - pref[idx + 1];

        // Calculate the number of votes needed for current candidate to win
        ll needed_votes = max_other_votes + 1 + remaining_candidates - m;

        if (needed_votes <= left_votes) {
            ans[idx] = needed_votes;
        } else {
            ans[idx] = -1;
        }
    }

    for (auto i : ans) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}