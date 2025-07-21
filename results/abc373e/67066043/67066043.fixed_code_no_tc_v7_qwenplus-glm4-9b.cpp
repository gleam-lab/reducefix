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
    
    // Sort candidates based on the votes they have received
    sort(a.begin(), a.end());
    
    // Calculate remaining votes to be distributed
    ll remaining_votes = k;
    
    // Iterate over candidates who are not in the top m positions
    vector<ll> additional_votes_needed(n, 0);
    for (int i = m; i < n; i++) {
        // Find the candidate just above or at this candidate in the sorted order
        int higher_cand_index = upper_bound(a.begin(), a.begin() + i, a[i]) - a.begin();
        int lower_cand_index = i - (higher_cand_index - i == 0);
        
        // Calculate the minimum votes needed for this candidate to be in the top m
        ll votes_needed = m + 1 - higher_cand_index + a[m - 1] - a[i];
        
        // Check if this candidate can secure victory with the remaining votes
        if (votes_needed > remaining_votes) {
            additional_votes_needed[i] = -1;
        } else {
            additional_votes_needed[i] = votes_needed;
            remaining_votes -= votes_needed;
        }
    }
    
    // Output the result for each candidate
    for (int i = 0; i < n; i++) {
        if (i < m) {
            additional_votes_needed[i] = 0; // Already in the top m
        }
        cout << additional_votes_needed[i] << ' ';
    }
    cout << '\n';
}