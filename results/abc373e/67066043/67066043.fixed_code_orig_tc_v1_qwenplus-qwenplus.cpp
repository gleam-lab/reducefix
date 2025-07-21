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
    }

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);

    // Sort candidates by current votes
    sort(idx.begin(), idx.end(), [&](int a, int b) { return A[a] < A[b]; });
    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefixSum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + sortedA[i];
    }

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        int pos = i; // position in sorted list
        ll current = A[i];

        // Binary search on required additional votes
        ll low = 0, high = K + 1;
        while (low < high) {
            ll mid = (low + high) / 2;

            ll totalNeeded = 0;
            ll target = current + mid;

            // Find how many candidates have more than or equal to our target
            int cnt = N - (upper_bound(sortedA.begin(), sortedA.end(), target) - sortedA.begin());

            if (cnt < M) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        // After binary search, check if low is valid
        ll totalUsed = 0;
        ll finalScore = current + low;

        // We need to ensure that at most M-1 candidates have score > finalScore
        // So we make sure candidate i is among the top M

        // Compute how many candidates are strictly above finalScore
        int better = N - (upper_bound(sortedA.begin(), sortedA.end(), finalScore) - sortedA.begin());

        if (better < M) {
            res[i] = 0;
        } else {
            // Need to raise this candidate so that only M-1 others have higher scores
            // So find smallest X such that when candidate gets X, only M-1 candidates have higher votes

            low = 0, high = K + 1;
            while (low < high) {
                ll mid = (low + high) / 2;
                ll newScore = A[i] + mid;

                // Count number of candidates with votes > newScore
                int cnt = N - (upper_bound(sortedA.begin(), sortedA.end(), newScore) - sortedA.begin());

                if (cnt < M) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }

            // Final check
            ll newScore = A[i] + low;
            int cnt = N - (upper_bound(sortedA.begin(), sortedA.end(), newScore) - sortedA.begin());
            if (cnt < M && low <= K) {
                res[i] = low;
            } else {
                res[i] = -1;
            }
        }
    }

    for (auto x : res) cout << x << ' ';
    cout << '\n';
}