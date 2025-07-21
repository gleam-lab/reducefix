#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int index;
};

bool compareByVotes(const Candidate &a, const Candidate &b) {
    return a.votes < b.votes;
}

bool canGuaranteeVictory(int i, ll additional, const vector<Candidate> &sorted, const vector<ll> &prefixSum, ll remaining) {
    ll total = sorted[i].votes + additional;
    
    // Find how many candidates have strictly more votes than us
    Candidate tmp = {total, -1};
    int pos = upper_bound(sorted.begin(), sorted.end(), tmp, compareByVotes) - sorted.begin();
    
    // We need to be in top M => at most M-1 candidates should have more votes
    // So we must ensure that even after distributing remaining votes among others,
    // at least (N - M) candidates cannot surpass us.
    int max_candidates_above = N - M;
    
    if (pos <= max_candidates_above) {
        return false; // Too many candidates above us already
    }
    
    // Calculate minimum required votes to block (pos - max_candidates_above) candidates
    int l = max(max_candidates_above, 0);
    ll needed = (total + 1) * (pos - l) - (prefixSum[pos] - prefixSum[l]);
    
    // If candidate i was originally beyond l, subtract their own added votes from requirement
    if (i > l) {
        needed -= additional + 1;
    }
    
    return needed <= remaining - additional;
}

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    
    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }
    
    // Sort candidates by current votes
    sort(candidates.begin(), candidates.end(), compareByVotes);
    
    vector<ll> prefixSum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + candidates[i].votes;
    }
    
    ll totalCurrent = prefixSum[N];
    ll remaining = K - totalCurrent;
    
    vector<ll> result(N);
    
    for (int i = 0; i < N; ++i) {
        // Already enough?
        if (canGuaranteeVictory(i, 0, candidates, prefixSum, remaining)) {
            result[candidates[i].index] = 0;
            continue;
        }
        
        if (remaining == 0) {
            result[candidates[i].index] = -1;
            continue;
        }
        
        ll low = 0, high = remaining;
        ll answer = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (canGuaranteeVictory(i, mid, candidates, prefixSum, remaining)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        result[candidates[i].index] = (answer == -1) ? -1 : answer;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}