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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    // Calculate the number of votes needed to surpass the highest voted candidate minus one
    ll max_votes_needed = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
    if (k < max_votes_needed) {
        for (int i = 0; i < n; ++i) cout << -1 << " ";
        return 0;
    }

    // Sort candidates by their vote count in ascending order
    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; ++i) candidates[i] = {a[i], i};
    sort(candidates.begin(), candidates.end());

    // Calculate the minimum additional votes needed for each candidate
    vector<ll> min_additional_votes(n, 0);
    ll remaining_votes = k;
    for (int i = 0; i < n; ++i) {
        if (remaining_votes < candidates[i].first - candidates[n - 1].first) break;
        min_additional_votes[candidates[i].second] = candidates[i].first - candidates[n - 1].first;
        remaining_votes -= (candidates[i].first - candidates[n - 1].first);
    }

    // Adjust the results based on remaining votes and the requirement to surpass M candidates
    for (int i = 0; i < n; ++i) {
        if (candidates[i].first + remaining_votes < candidates[n - m - 1].first) {
            min_additional_votes[candidates[i].second] = -1;
        } else {
            min_additional_votes[candidates[i].second] = candidates[n - m - 1].first - candidates[i].first;
        }
    }

    // Output the results
    for (ll val : min_additional_votes) cout << val << " ";

    return 0;
}