#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define int long long

const int MAXN = 2e5 + 5;

int N, M;
int A[MAXN];
int sortedA[MAXN];
int prefixSum[MAXN];

// Compute the minimum additional votes candidate with current votes 'base' needs
int solveFor(int base, int remainingVotes) {
    int l = 0, r = remainingVotes, ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        // Find how many candidates already have more than base + mid
        int idx = upper_bound(sortedA, sortedA + N, base + mid) - sortedA;

        int cnt = N - idx; // candidates who currently have > base + mid

        if (cnt >= M) {
            // Already too many candidates above us, need more aggressive strategy
            l = mid + 1;
            continue;
        }

        // Need (M - cnt) candidates from remaining ones to not exceed us
        int need = max(0LL, M - cnt - 1);
        if (need == 0) {
            ans = mid;
            r = mid - 1;
            continue;
        }

        // Take top "need" from [max(0, N - need), N)
        int takeFrom = max(0LL, N - need);
        int totalExtra = (base + mid) * need;

        if (prefixSum[N] - prefixSum[takeFrom] <= totalExtra) {
            // We can cap those need candidates below us
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Special case: any candidate will win automatically
    if (M > N) {
        for (int i = 0; i < N; ++i) cout << 0 << " ";
        cout << "\n";
        return 0;
    }

    // Sort and prepare prefix sums
    copy(A, A + N, sortedA);
    sort(sortedA, sortedA + N);

    prefixSum[0] = 0;
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + sortedA[i];
    }

    for (int i = 0; i < N; ++i) {
        int res = solveFor(A[i], K - A[i]);
        cout << res << " ";
    }

    cout << "\n";

    return 0;
}