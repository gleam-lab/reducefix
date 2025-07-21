#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort A in ascending order to help determine thresholds efficiently
    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    vector<ll> ans(N);

    for (int i = 0; i < N; ++i) {
        ll my_votes = A[i];

        // Binary search on the minimum additional votes needed
        ll low = 0, high = K, result = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll required = mid;

            // We need to ensure that fewer than M candidates have more votes than my_votes + mid
            // So find how many candidates could potentially have more votes
            ll target = my_votes + mid + 1;
            ll extra_needed = 0;

            // Use binary search to find how many candidates have votes >= target
            int cnt = N - (upper_bound(all(sorted_A), target - 1) - sorted_A.begin());

            // If current candidate already has enough votes to be in top M, skip
            if (cnt < M) {
                result = required;
                high = mid - 1;
            } else {
                // Compute how many extra votes are needed to raise at least (cnt - M + 1) candidates below target
                auto it = upper_bound(all(sorted_A), my_votes + mid);
                while (it != sorted_A.end() && cnt >= M) {
                    ll diff = *it - (my_votes + mid) + 1;
                    extra_needed += diff;
                    ++it;
                    --cnt;
                }

                if (extra_needed <= K) {
                    result = required;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        if (result != -1 && result <= K) {
            ans[i] = result;
        } else {
            ans[i] = -1;
        }
    }

    for (auto x : ans) cout << x << ' ';
}