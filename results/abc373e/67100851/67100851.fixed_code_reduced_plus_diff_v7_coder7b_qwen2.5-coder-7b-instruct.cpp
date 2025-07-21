#include <iostream>
#include <vector>
#include <algorithm>

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const std::vector<Candidate>& candidates, int i, long long additionalVotes, int M) {
    int count = 0;
    for (const auto& c : candidates) {
        if (c.votes + additionalVotes > candidates[i].votes) {
            count++;
        }
        if (count >= M) break;
    }
    return count < M;
}

int main() {
    int N, M;
    long long K;
    std::cin >> N >> M >> K;
    
    std::vector<Candidate> candidates(N);
    long long totalVotes = 0;
    for (int i = 0; i < N; ++i) {
        std::cin >> candidates[i].votes;
        candidates[i].index = i;
        totalVotes += candidates[i].votes;
    }
    
    // Sort candidates based on their current vote counts
    std::sort(candidates.begin(), candidates.end(),
              [](const Candidate& a, const Candidate& b) { return a.votes < b.votes; });
    
    std::vector<long long> results(N, -1);
    long long remainingVotes = K - totalVotes;
    
    for (int i = 0; i < N; ++i) {
        if (remainingVotes == 0) break;
        
        // Binary search to find the minimum additional votes needed
        long long left = 0, right = remainingVotes;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (canWin(candidates, i, mid, M)) {
                results[candidates[i].index] = mid;
                remainingVotes -= mid;
                break;
            } else {
                left = mid + 1;
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        std::cout << results[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}