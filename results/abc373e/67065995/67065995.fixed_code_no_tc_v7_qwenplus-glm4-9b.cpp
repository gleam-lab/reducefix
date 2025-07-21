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
    
    // Sort candidates by the votes they have received
    vector<pair<ll, int>> indexed_a(n);
    for (int i = 0; i < n; i++) {
        indexed_a[i] = {a[i], i};
    }
    sort(indexed_a.begin(), indexed_a.end());
    
    // Calculate votes left to distribute
    ll votes_left = K - accumulate(all(a), 0LL);
    
    // Calculate votes needed for each position to win
    vector<ll> votes_needed(n, 0);
    ll current_votes = 0;
    for (int i = 0; i < n; i++) {
        current_votes += indexed_a[i].first;
        votes_needed[i] = m * indexed_a[i].first - current_votes - (n - m);
        votes_needed[i] = votes_needed[i] < 0 ? 0 : votes_needed[i];
    }
    
    // Adjust votes_needed based on the remaining votes to ensure they can win
    ll remaining_votes = votes_left - accumulate(all(votes_needed), 0LL);
    for (int i = n - 1; i >= 0; i--) {
        if (votes_needed[i] + remaining_votes < m * indexed_a[i].first - current_votes - (n - m)) {
            votes_needed[i] -= m * indexed_a[i].first - current_votes - (n - m);
        } else {
            votes_needed[i] = 0;
        }
        current_votes -= indexed_a[i].first;
    }
    
    // Output the result
    for (int i = 0; i < n; i++) {
        if (votes_needed[i] < m * indexed_a[i].first - current_votes - (n - m)) {
            votes_needed[i] = -1;
        }
        cout << votes_needed[i] << " ";
    }
    cout << endl;
    return 0;
}