#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
using ll = long long;

struct Node {
    ll val;
    int idx;
};

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Node> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i].val;
        a[i].idx = i;
    }

    // Sort candidates based on the current number of votes in ascending order
    sort(a.begin() + 1, a.begin() + N + 1, [](const Node &A, const Node &B) -> bool {
        return A.val < B.val;
    });

    // Precompute the prefix sums of votes
    vector<ll> prefix_sum(N + 1);
    prefix_sum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i].val;
    }

    // Calculate the remaining votes after current counts
    K -= prefix_sum[N];

    vector<ll> votes_needed(N + 1, numeric_limits<ll>::max());

    // Iterate over each candidate starting from the one with the highest votes
    for (int i = N; i >= 1; --i) {
        // Current votes and the remaining votes needed to surpass the current candidate
        ll current_votes = a[i].val;
        ll needed_to_surpass = M - 1; // We subtract 1 because we need at least as many as the one before us

        // Calculate the maximum votes the next M-1 candidates can have together
        ll upper_bound_votes = (N - i >= M - 1) ? prefix_sum[N] - prefix_sum[N - M + 1] : 0;

        // Calculate the minimum votes needed for the current candidate to guarantee victory
        ll votes_needed_for_victory = current_votes + needed_to_surpass - upper_bound_votes;

        // Check if the remaining votes are enough or more than the maximum votes needed to surpass the current candidate
        if (votes_needed_for_victory > K) {
            votes_needed[i] = -1; // Cannot guarantee victory
        } else {
            votes_needed[i] = votes_needed_for_victory - current_votes;
        }
    }

    // Output the result
    for (int i = 1; i <= N; ++i) {
        cout << (votes_needed[i] == numeric_limits<ll>::max() ? -1 : votes_needed[i]) << " ";
    }
    cout << endl;

    return 0;
}