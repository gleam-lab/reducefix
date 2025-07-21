#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> votes(n);
    long long total_votes = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
        total_votes += votes[i];
    }
    
    vector<pair<long long, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {votes[i], i};
    }
    
    sort(candidates.begin(), candidates.end(), greater<pair<long long, int>>());
    
    vector<long long> required_votes(n);
    
    for (int i = 0; i < n; ++i) {
        if (i < m - 1) {
            required_votes[candidates[i].second] = 0;  // Already guaranteed to win
        } else {
            // Calculate votes needed to ensure more votes than (m-1)th candidate
            required_votes[candidates[i].second] = max(0LL, (long long)(m - 1) * (candidates[m-1].first + 1) - votes[candidates[i].second]);
        }
    }
    
    // Calculate the remaining votes after current vote counts
    long long remaining_votes = k - total_votes;
    
    // Adjust votes needed based on remaining votes
    for (int i = 0; i < n; ++i) {
        if (required_votes[candidates[i].second] == 0) continue;
        
        // Calculate the minimum votes needed to guarantee victory
        int next_greater = upper_bound(votes.begin(), votes.begin() + n, candidates[i].first) - votes.begin();
        int max_m_minus_1 = min(m - 1, n);
        
        // Calculate votes needed to ensure victory over the (max_m_minus_1)th candidate
        long long votes_needed = max_m_minus_1 * (candidates[max_m_minus_1].first + 1) - votes[candidates[i].second];
        
        // Calculate the excess votes available
        long long excess_votes = remaining_votes - votes_needed;
        
        if (excess_votes >= required_votes[candidates[i].second]) {
            required_votes[candidates[i].second] = max(0LL, votes_needed - excess_votes);
        } else {
            required_votes[candidates[i].second] = 0;
        }
    }
    
    for (long long vote : required_votes) {
        cout << vote << " ";
    }
    
    return 0;
}