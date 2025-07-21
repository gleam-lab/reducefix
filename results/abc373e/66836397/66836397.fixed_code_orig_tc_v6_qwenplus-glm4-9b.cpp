#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    for (ll &v : a) cin >> v;

    // Sort candidates based on the number of votes they have received so far
    sort(a.begin(), a.end());

    vector<ll> additional_votes_needed(n, 0);

    // Calculate the total votes needed for the candidate to guarantee victory
    for (int i = 0; i < n; ++i) {
        ll current_votes = a[i];
        ll remaining_votes = K - accumulate(a.begin(), a.begin() + n, 0LL);
        ll additional_votes = 0;

        // Calculate the minimum additional votes needed
        if (i >= m - 1) {
            // More than m-1 candidates have more votes
            additional_votes = m * current_votes - accumulate(a.begin(), a.begin() + min(m, n), 0LL);
        } else {
            additional_votes = remaining_votes - current_votes;
        }

        // If additional_votes is negative, no more votes are needed
        if (additional_votes < 0) {
            additional_votes_needed[i] = 0;
        } else {
            additional_votes_needed[i] = additional_votes;
        }
    }

    // Output the result
    for (int i = 0; i < n; ++i) {
        cout << additional_votes_needed[i] << " ";
    }
    cout << endl;
}