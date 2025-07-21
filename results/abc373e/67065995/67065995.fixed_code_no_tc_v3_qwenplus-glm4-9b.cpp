#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

struct candidate {
    ll votes;
    int index;
};

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

    // Create a vector of candidates and sort them by votes descending
    vector<candidate> candidates(n);
    for (int i = 0; i < n; i++) {
        candidates[i] = {a[i], i};
    }
    sort(candidates.rbegin(), candidates.rend()); // Sort in descending order for easier calculations

    // Calculate the votes needed to guarantee victory
    vector<ll> votes_needed(n);
    vector<ll> votes_left = k; // Total votes left to be counted
    bool possible[n]; // To check if victory is possible

    for (int i = 0; i < m; i++) {
        if (i == m - 1 || candidates[i + 1].votes != candidates[i].votes) {
            ll votes_diff = candidates[i].votes - candidates[i + 1].votes; // Votes difference between current and next candidate
            ll min_votes = votes_diff * (m - 1 - i) - (m - 1 - i) * (m - 1 - i) / 2; // Minimum votes needed to guarantee current candidate wins
            votes_needed[candidates[i].index] = max(0LL, min_votes);
            votes_left -= votes_needed[candidates[i].index];
            possible[candidates[i].index] = votes_needed[candidates[i].index] <= votes_left;
        } else {
            votes_needed[candidates[i].index] = 0;
            possible[candidates[i].index] = true;
        }
    }

    // Output the results
    for (int i = 0; i < n; i++) {
        if (possible[i]) {
            cout << votes_needed[i] << " ";
        } else {
            cout << "-1 ";
        }
    }
}