#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, int M, long long K, int i, long long additionalVotes) {
    // Calculate the maximum votes any candidate can get without losing
    long long maxPossibleVotes = candidates.back().votes + additionalVotes;
    
    // Remove the candidate we're checking from consideration
    candidates.pop_back();
    
    // Sort the remaining candidates by votes in descending order
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });
    
    // Count how many candidates have more votes than the one we're checking
    int count = 0;
    for (size_t j = 0; j < candidates.size(); ++j) {
        if (candidates[j].votes > maxPossibleVotes) {
            count++;
        } else {
            break;
        }
    }
    
    // Restore the candidate to its original position
    candidates.push_back({maxPossibleVotes, i});
    
    // Return true if the count is less than M
    return count < M;
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
    
    // Sort candidates by votes in ascending order
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes < b.votes;
    });
    
    vector<long long> results(N, -1);
    
    for (int i = 0; i < N; ++i) {
        long long minAdditionalVotes = 0;
        
        // Binary search for the minimum additional votes needed
        long long left = 0, right = K;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canWin(candidates, M, K, i, mid)) {
                minAdditionalVotes = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        results[candidates[i].index] = minAdditionalVotes;
    }
    
    for (long long result : results) {
        cout << result << " ";
    }
    cout << endl;
    
    return 0;
}