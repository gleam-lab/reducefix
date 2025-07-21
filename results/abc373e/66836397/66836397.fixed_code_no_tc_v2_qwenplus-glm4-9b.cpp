#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, K;
vector<ll> a;

int main() {
    cin >> n >> m >> K;
    a.resize(n);
    for (ll &ai : a) cin >> ai;

    // Calculate the votes remaining to be counted
    ll votes_remaining = K - accumulate(a.begin(), a.end(), 0LL);

    // Sort the votes received by each candidate in ascending order
    sort(a.begin(), a.end());

    // Prepare to accumulate the votes to find the m-th and (m-1)-th largest votes
    vector<ll> prefix_sums(n);
    prefix_sums[0] = a[0];
    for (ll i = 1; i < n; ++i) {
        prefix_sums[i] = prefix_sums[i - 1] + a[i];
    }

    vector<ll> min_votes_needed(n, -1LL); // Initialize with -1 to indicate impossible

    // Iterate over each candidate in reverse order (starting from the one with the most votes)
    for (ll i = n - 1; i >= 0; --i) {
        // Number of votes needed to guarantee the victory
        ll votes_needed = (m - 1) * votes_remaining + prefix_sums[i] - prefix_sums[m - 2];

        // If the candidate already has more than or equal to m-1 votes, they are guaranteed to win
        if (a[i] >= votes_needed) {
            min_votes_needed[i] = 0;
            // Deallocate votes needed for other candidates
            votes_remaining -= votes_needed - (prefix_sums[i] - prefix_sums[m - 2]);
        } else {
            // Check if it's still possible to win with the remaining votes
            if (votes_needed <= votes_remaining) {
                min_votes_needed[i] = votes_needed;
            }
        }
    }

    // Output the result for each candidate
    for (ll votes_needed : min_votes_needed) {
        cout << (votes_needed == -1LL ? -1 : votes_needed) << " ";
    }
    cout << endl;

    return 0;
}