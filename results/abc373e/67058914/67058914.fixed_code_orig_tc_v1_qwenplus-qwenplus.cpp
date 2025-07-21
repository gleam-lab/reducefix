#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Candidate {
    ll votes;
    int index;
};

bool compare(const Candidate &a, const Candidate &b) {
    return a.votes < b.b;
}

int main() {
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }

    // Sort by current votes
    sort(candidates.begin(), candidates.end(), compare);

    // Compute prefix sums of the sorted votes
    vector<ll> prefix_sum(N + 1, 0LL);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].votes;
    }

    ll total_votes_given = prefix_sum[N];
    ll remaining_votes = K - total_votes_given;

    vector<ll> result(N);

    // For each candidate, binary search on minimum needed additional votes
    for (int i = 0; i < N; ++i) {
        int original_index = candidates[i].index;

        ll low = 0;
        ll high = remaining_votes;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll current_total = candidates[i].votes + mid;

            // We want to find how many candidates have votes > current_total
            // This is done via binary search in the sorted list
            int pos = upper_bound(candidates.begin(), candidates.end(), Candidate{current_total, -1}, compare) - candidates.begin();

            int required_more_votes = M - (N - pos);

            if (required_more_votes <= 0) {
                // Already enough even without further allocation
                answer = mid;
                high = mid - 1;
            } else {
                // Need to boost at least "required_more_votes" other candidates to >= current_total
                // Calculate minimal required votes using greedy or binary search

                // Binary search over top (pos) candidates
                int left = 0;
                int right = pos;
                int boosted = 0;

                while (left < right) {
                    int middle = (left + right) / 2;
                    ll need = current_total * (pos - middle) - (prefix_sum[pos] - prefix_sum[middle]);
                    if (need <= remaining_votes - mid) {
                        boosted = pos - middle;
                        right = middle;
                    } else {
                        left = middle + 1;
                    }
                }

                if ((N - pos + boosted) >= M) {
                    answer = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        result[original_index] = (answer != -1) ? answer : -1;
    }

    // Output results in original order
    for (int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }

    return 0;
}