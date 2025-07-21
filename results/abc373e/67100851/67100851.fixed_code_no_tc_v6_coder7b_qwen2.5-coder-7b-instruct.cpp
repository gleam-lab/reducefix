#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const vector<Candidate>& candidates, int M, long long K, int targetIndex, long long additionalVotes) {
    vector<long long> voteCounts(candidates.size());
    for (size_t i = 0; i < candidates.size(); ++i) {
        voteCounts[i] = candidates[i].votes + (i == targetIndex ? additionalVotes : 0);
    }
    
    sort(voteCounts.begin(), voteCounts.end());
    int validCandidates = 0;
    for (int i = 0; i < candidates.size() - M; ++i) {
        if (voteCounts[i] > voteCounts[candidates.size() - M]) {
            validCandidates++;
        } else {
            break;
        }
    }
    
    return validCandidates >= M;
}

vector<long long> minAdditionalVotes(vector<Candidate>& candidates, int M, long long K) {
    vector<long long> results(candidates.size(), 0);
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) { return a.votes < b.votes; });
    
    for (size_t i = 0; i < candidates.size(); ++i) {
        if (canWin(candidates, M, K, i, 0)) {
            results[i] = 0;
        } else {
            long long low = 0, high = LLONG_MAX;
            while (low < high) {
                long long mid = low + (high - low) / 2;
                if (canWin(candidates, M, K, i, mid)) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            results[i] = low;
        }
    }
    
    return results;
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
    
    vector<long long> results = minAdditionalVotes(candidates, M, K);
    
    for (long long result : results) {
        cout << result << " ";
    }
    cout << endl;
    
    return 0;
}