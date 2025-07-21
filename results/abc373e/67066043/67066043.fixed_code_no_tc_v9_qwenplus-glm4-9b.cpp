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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Sort candidates by current votes
    vector<pair<ll, int>> sorted_a(a.begin(), a.end());
    sort(sorted_a.begin(), sorted_a.end());

    // Calculate number of candidates with more votes and number of votes to get minimum votes required to win
    vector<ll> votes_needed(n, -1);
    ll sum_votes = 0;
    for (int i = 0; i < n; i++) {
        sum_votes += sorted_a[i].first;
    }

    for (int i = n - 1; i >= n - m; i--) {
        if (i > 0 && sorted_a[i].first == sorted_a[i - 1].first) {
            continue; // Skip if same votes as previous candidate
        }
        ll votes_to_win = (m - 1) * sorted_a[i].first + sorted_a[i].first;
        if (sorted_a[i].first + (k - sum_votes) >= votes_to_win) {
            votes_needed[i] = votes_to_win - sorted_a[i].first - (k - sum_votes);
        } else {
            votes_needed[i] = -1; // Cannot win even with all remaining votes
        }
    }

    // Output the minimum votes needed for each candidate
    for (int i = 0; i < n; i++) {
        if (i < n - m || votes_needed[i] != -1) {
            cout << votes_needed[i] << ' ';
        } else {
            cout << -1 << ' ';
        }
    }
    cout << '\n';
}