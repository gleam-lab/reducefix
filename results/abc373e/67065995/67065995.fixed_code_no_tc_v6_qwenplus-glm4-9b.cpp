#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }

    // Sort the votes to know the minimum votes needed to win
    sort(votes.begin(), votes.end());

    // Calculate the remaining votes to be distributed
    ll remaining_votes = k - accumulate(votes.begin(), votes.end(), 0LL);

    vector<ll> required_votes(n, -1);

    for (int i = 0; i < n; ++i) {
        // Current votes candidate i has
        ll current_votes = votes[i];

        // Remaining votes to distribute
        ll remaining_votes_to_account = remaining_votes;

        // We need to calculate how many more votes this candidate needs to guarantee victory
        // The candidate needs to secure the M-th place, so we need to consider the worst-case scenario
        // where all candidates ahead of them get at least as many votes as they have

        int candidates_to_consider = min(m - 1, n - i - 1); // m-1 because we don't need to consider the candidate itself

        // Calculate the minimum additional votes needed to secure the M-th place
        ll additional_votes_needed = m * votes[i] - current_votes + candidates_to_consider;

        if (additional_votes_needed <= remaining_votes_to_account) {
            required_votes[i] = additional_votes_needed;
            remaining_votes_to_account -= additional_votes_needed;
        }

        // If there are no more votes left to distribute and the candidate cannot guarantee the M-th place
        if (remaining_votes_to_account < 0 && i + m >= n) {
            required_votes[i] = -1;
        }
    }

    for (ll vote : required_votes) {
        cout << vote << " ";
    }
    cout << endl;

    return 0;
}