#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MAXN = 2e5 + 10;

int N, M;
i64 K;
i64 A[MAXN], B[MAXN];
i64 prefix[MAXN];

// Function to calculate how many candidates have more votes than x
int countGreater(i64 x, i64* arr, int n) {
    return n - (upper_bound(arr + 1, arr + n + 1, x) - arr - 1);
}

bool isSafe(i64 base, i64 add, i64 rem, i64* sortedA, int n) {
    i64 total = base + add;
    // How many have more than total?
    int idx = upper_bound(sortedA + 1, sortedA + n + 1, total) - sortedA;
    int cntMore = n - idx + 1;
    if (cntMore < M) return true;

    // Need to cap the top (cntMore) candidates to <= total
    i64 needed = 0;
    for (int i = idx; i <= idx + cntMore - M; ++i)
        needed += max(0LL, sortedA[i] - total - 1);
    return needed <= rem;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    if (M >= N) {
        for (int i = 1; i <= N; ++i) cout << 0 << " ";
        cout << "\n";
        return;
    }

    // Copy and sort A
    for (int i = 1; i <= N; ++i) B[i] = A[i];
    sort(B + 1, B + N + 1, greater<i64>());
    for (int i = N; i >= 1; --i) prefix[i] = B[i] + prefix[i + 1];

    i64 totalGiven = 0;
    for (int i = 1; i <= N; ++i) totalGiven += A[i];
    i64 rem = K - totalGiven;

    vector<i64> res(N + 1);

    for (int i = 1; i <= N; ++i) {
        i64 l = 0, r = rem, ans = -1;
        while (l <= r) {
            i64 mid = (l + r) / 2;
            if (isSafe(A[i], mid, rem - mid, B, N)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        res[i] = ans;
    }

    for (int i = 1; i <= N; ++i) cout << res[i] << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}