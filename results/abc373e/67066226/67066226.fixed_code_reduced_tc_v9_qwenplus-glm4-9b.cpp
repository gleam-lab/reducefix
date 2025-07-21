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

    // Sort candidates by their votes and index
    vector<pair<ll, int>> indexed_a(n);
    for (int i = 0; i < n; ++i) {
        indexed_a[i] = {a[i], i};
    }
    sort(indexed_a.begin(), indexed_a.end());

    // Calculate the number of votes each candidate needs to guarantee victory
    vector<ll> votes_needed(n, -1);
    for (int i = 0; i < n; ++i) {
        // Remaining positions needed to win
        int remaining_positions = max(n - (m + 1), 0);
        // Maximum votes they can have after distributing all remaining votes
        ll max_votes = indexed_a[i].first + k;
        // Votes needed to guarantee the victory is the difference between these two
        votes_needed[indexed_a[i].second] = max_votes - remaining_positions;
    }

    // Sort votes_needed and indexed_a by votes_needed (in descending order)
    sort(votes_needed.begin(), votes_needed.end(), greater<ll>());
    sort(indexed_a.begin(), indexed_a.end(), [](const pair<ll, int>& a, const pair<ll, int>& b) {
        return a.first > b.first;
    });

    vector<ll> ans(n, -1);
    ll current_votes_needed = 0;
    for (int i = 0; i < n; ++i) {
        // Update votes_needed if the current candidate's votes_needed is greater
        if (votes_needed[indexed_a[i].second] > current_votes_needed) {
            current_votes_needed = votes_needed[indexed_a[i].second];
        }
        // If current_votes_needed is greater than 0, this candidate needs those many additional votes
        if (current_votes_needed > 0) {
            ans[indexed_a[i].second] = votes_needed[indexed_a[i].second] - current_votes_needed;
        } else {
            ans[indexed_a[i].second] = 0;
        }
    }

    for (const ll& vote : ans) {
        cout << vote << " ";
    }
    cout << endl;

    return 0;
}