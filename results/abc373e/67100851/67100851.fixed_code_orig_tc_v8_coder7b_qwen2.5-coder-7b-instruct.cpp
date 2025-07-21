#include <bits/stdc++.h>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool compare(Candidate a, Candidate b) {
    return a.votes > b.votes;
}

vector<long long> minAdditionalVotes(vector<int>& votes, int m, long long k) {
    int n = votes.size();
    vector<Candidate> candidates(n);
    
    // Initialize candidates with votes and indices
    for (int i = 0; i < n; ++i) {
        candidates[i] = {votes[i], i};
    }
    
    // Sort candidates based on votes in descending order
    sort(candidates.begin(), candidates.end(), compare);
    
    // Calculate prefix sum array for quick vote retrieval
    vector<long long> prefixSum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + candidates[i].votes;
    }
    
    vector<long long> result(n, 0);
    
    // Iterate over candidates and calculate minimum additional votes needed
    for (int i = 0; i < n; ++i) {
        int above = n - i - 1;
        
        if (above >= m) continue; // If enough candidates above current one
        
        long long required = 0;
        
        if (above > 0) {
            required += (prefixSum[n] - prefixSum[i]) - (m * (candidates[i].votes + 1));
        } else {
            required = (prefixSum[n] - prefixSum[i]) - (k - prefixSum[i]);
        }
        
        if (required <= 0) continue; // Already won
        
        result[candidates[i].index] = required;
    }
    
    return result;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    vector<int> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }
    
    vector<long long> result = minAdditionalVotes(votes, m, k);
    
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}