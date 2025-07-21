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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort candidates based on their current vote counts
    vector<pair<ll, int>> candidates;
    for(int i = 0; i < n; i++) {
        candidates.push_back({a[i], i});
    }
    sort(candidates.begin(), candidates.end());

    // Calculate the prefix sum of sorted vote counts
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + candidates[i].first;
    }

    vector<ll> ans(n, -1);

    // Iterate over each candidate
    for(int i = 0; i < n; i++) {
        ll target_votes = candidates[i].first + 1;
        int remaining_candidates = n - i - 1;
        ll required_votes = 0;

        // Calculate the minimum votes needed to surpass the top M candidates
        if(i >= n - m) {
            required_votes = 0;
        } else {
            int rank = min(m, remaining_candidates);
            required_votes = target_votes * rank - (pref[rank] - pref[i + 1]);
        }

        // Check if the required votes can be achieved within the remaining ballots
        if(required_votes <= k) {
            ans[candidates[i].second] = required_votes;
        }
    }

    // Output the results
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}