#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using ll = long long;

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<ll> votes(n);
    for (ll &v : votes) {
        std::cin >> v;
    }

    // Calculate the number of remaining votes
    ll remaining_votes = k - std::accumulate(votes.begin(), votes.end(), 0LL);

    // Prepare for binary search
    std::vector<ll> sorted_votes = votes;
    std::sort(sorted_votes.begin(), sorted_votes.end());

    std::vector<ll> min_votes_needed(n, std::numeric_limits<ll>::max());

    // Iterate over each candidate
    for (int i = 0; i < n; ++i) {
        // Binary search to find the minimum votes needed
        ll left = 0, right = remaining_votes + 1;
        while (left + 1 < right) {
            ll mid = left + (right - left) / 2;
            // Calculate the number of candidates who could potentially vote for candidate i
            ll votes_above = 0;
            for (int j = 0; j < m; ++j) {
                votes_above += votes[j] + mid - sorted_votes[j] - 1;
            }
            // Update the left and right boundaries
            if (votes_above < m) {
                left = mid;
            } else {
                right = mid;
            }
        }

        // Check the correctness of the found number of votes
        ll votes_needed = left;
        ll votes_above = 0;
        for (int j = 0; j < m; ++j) {
            votes_above += votes[j] + votes_needed - sorted_votes[j];
        }
        if (votes_above >= m) {
            min_votes_needed[i] = votes_needed;
        } else {
            min_votes_needed[i] = -1; // This candidate cannot secure the victory
        }
    }

    // Output the results
    for (const ll &v : min_votes_needed) {
        if (v == std::numeric_limits<ll>::max()) {
            std::cout << -1 << " ";
        } else {
            std::cout << v << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}