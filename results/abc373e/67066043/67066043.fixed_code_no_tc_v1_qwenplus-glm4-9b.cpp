#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    // Sort candidates by their current votes
    sort(a.begin(), a.end());
    
    // Calculate the sum of current votes
    ll current_sum = 0;
    for (ll vote : a) {
        current_sum += vote;
    }
    
    // Calculate the votes needed to guarantee victory
    vector<ll> votes_needed(n, -1);
    for (int i = 0; i < n; i++) {
        if (m == 1) {
            // If only one candidate can be elected, they need all remaining votes
            votes_needed[i] = k - current_sum + a[i];
            if (votes_needed[i] < 0) votes_needed[i] = -1; // Not enough votes to guarantee victory
        } else {
            // Calculate votes needed to be ahead of the candidates with fewer votes
            ll votes_ahead = 0;
            for (int j = 0; j < i; j++) {
                votes_ahead += a[j] - a[i];
            }
            votes_needed[i] = votes_ahead + (m - 1) * (k - current_sum - votes_ahead - a[i]);
            if (votes_needed[i] < 0) votes_needed[i] = -1; // Not enough votes to guarantee victory
        }
    }
    
    // Output the result
    for (ll needed : votes_needed) {
        cout << needed << ' ';
    }
    cout << '\n';
    return 0;
}