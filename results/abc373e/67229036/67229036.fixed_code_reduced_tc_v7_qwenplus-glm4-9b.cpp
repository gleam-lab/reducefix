#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int a[N], c[N], prefixSum[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        c[i] = a[i];
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    
    // Sort candidates based on their current votes
    sort(a + 1, a + n + 1);
    
    // Process each candidate
    for (int i = 1; i <= n; ++i) {
        // The number of votes needed to guarantee the candidate is not among top M
        int votesNeeded = 0;
        
        // Calculate the cumulative sums up to the top M-1 candidates
        for (int j = n; j >= m; --j) {
            // The total votes beyond the top M-1 candidates
            long long remainingVotes = prefixSum[n] - prefixSum[j - 1];
            
            // The number of votes the current candidate needs to be in the top M-1
            long long requiredVotes = (k - prefixSum[j - 1] - m * a[j]) - (prefixSum[j - 1] - prefixSum[j - 1 - m]);
            
            // If the candidate can be in the top M-1 without exceeding the remaining votes
            if (requiredVotes <= remainingVotes) {
                votesNeeded = requiredVotes;
                break;
            }
        }
        
        // If the votes needed are zero or negative, the candidate is already guaranteed to win
        if (votesNeeded <= 0) {
            cout << votesNeeded << " ";
        } else {
            // Otherwise, the candidate can't secure a win
            cout << -1 << " ";
        }
    }
    
    return 0;
}