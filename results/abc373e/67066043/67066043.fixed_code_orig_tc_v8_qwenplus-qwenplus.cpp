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

    // If M >= N, everyone is elected
    if (M >= N) {
        cout << string(N, '0') << endl;
        return 0;
    }

    // Create a list of indices sorted by A[i]
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int x, int y) { return A[x] < A[y]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[ord[i]];
    }

    // Prefix sum array
    vector<ll> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    vector<ll> C(N, -1);

    // For each candidate, compute the minimum needed votes
    for (int i = 0; i < N; ++i) {
        ll ai = A[i];

        // Binary search on required additional votes X
        ll low = 0, high = K;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;

            // Total votes candidate has after getting mid more
            ll total = ai + mid;

            // Find how many candidates have strictly greater votes than this
            int idx = upper_bound(sorted_A.begin(), sorted_A.end(), total) - sorted_A.begin();

            // Remaining candidates that can have more votes than this one
            int remaining = N - idx;

            // How many candidates are allowed to have more votes?
            if (remaining < M) {
                answer = mid;
                high = mid - 1;
            } else {
                // Need to increase this candidate's votes more
                low = mid + 1;
            }
        }

        if (answer <= K) {
            C[i] = max<ll>(0, answer);
        } else {
            C[i] = -1;
        }
    }

    // Output result
    for (auto x : C) cout << x << " ";
    cout << endl;
}