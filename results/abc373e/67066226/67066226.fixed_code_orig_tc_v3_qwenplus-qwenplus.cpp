#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }

    ll remaining = K - total;

    // To sort candidates by initial votes
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return A[i] < A[j]; });

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    // Prefix sums for efficient range queries
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    vector<ll> result(N, -1);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = A[i] + mid;

            // Find how many candidates currently have more than target
            // Use binary search on sortedA
            int pos = lower_bound(sortedA.begin(), sortedA.end(), target + 1) - sortedA.begin();

            // We want to ensure that at most M-1 candidates have more votes than this one
            // So, we assume the worst: the next highest M candidates will try to maximize their votes

            ll required = 0;

            // The top M candidates above current one
            int upper = N - M;
            if (pos > upper) {
                // Need to raise those M candidates up to current candidate's level
                required = (N - M) * (target + 1) - (prefix[N - M] - prefix[0]);
            }

            if (required <= remaining - mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        result[i] = ans == -1 ? -1 : ans;
    }

    // Now remap results back to original order
    vector<ll> output(N);
    for (int i = 0; i < N; ++i) {
        output[idx[i]] = result[i];
    }

    for (ll val : output) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}