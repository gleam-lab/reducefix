#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    // Create a list of candidate indices sorted by their current votes
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return A[i] < A[j]; });

    // Prepare prefix sums of the sorted votes
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    vector<ll> result(N, -1);

    for (int i = 0; i < N; ++i) {
        int pos = i;  // position in sorted array
        ll my_votes = A[idx[i]];

        // Binary search for minimum X additional votes needed
        ll low = 0, high = K;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total_needed = 0;

            // Find how many candidates have more than my_votes + mid
            ll target = my_votes + mid;

            // Use binary search to find how many candidates have votes > target
            int left = lower_bound(sorted_A.begin(), sorted_A.end(), target + 1) - sorted_A.begin();
            int stronger = N - left;

            // If already among top M, then we are guaranteed to win
            if (stronger < M) {
                answer = mid;
                high = mid - 1;
                continue;
            }

            // We need to overtake enough candidates to be in top N-M
            int to_force = stronger - (M - 1); // number of candidates we must surpass

            // We can only use up to remaining K votes
            ll extra = 0;
            int count = 0;

            // Start from highest and move down to those we need to surpass
            for (int j = N - 1; j >= 0 && count < to_force; --j) {
                if (sorted_A[j] <= my_votes) continue;
                ll need = max(0LL, sorted_A[j] - target + 1);
                extra += need;
                ++count;
                if (extra + mid > K) break;
            }

            if (extra <= K) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (answer != -1)
            result[idx[i]] = answer;
        else
            result[idx[i]] = -1;
    }

    for (auto x : result)
        cout << x << " ";
}