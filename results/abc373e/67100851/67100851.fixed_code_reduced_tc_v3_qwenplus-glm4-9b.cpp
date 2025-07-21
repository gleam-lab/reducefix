#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int INF = 200000;
int N, M, K;
ll A[INF];
ll prefix_sum[INF];

bool canWinWithVotes(ll votes, int candidate_index) {
    ll current_votes = votes + A[candidate_index];
    ll more_votes = 0;
    // Count how many candidates have more votes than the current candidate
    for (int i = 0; i < N; ++i) {
        if (i == candidate_index) continue;
        more_votes += max(0LL, A[i] - current_votes);
    }
    return more_votes < M;
}

int main() {
    scanf("%d %d %lld", &N, &M, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i]);
    }

    // Compute prefix sums
    prefix_sum[0] = A[0];
    for (int i = 1; i < N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }

    vector<pair<ll, int>> candidates;
    for (int i = 0; i < N; ++i) {
        ll votes_needed = M - 1 - prefix_sum[i] + prefix_sum[N - 1];
        if (votes_needed <= K - (prefix_sum[N - 1] - prefix_sum[i])) {
            candidates.emplace_back(votes_needed, i);
        }
    }

    sort(candidates.begin(), candidates.end());

    for (auto& candidate : candidates) {
        int index = candidate.second;
        while (true) {
            if (canWinWithVotes(candidate.first, index)) {
                printf("%lld ", candidate.first);
                break;
            }
            candidate.first++;
            if (candidate.first > K) {
                candidate.first = -1;
                break;
            }
        }
    }

    while (N-- > candidates.size()) {
        printf("-1 ");
    }

    printf("\n");
    return 0;
}