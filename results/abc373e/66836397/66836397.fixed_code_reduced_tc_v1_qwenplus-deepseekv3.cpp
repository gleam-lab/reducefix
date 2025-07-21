#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) cin >> a;
    ll rem = K - accumulate(A.begin(), A.end(), 0LL);

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    auto can_win = [&](ll candidate, ll X) {
        ll total = A[candidate] + X;
        ll pos = upper_bound(sorted_A.begin(), sorted_A.end(), total) - sorted_A.begin();
        ll upper_cnt = N - pos;
        if (upper_cnt >= M) return false;

        ll needed = M - 1 - upper_cnt;
        if (needed < 0) needed = 0;
        ll start = pos - needed - 1;
        start = max(start, 0LL);
        ll sum = 0;
        if (start < pos) {
            sum = (total + 1) * (pos - start) - (prefix_sum[pos] - prefix_sum[start]);
        }
        return sum <= rem - X;
    };

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = rem;
        ll ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (can_win(i, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << (ans != -1 ? ans : -1) << " \n"[i == N - 1];
    }

    return 0;
}