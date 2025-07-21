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
    ll sum_A = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum_A += A[i];
    }
    ll remaining = K - sum_A;
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
        ll low = 0, high = remaining + A[i], best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = A[i] + mid;
            int pos = upper_bound(all(sorted_A), total) - sorted_A.begin();
            int count = N - pos;
            if (count < M) {
                best = mid;
                high = mid - 1;
            } else {
                ll required = 0;
                int start = pos;
                int end = N - M;
                if (start <= end) {
                    required = (sorted_A[end] - total) * (end - start + 1);
                    required += (prefix[N] - prefix[end + 1]) - total * (N - (end + 1));
                } else {
                    required = (prefix[N] - prefix[pos]) - total * (N - pos);
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
        if (ans[i] == -1) {
            cout << -1 << ' ';
        } else {
            cout << max(0LL, ans[i]) << ' ';
        }
    }
    cout << '\n';
    return 0;
}