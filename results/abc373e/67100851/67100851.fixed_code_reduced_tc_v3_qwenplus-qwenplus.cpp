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
    vector<ll> A(N);

    for (ll i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
        A[i] = candidates[i].votes;
    }

    sort(A.begin(), A.end());
    vector<ll> prefix_sum(N + 1, 0);
    for (ll i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i - 1];
    }

    ll total_remaining_votes = K - prefix_sum[N];
    vector<ll> result(N);

    for (ll i = 0; i < N; ++i) {
        ll current_votes = candidates[i].votes;
        ll left = 0, right = total_remaining_votes;
        ll ans = -1;

        // Binary search on additional votes needed
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll new_vote_count = current_votes + mid;

            // Find how many candidates have strictly more votes than this candidate after getting `mid` votes
            ll l = 0, r = N;
            while (l < r) {
                ll m = (l + r) / 2;
                if (A[m] > new_vote_count)
                    r = m;
                else
                    l = m + 1;
            }

            ll num_strictly_higher = N - l;

            // We need at most M-1 candidates to have more votes than this one
            if (num_strictly_higher < M) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        result[candidates[i].index] = (ans == -1 ? -1 : ans);
    }

    for (ll i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}