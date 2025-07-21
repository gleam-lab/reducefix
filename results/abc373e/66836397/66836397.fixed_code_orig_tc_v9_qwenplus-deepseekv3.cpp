#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum_A = 0;
    for (ll &a : A) {
        cin >> a;
        sum_A += a;
    }
    ll remaining = K - sum_A;

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<ll>());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining, ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = A[i] + mid;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), total, greater<ll>()) - sorted_A.begin();
            if (pos < M) {
                ans = mid;
                high = mid - 1;
                continue;
            }
            ll needed = total * (M - 1) - (prefix[M - 1] - (pos < M - 1 ? 0 : sorted_A[pos - 1]));
            if (needed <= remaining - mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << (ans == -1 ? -1 : ans) << " \n"[i == N - 1];
    }

    return 0;
}