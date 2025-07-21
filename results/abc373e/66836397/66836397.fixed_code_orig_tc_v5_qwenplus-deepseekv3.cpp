#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll rem = K;
    for (ll &a : A) {
        cin >> a;
        rem -= a;
    }

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = rem;
        ll ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = A[i] + mid;
            ll pos = upper_bound(sorted_A.begin(), sorted_A.end(), total) - sorted_A.begin();
            ll count = N - pos;
            if (count < M) {
                ll required = 0;
                if (count > 0) {
                    ll start = pos - (M - count);
                    if (start < 0) start = 0;
                    required = (total + 1) * (pos - start) - (prefix[pos] - prefix[start]);
                }
                if (required <= rem - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        cout << (ans == -1 ? -1 : ans) << " \n"[i == N - 1];
    }

    return 0;
}