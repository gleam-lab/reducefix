#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> A(n);
    ll total_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        total_votes += A[i];
    }
    ll remaining_votes = k - total_votes;
    
    vector<pair<ll, int>> votes Candidates(n);
    for (int i = 0; i < n; ++i) {
        votes[i] = {A[i], i};
    }
    sort(votes.begin(), votes.end());
    
    vector<ll> prefix_sum(n);
    prefix_sum[0] = votes[0].first;
    for (int i = 1; i < n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + votes[i].first;
    }
    
    vector<ll> required_votes(n, -1);
    for (int i = 0; i < n; ++i) {
        ll votes_needed = 0;
        bool possible = true;
        
        for (int j = i; j >= 0 && possible; --j) {
            if (j == 0) {
                votes_needed = m - 1; // Candidate has no one below them.
            } else {
                ll votes_above = prefix_sum[n - 1] - prefix_sum[j];
                votes_needed = m - votes_above;
                if (votes_above >= m) {
                    possible = false;
                }
            }
            
            if (votes_needed <= remaining_votes) {
                ll remaining = remaining_votes - votes_needed;
                if (j < n - 1) remaining += j; // Additional votes needed if not the last one.
                
                required_votes[votes[j].second] = votes_needed - remaining;
                remaining_votes -= remaining;
                break;
            }
        }
        
        if (!possible) {
            required_votes[votes[i].second] = -1;
        }
    }
    
    for (auto &vote : required_votes) {
        cout << vote << " ";
    }
    cout << "\n";
    return 0;
}