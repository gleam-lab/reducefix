#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int index;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<Candidate> candidates(N);
    for (ll i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }

    // Sort candidates by current votes
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes < b.votes;
    });

    // Prefix sum of current votes
    vector<ll> prefix_sum(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].votes;
    }

    ll total_remaining = K - prefix_sum[N];
    vector<ll> result(N);

    auto is_valid = [&](ll idx, ll needed_votes) {
        ll base = candidates[idx].votes + needed_votes;
        
        // Binary search to find how many candidates have votes > base
        ll low = 0, high = N;
        while (low < high) {
            ll mid = (low + high) / 2;
            if (candidates[mid].votes <= base)
                low = mid + 1;
            else
                high = mid;
        }
        ll stronger_count = N - low;

        // If already more than M candidates have more votes -> impossible
        if (stronger_count >= M) return false;

        // Need to ensure at most M-1 candidates have more votes than this one
        ll target_stronger = M - 1;
        if (stronger_count > target_stronger) return false;

        // We need to increase this candidate's votes so that at most M-1 others can be higher
        // Consider the top M candidates it needs to beat
        ll l = idx, r = N - 1;
        ll left = 0, right = N - idx;
        while (left < right) {
            ll mid = (left + right) / 2;
            ll pos = idx + mid;
            ll cnt = N - pos;
            ll required = (mid + 1) * (base + 1) - (prefix_sum[pos + 1] - prefix_sum[idx]);
            
            if (cnt <= target_stronger) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Find minimum required votes among valid positions
        ll min_required = 1e18;
        for (ll i = max(idx, idx + left - 1); i <= min(N - 1, idx + left + 1); ++i) {
            if (i < idx) continue;
            ll pos = i;
            ll cnt = N - pos;
            if (cnt > target_stronger) continue;
            
            ll required = (pos - idx + 1) * (base + 1) - (prefix_sum[pos + 1] - prefix_sum[idx]);
            if (required <= total_remaining - needed_votes) {
                return true;
            }
        }

        return false;
    };

    for (ll i = 0; i < N; ++i) {
        if (is_valid(i, 0)) {
            result[candidates[i].index] = 0;
            continue;
        }

        if (!is_valid(i, total_remaining)) {
            result[candidates[i].index] = -1;
            continue;
        }

        ll lo = 0, hi = total_remaining;
        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            if (is_valid(i, mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        result[candidates[i].index] = hi;
    }

    for (ll i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}