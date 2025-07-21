#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

// Function to check if a candidate can win with `x` additional votes
bool canWin(const vector<Candidate>& candidates, int m, long long x, int i) {
    int count = 0;
    long long sum = 0;
    
    // Iterate over all candidates except the one we're checking
    for (int j = 0; j < candidates.size(); ++j) {
        if (j != i) {
            if (candidates[j].votes + x > candidates[i].votes) {
                count++;
            } else {
                sum += candidates[j].votes + x;
            }
        }
    }
    
    // Check if the current candidate can still win
    if (count >= m) return false;
    
    // Calculate the total votes needed to surpass the highest ranked losing candidate
    long long target = sum / (m - count - 1);
    return candidates[i].votes + x > target;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }
    
    // Sort candidates by votes
    sort(candidates.begin(), candidates.end());
    
    vector<long long> results(n, -1); // Initialize results with -1
    
    for (int i = 0; i < n; ++i) {
        long long lo = 0, hi = k - accumulate(candidates.begin(), candidates.end(), 0LL);
        
        while (hi - lo > 1) {
            long long mid = (lo + hi) / 2;
            if (canWin(candidates, m, mid, i)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        if (canWin(candidates, m, lo, i)) {
            results[candidates[i].index] = lo;
        } else if (canWin(candidates, m, hi, i)) {
            results[candidates[i].index] = hi;
        }
    }
    
    // Print results
    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    
    return 0;
}