#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<pair<ll, int>> candidates(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].first;
        candidates[i].second = i;
    }
    
    // Sort candidates based on the number of votes they have received
    sort(candidates.begin(), candidates.end());
    
    // Compute the prefix sum of votes
    vector<ll> prefix_sum(N);
    prefix_sum[0] = candidates[0].first;
    for (int i = 1; i < N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + candidates[i].first;
    }
    
    // We need to find the minimum additional votes required for each candidate
    vector<ll> result(N, -1);
    
    for (int i = 0; i < N; ++i) {
        int votes_needed = K - prefix_sum[N - 1];
        int ahead = N - M - 1;
        
        if (i > ahead) {
            // If the candidate is already ahead of the number needed to win
            result[candidates[i].second] = 0;
            continue;
        }
        
        // Binary search for the minimum votes needed
        int low = 0, high = K;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            ll additional_votes = mid;
            ll current_votes = candidates[i].first + additional_votes;
            
            ll sum_needed = 0;
            for (int j = i + 1; j <= ahead; ++j) {
                sum_needed += (j - (i + 1)) * (current_votes + 1);
            }
            
            if (sum_needed <= votes_needed) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        
        result[candidates[i].second] = low;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
    
    return 0;
}