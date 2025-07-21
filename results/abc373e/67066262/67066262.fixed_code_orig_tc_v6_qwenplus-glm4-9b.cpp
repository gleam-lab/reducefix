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
    vector<ll> a(n, 0);
    k -= accumulate(a.begin(), a.end(), 0LL); // subtract already counted votes from total votes k

    // Sort candidates by the votes they have received
    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> votes_needed(n, -1);
    vector<ll> votes_highest_competition(n, -1);
    int count_votes_needed = 0;

    // Calculate additional votes needed for each candidate to be certain to win
    for (int i = 0; i < n; ++i) {
        if (i + 1 >= m) {
            break; // This candidate is in the top M already, does not need additional votes
        }
        // Calculate votes needed to surpass all candidates with more votes than current one
        votes_needed[i] = accumulate(a.begin() + i, a.begin() + m, 0LL);
        count_votes_needed += votes_needed[i];
    }

    // Check if the remaining votes are sufficient for the votes_needed for the other candidates
    ll min_votes_needed = count_votes_needed;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0 && votes_needed[i] != -1) {
            votes_highest_competition[i] = votes_needed[i] - a[i];
            min_votes_needed = min(min_votes_needed, votes_highest_competition[i]);
        }
    }

    // Output the result
    for (int i = 0; i < n; ++i) {
        if (min_votes_needed == -1) {
            // If no votes are needed, candidate already has a guarantee of victory
            cout << 0 << " ";
        } else if (a[i] > 0 && votes_needed[i] != -1) {
            // If votes_needed is less than the highest competition vote needed, it's guaranteed to win
            cout << (votes_needed[i] > votes_highest_competition[i] ? 0 : votes_highest_competition[i] - votes_needed[i]) << " ";
        } else {
            // If votes_needed is higher than the highest competition vote needed, cannot guarantee victory
            cout << -1 << " ";
        }
    }
    return 0;
}