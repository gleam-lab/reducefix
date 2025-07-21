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

    // Pair each candidate's current votes with their index
    vector<pair<ll, int>> votes(a.begin(), a.end());

    // Sort candidates by their current votes in descending order
    sort(votes.rbegin(), votes.rend());

    // Calculate the maximum votes a candidate can get to still be in top M
    vector<ll> max_votes(n, 0);
    ll threshold_votes = votes[m - 1].first;
    for(int i = 0; i < m; i++) {
        max_votes[i] = votes[i].first;
    }

    // Calculate the gaps between the votes of each candidate and the one before them
    vector<ll> gaps(n, 0);
    for(int i = 0; i < n - 1; i++) {
        gaps[i] = votes[i + 1].first - votes[i].first - 1;
    }

    // Calculate minimum additional votes needed for each candidate
    vector<ll> ans(n, 0);
    for(int i = 0; i < n; i++) {
        // Calculate the remaining votes after allocating max_votes to top M candidates
        ll remaining_votes = k - m * (threshold_votes - votes[i].first);

        // If the current candidate is in the top M or has enough votes to reach the threshold
        if(i < m || remaining_votes >= gaps[i]) {
            ans[i] = 0;
        } else {
            // Calculate the minimum number of additional votes needed
            ans[i] = threshold_votes - votes[i].first + (remaining_votes + gaps[i] - 1) / gaps[i];
        }
    }

    // Output the results
    for(ll vote : ans) {
        cout << vote << ' ';
    }
    cout << '\n';
    return 0;
}