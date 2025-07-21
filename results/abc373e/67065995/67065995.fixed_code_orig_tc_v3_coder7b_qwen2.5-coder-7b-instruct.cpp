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

    // Sort candidates by number of votes
    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {a[i], i};
    }
    sort(candidates.begin(), candidates.end());

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + candidates[i].first;
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        int idx = candidates[i].second;
        ll votes_needed = 0;

        // Calculate the number of candidates with more votes than current candidate
        int higher_vote_count = n - i - 1;

        if (higher_vote_count >= m) continue;

        // Calculate the maximum votes needed to ensure victory
        ll remaining_votes = k - pref[n] + pref[i + 1];
        if (remaining_votes < 0) remaining_votes = 0;

        votes_needed = max(votes_needed, (ll)m - higher_vote_count - 1);
        if (votes_needed > remaining_votes) continue;

        // Calculate the exact number of additional votes needed
        ll additional_votes = max(0LL, (votes_needed * (votes_needed + 1)) / 2 - (pref[n] - pref[i + 1]));
        ans[idx] = additional_votes;
    }

    for (auto x : ans) cout << x << " ";
    return 0;
}