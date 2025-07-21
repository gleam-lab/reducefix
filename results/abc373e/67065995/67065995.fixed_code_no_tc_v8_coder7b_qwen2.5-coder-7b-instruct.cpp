#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    
    // Calculate the maximum votes needed for a candidate to win
    vector<ll> max_votes_needed(n, -1);
    for(int i = 0; i < n; ++i) {
        ll remaining = k - a[i];
        if(remaining < 0) continue;
        
        ll total_votes_if_i_wins = 0;
        for(int j = 0; j < n; ++j) {
            if(j != i) {
                total_votes_if_i_wins += a[j];
            }
        }
        
        if(total_votes_if_i_wins < remaining) {
            max_votes_needed[i] = remaining - total_votes_if_i_wins;
        }
    }
    
    // Adjust for candidates who can already win or cannot win
    for(int i = 0; i < n; ++i) {
        if(a[i] > k / (n - m)) {
            max_votes_needed[i] = 0;
        } else if(max_votes_needed[i] > k) {
            max_votes_needed[i] = -1;
        }
    }
    
    // Output the results
    for(int i = 0; i < n; ++i) {
        cout << max_votes_needed[i] << " ";
    }
    cout << endl;
    
    return 0;
}