#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define all(v) v.begin(), v.end()
#define sz(v) ((ll)(v.size()))

template<typename T>
inline bool chmin(T &a, const T &b) {
    if (b < a) { return a = b, true; }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    
    vector<ll> A(N);
    ll total_A = 0;
    for (auto &x : A) {
        cin >> x;
        total_A += x;
    }

    ll remaining_votes = K - total_A;
    if (remaining_votes < 0) {
        // This should not happen per problem statement, but handle it anyway
        cout << string(N, ' ') << endl;
        return 0;
    }

    // Create a list of (original_index, votes)
    vector<pll> candidates;
    for (ll i = 0; i < N; ++i) {
        candidates.emplace_back(i, A[i]);
    }

    // Sort by vote count descending
    sort(candidates.rbegin(), candidates.rend(), [](const pll &a, const pll &b) {
        return a.second < b.second;
    });

    // prefix sums of sorted votes
    vector<ll> prefix_sum(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].second;
    }

    vector<ll> result(N, -1); // Default: impossible

    // For each candidate, determine the minimum additional votes needed to guarantee victory
    for (ll idx = 0; idx < N; ++idx) {
        auto [original_idx, current_votes] = candidates[idx];

        // Binary search on additional votes needed
        ll low = 0, high = remaining_votes;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll extended_votes = current_votes + mid;

            // Find how many candidates have strictly more votes than us after adding votes
            ll strict_superior_count = 0;
            ll left = 0, right = N;
            while (left < right) {
                ll m = (left + right) / 2;
                if (A[m] > extended_votes) left = m + 1;
                else right = m;
            }
            strict_superior_count = left;

            // Determine how many other candidates can be kept above us
            ll available_other_votes = remaining_votes - mid;

            ll needed_to_block = M - 1;
            if (strict_superior_count >= needed_to_block) {
                // Already enough candidates ahead of us to block election
                low = mid + 1;
                continue;
            }

            ll remaining_to_block = needed_to_block - strict_superior_count;
            ll start_idx = strict_superior_count;
            ll end_idx = min(N, start_idx + remaining_to_block);

            ll required_votes = 0;
            for (ll i = start_idx; i < end_idx; ++i) {
                required_votes += max(0LL, A[i] - extended_votes + 1);
            }

            if (available_other_votes >= required_votes) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (answer == -1 && remaining_votes >= 0) {
            // Check if already elected without any additional votes
            ll superior_count = 0;
            ll start_idx = 0, end_idx = N;
            while (start_idx < end_idx) {
                ll m = (start_idx + end_idx) / 2;
                if (A[m] > current_votes) start_idx = m + 1;
                else end_idx = m;
            }
            superior_count = start_idx;

            if (superior_count < M) {
                answer = 0;
            }
        }

        result[original_idx] = answer;
    }

    for (auto x : result) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}