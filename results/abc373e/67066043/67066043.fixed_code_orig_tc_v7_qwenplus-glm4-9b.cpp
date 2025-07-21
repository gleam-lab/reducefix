#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }

    sort(votes.begin(), votes.end());

    vector<ll> required_votes(n, -1); // Initialize with -1, indicating uncertainty

    ll remaining_votes = k - accumulate(votes.begin(), votes.end(), 0LL);
    ll min_votes_needed = votes[n - m - 1] + m; // Minimum votes needed to secure a win

    for (int i = 0; i < n; ++i) {
        // Calculate the required additional votes to surpass at least `m` candidates
        ll additional_votes_needed = max(0LL, min_votes_needed - votes[i]);

        // Check if the remaining votes are enough to secure the win
        if (remaining_votes >= additional_votes_needed) {
            required_votes[i] = additional_votes_needed;
        } else {
            // If not enough votes left, then the candidate cannot secure a win
            required_votes[i] = -1;
        }
    }

    for (const auto& vote : required_votes) {
        cout << vote << " ";
    }
    cout << endl;

    return 0;
}