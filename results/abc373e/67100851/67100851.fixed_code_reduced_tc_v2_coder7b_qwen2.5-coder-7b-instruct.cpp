#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, long long K, int M, int i, long long x) {
    candidates[i].votes += x;
    sort(candidates.begin(), candidates.end());
    
    // Calculate the number of candidates with more votes than candidate i
    int count = 0;
    for (int j = 0; j < candidates.size(); ++j) {
        if (candidates[j].votes > candidates[i].votes) {
            count++;
        } else if (candidates[j].votes == candidates[i].votes) {
            break;
        }
    }
    
    // Check if the number of such candidates is less than M
    bool result = count < M;
    
    // Revert the vote change
    candidates[i].votes -= x;
    sort(candidates.begin(), candidates.end());
    
    return result;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;
    
    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }
    
    vector<long long> results(N, -1); // Initialize results as -1
    
    // Sort candidates by their current votes
    sort(candidates.begin(), candidates.end());
    
    // Iterate over each candidate to determine the minimum additional votes needed
    for (int i = 0; i < N; ++i) {
        if (canWin(candidates, K, M, i, 0)) {
            results[i] = 0;
            continue;
        }
        
        long long lo = 0, hi = K;
        while (hi - lo > 1) {
            long long mid = (lo + hi) / 2;
            if (canWin(candidates, K, M, i, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        if (hi > lo && canWin(candidates, K, M, i, hi - 1)) {
            hi--;
        }
        
        results[i] = hi;
    }
    
    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    
    return 0;
}