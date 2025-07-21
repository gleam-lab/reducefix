#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const vector<Candidate>& candidates, const vector<long long>& prefixSum, int m, int i, long long x) {
    int n = candidates.size();
    int needed = 0;
    
    // Count the number of candidates that can potentially win with the current candidate getting `x` more votes
    for (int j = 0; j < n; ++j) {
        if (j != i && candidates[j].votes + x <= candidates[i].votes) {
            ++needed;
        }
    }
    
    // Check if there are at least M candidates that cannot beat the current candidate even with the added votes
    return needed >= m;
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
    
    // Sort candidates based on votes
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });
    
    // Calculate prefix sum of votes
    vector<long long> prefixSum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + candidates[i].votes;
    }
    
    vector<long long> result(n, -1);
    
    // For each candidate, determine the minimum additional votes required to ensure victory
    for (int i = 0; i < n; ++i) {
        if (canWin(candidates, prefixSum, m, i, 0)) {
            result[i] = 0;
            continue;
        }
        
        long long left = 0, right = k;
        while (left < right) {
            long long mid = (left + right) / 2;
            if (canWin(candidates, prefixSum, m, i, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        result[i] = left;
    }
    
    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}