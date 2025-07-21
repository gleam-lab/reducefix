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
        k -= a[i];
    }
    
    // Sort the candidates by their votes
    sort(a.begin(), a.end());
    
    // Calculate the votes needed to surpass the top M candidates
    vector<ll> votes_needed(n);
    for (int i = 0; i < n; i++) {
        votes_needed[i] = a[n - 1 - i] - a[i] + 1;
    }
    
    // Sort the votes_needed for easy access
    sort(votes_needed.begin(), votes_needed.end());
    
    // Calculate the additional votes needed for each candidate
    vector<ll> additional_votes(n);
    for (int i = 0; i < n; i++) {
        // The minimum additional votes needed to guarantee victory
        ll min_votes_needed = votes_needed[m - 1] - a[i];
        
        // Ensure we do not exceed the remaining votes
        if (min_votes_needed > k) {
            additional_votes[i] = -1;
        } else {
            additional_votes[i] = min_votes_needed;
            k -= additional_votes[i];
        }
    }
    
    // Output the results
    for (ll additional_vote : additional_votes) {
        cout << additional_vote << ' ';
    }
    cout << '\n';
}