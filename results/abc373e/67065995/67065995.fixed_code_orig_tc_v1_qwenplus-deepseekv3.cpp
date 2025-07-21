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
    ll sum_A = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum_A += A[i];
    }
    ll remaining = K - sum_A;
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[ord[i]];
    }
    vector<ll> pref(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        pref[i + 1] = pref[i] + sorted_A[i];
    }
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll current = A[i];
        ll low = 0, high = remaining;
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            int pos = upper_bound(all(sorted_A), new_votes) - sorted_A.begin();
            int needed = max(0, N - M + 1 - pos);
            if (idx >= pos) {
                needed = max(0, N - M - (idx - pos));
            } else {
                needed = max(0, N - M - (pos - idx - 1));
            }
            if (needed <= 0) {
                best_X = mid;
                high = mid - 1;
                continue;
            }
            ll total = 0;
            int start = pos;
            int end = start + needed - 1;
            if (end >= N) {
                end = N - 1;
                needed = end - start + 1;
            }
            if (needed <= 0) {
                best_X = mid;
                high = mid - 1;
                continue;
            }
            total = needed * new_votes - (pref[end + 1] - pref[start]);
            if (total <= remaining - mid) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best_X != -1) {
            ans[i] = best_X;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}