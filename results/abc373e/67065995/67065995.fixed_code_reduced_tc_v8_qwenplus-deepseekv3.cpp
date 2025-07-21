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
    ll sum_A = accumulate(all(A), 0LL);
    ll remaining = K - sum_A;
    if (remaining < 0) {
        remaining = 0;
    }

    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[ord[i]];
    }
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        ll current = sorted_A[idx];
        ll low = 0, high = remaining;
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = current + mid;
            int pos = upper_bound(all(sorted_A), new_val) - sorted_A.begin();
            if (pos >= N - M + 1) {
                best_X = mid;
                high = mid - 1;
                continue;
            }
            ll needed = 0;
            int count = N - M - pos;
            if (count > 0) {
                ll start = N - M;
                ll end = start + count;
                needed = new_val * count - (prefix[end] - prefix[start]);
            }
            if (needed <= remaining - mid) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[ord[idx]] = best_X;
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}