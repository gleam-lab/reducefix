#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n, m, k;
    vector<long long> votes;
    long long a;
    
    // Input reading
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        votes.push_back(a);
    }
    
    // Sort votes in descending order
    sort(votes.begin(), votes.end(), greater<long long>());
    
    // Calculate prefix sums of sorted votes
    vector<long long> prefixSum(n);
    prefixSum[0] = votes[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + votes[i];
    }
    
    // Find the minimum votes required for each candidate
    vector<long long> additionalVotes(n);
    for (int i = 0; i < n; ++i) {
        if (m > votes[i]) {
            // Candidate already guaranteed to win
            additionalVotes[i] = 0;
        } else if (m <= n - votes[i]) {
            // Candidate can win if the remaining votes are distributed such that they are the top m candidates
            long long remainingVotes = k - prefixSum[n - m - 1];
            long long targetVotes = prefixSum[n - m - 1] + votes[i];
            if (targetVotes <= remainingVotes) {
                additionalVotes[i] = 0;
            } else {
                // Binary search to find the minimum votes required
                long long left = 0, right = remainingVotes;
                while (left < right) {
                    long long mid = (left + right) / 2;
                    int pos = lower_bound(votes.begin() + n - m, votes.begin() + n, votes[i] + mid) - votes.begin();
                    long long actualVotes = prefixSum[n - m - 1] + votes[i] + mid - (pos > n - m ? mid : votes[i] + mid - prefixSum[pos]);
                    if (actualVotes > remainingVotes) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                additionalVotes[i] = left;
            }
        } else {
            // Candidate cannot win
            additionalVotes[i] = -1;
        }
    }
    
    // Output the result
    for (int i = 0; i < n; ++i) {
        cout << additionalVotes[i] << ' ';
    }
    cout << endl;
    
    return 0;
}