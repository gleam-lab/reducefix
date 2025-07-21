#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    long long a;
    int idx;
} node;

int N, M, K;
long long Psum[200001];

vector<pair<int, int>> candidates; // Pair of (remaining_votes, candidate_index)
vector<pair<long long, pair<int, int>>> needed_votes; // Pair of (current_votes, {- needed votes, candidate_index})

long long upper_bound(const vector<pair<int, int>>& vec, int votes) {
    int start = 0, end = vec.size();
    while (start < end) {
        int mid = (start + end) / 2;
        if (vec[mid].first <= votes)
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}

int main() {
    scanf("%d %d %lld", &N, &M, &K);
    for (int i = 0; i < N; ++i) {
        long long votes;
        scanf("%lld", &votes);
        Psum[i + 1] = Psum[i] + votes;
        candidates.emplace_back(K - Psum[i] - votes, i);
    }

    sort(candidates.begin(), candidates.end());

    for (int i = 0; i < N; ++i) {
        int votes_needed = M - i - 1;
        long long current_votes = K - Psum[N];
        if (votes_needed > current_votes) {
            needed_votes.emplace_back(-1, {i, votes_needed});
            continue;
        }
        needed_votes.emplace_back(current_votes, {i, votes_needed});
    }

    sort(needed_votes.begin(), needed_votes.end());

    for (int i = 0; i < N; ++i) {
        if (needed_votes[i].first == -1) {
            printf("-1 ");
            continue;
        }

        long long votes_needed = needed_votes[i].second.first;
        int candidate = needed_votes[i].second.second;
        long long lo = 0, hi = N, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            long long extra_votes = Psum[mid] - Psum[N];
            long long max_votes = extra_votes + candidates[mid].first;
            if (max_votes - votes_needed >= candidates[candidate].first)
                hi = mid;
            else
                lo = mid + 1;
        }

        if (hi == N || candidates[hi].first + (hi - candidate) * (votes_needed + 1) < candidates[candidate].first + votes_needed)
            printf("-1 ");
        else
            printf("%lld ", votes_needed);
    }
    printf("\n");
}