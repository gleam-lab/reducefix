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
    ll total = accumulate(all(A), 0LL);
    ll remaining = K - total;
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A = A;
    sort(all(sorted_A));
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = sorted_A[i] + prefix[i];
    }
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = A[i] + mid;
            auto it = upper_bound(all(sorted_A), new_votes);
            int cnt = sorted_A.end() - it;
            if (cnt < M) {
                best = mid;
                high = mid - 1;
            } else {
                ll required = 0;
                int pos = it - sorted_A.begin();
                int start_pos = N - M;
                if (pos <= start_pos) {
                    required = prefix[N] - prefix[start_pos] - (new_votes + 1) * (N - start_pos);
                    if (required < 0) required = 0;
                } else {
                    required = prefix[N] - prefix[pos] - (new_votes + 1) * (N - pos);
                    if (required < 0) required = 0;
                }
                if (required <= remaining - mid) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[i] = best;
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}