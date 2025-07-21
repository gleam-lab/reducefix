#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M, K;
    std::cin >> N >> M >> K;
    
    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        K -= A[i];
    }

    std::vector<std::pair<long long, int>> B(N); // pair<votes, index>
    std::vector<long long> prefix(N + 1, 0);
    
    // Populate B with votes and original indices
    for (int i = 0; i < N; ++i) {
        B[i] = {A[i], i};
    }
    
    // Sort B based on votes
    std::sort(B.begin(), B.end());
    
    // Calculate prefix sums for sorted votes
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + B[i - 1].first;
    }

    std::vector<long long> result(N, -1); // Default result: cannot guarantee win

    // Iterate over sorted votes to calculate required votes
    for (int i = 0; i < N; ++i) {
        int j = i + 1; // The candidate below in sorted order
        long long votes_needed = std::abs(prefix[N] - prefix[j]) - B[i].first + 1;

        // Check if votes_needed is feasible with remaining votes K
        if (votes_needed <= K) {
            result[B[i].second] = votes_needed;
        }
    }

    // Output the results
    for (long long v : result) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}