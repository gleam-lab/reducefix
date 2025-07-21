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
    ios_base::sync_with_stdio(false);
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

    vector<ll> prefix_sum(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].votes;
    }

    ll total_remaining = K - prefix_sum[N];

    vector<ll> result(N);
    
    for (ll i = 0; i < N; ++i) {
        ll left = 0;
        ll right = total_remaining;
        ll answer = -1;

        while (left <= right) {
            ll mid = (left + right) / 2;
            ll x_votes = candidates[i].votes + mid;

            // Find how many candidates have strictly more votes than x_votes
            ll low = 0;
            ll high = N;
            while (low < high) {
                ll mid_idx = (low + high) / 2;
                if (candidates[mid_idx].votes > x_votes)
                    high = mid_idx;
                else
                    low = mid_idx + 1;
            }

            ll num_strictly_higher = N - low;

            // We need at least (M) candidates with strictly more votes to prevent election
            // If fewer than M have more votes, the candidate is elected
            if (num_strictly_higher < M) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (answer == 0) {
            result[candidates[i].index] = 0;
        } else if (answer == -1) {
            result[candidates[i].index] = -1;
        } else {
            result[candidates[i].index] = answer;
        }
    }

    for (ll i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}