#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }
    
    // Sort votes in descending order
    sort(votes.rbegin(), votes.rend());
    
    // Calculate the minimum votes needed for each candidate
    vector<ll> min_votes_needed(n);
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            // Lead candidate, needs at least m-1 more to guarantee victory
            min_votes_needed[i] = max(0LL, votes[i] + m - 1 - votes[i + 1]);
        } else if (i < m - 1) {
            // Candidates not in the lead, need at least m votes to guarantee victory
            min_votes_needed[i] = max(0LL, votes[0] + m - 1 - votes[i]);
        } else {
            // Candidates who cannot guarantee victory
            min_votes_needed[i] = -1;
        }
    }
    
    // Output the result
    for (int i = 0; i < n; ++i) {
        cout << min_votes_needed[i] << " ";
    }
    cout << endl;
    
    return 0;
}