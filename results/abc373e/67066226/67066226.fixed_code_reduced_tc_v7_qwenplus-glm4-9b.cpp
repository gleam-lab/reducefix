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
    ll sum_votes = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum_votes += a[i];
    }

    vector<pair<ll, int>> candidates(n);
    for(int i = 0; i < n; i++) {
        candidates[i] = {a[i], i};
    }

    // Sort by votes to efficiently find the smallest votes
    sort(all(candidates));
    vector<ll> sorted_votes(candidates.begin(), candidates.end());
    vector<int> indices(candidates.begin(), candidates.end());

    // Calculate prefix sums of sorted votes for efficient range queries
    vector<ll> prefix(n + 1);
    for(int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + sorted_votes[i].first;
    }

    vector<ll> results(n, -1);
    for(int i = 0; i < n; i++) {
        int idx = indices[i].first;
        ll votes_needed = m - 1; // candidate needs at least m votes to win

        // Find the smallest vote count from the m-th largest candidate
        ll smallest_votes_in_list = sorted_votes[n - m].first;

        // Calculate the remaining votes
        ll remaining_votes = k - sum_votes;

        // If the candidate already has more than m votes, no additional votes are needed
        if(a[idx] >= smallest_votes_in_list + votes_needed) {
            results[idx] = 0;
            continue;
        }

        // Calculate the minimum votes needed to secure the victory
        ll votes_to_secure = smallest_votes_in_list + votes_needed - a[idx];
        if(remaining_votes >= votes_to_secure) {
            results[idx] = votes_to_secure;
        } else {
            results[idx] = -1;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << results[i] << ' ';
    }
}