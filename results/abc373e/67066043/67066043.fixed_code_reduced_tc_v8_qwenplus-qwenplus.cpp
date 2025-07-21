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

    // Create index ordering by current votes
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return A[i] < A[j]; });

    // Sorted votes
    vector<ll> sortedA = A;
    sort(all(sortedA));

    // Prefix sum of sortedA
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    vector<ll> result(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx]; // original index
        ll low = 0, high = K + 1;
        ll targetVotes = sortedA[idx];

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll required = 0;

            // We want candidate i to be in top M after adding mid votes
            // So we ensure that at least (N - M) candidates have <= A[i]+mid votes

            // Binary search to find how many candidates have votes > A[i] + mid
            ll threshold = A[i] + mid + 1;
            int pos = upper_bound(all(sortedA), A[i] + mid) - sortedA.begin();

            // Need to make sure the top (N - M) candidates have <= A[i]+mid votes
            int start = max(0, (N - M));

            if (pos >= start) {
                // Those from start to pos-1 need to be raised to A[i]+mid+1
                ll total = (ll)(pos - start) * (A[i] + mid + 1);
                ll current = prefix[pos] - prefix[start];
                required = total - current;
            }

            // If i is among those we're trying to suppress, subtract one
            if (start <= idx && idx < pos) {
                required--;
            }

            if (required <= K) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Check if solution exists
        if (high >= 0) {
            result[i] = high + 1;
            if (result[i] > K) result[i] = -1;
        } else {
            result[i] = 0;
            // Verify if already winning with current votes
            ll threshold = A[i];
            int cnt = N - (upper_bound(all(sortedA), threshold) - sortedA.begin());
            if (cnt < M) result[i] = 0;
            else result[i] = -1;
        }
    }

    for (auto x : result) cout << x << ' ';
    cout << '\n';

    return 0;
}