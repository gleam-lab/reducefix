#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int idx;
};

bool compare(const Candidate &a, const Candidate &b) {
    return a.votes < b.votes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<Candidate> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i].votes;
        A[i].idx = i;
    }

    // Sort candidates by current votes
    sort(A.begin(), A.end(), compare);

    // Prefix sum of current votes
    vector<ll> prefix_sum(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i].votes;
    }

    ll total_remaining = K - prefix_sum[N];
    vector<ll> result(N);

    for (ll i = 0; i < N; ++i) {
        ll left = 0, right = total_remaining;
        ll answer = -1;

        while (left <= right) {
            ll mid = (left + right) / 2;
            ll target_votes = A[i].votes + mid;

            // Binary search to find how many candidates have strictly more votes than target
            ll low = 0, high = N;
            while (low < high) {
                ll m = (low + high) / 2;
                if (A[m].votes > target_votes)
                    high = m;
                else
                    low = m + 1;
            }
            ll num_strictly_higher = N - low;

            // We need at most M-1 candidates to have strictly more votes than us
            if (num_strictly_higher < M) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        result[A[i].idx] = (answer == -1 ? -1 : max(0LL, answer));
    }

    for (ll i = 0; i < N; ++i)
        cout << result[i] << " ";
    cout << "\n";

    return 0;
}