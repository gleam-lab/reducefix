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

    // Sort the vote counts in ascending order
    sort(a.begin(), a.end());

    // Calculate the prefix sums
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll needed = 0;
        // Calculate the maximum number of votes that can be received by other candidates
        ll max_votes_by_others = pref[n] - a[i] - (n - i - 1) * (a[i] + 1);
        // Check if the current candidate can win even if others get the maximum possible votes
        if (max_votes_by_others < (m - 1) * (a[i] + 1)) {
            needed = (m - 1) * (a[i] + 1) - max_votes_by_others;
        }
        ans[i] = needed;
    }

    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}