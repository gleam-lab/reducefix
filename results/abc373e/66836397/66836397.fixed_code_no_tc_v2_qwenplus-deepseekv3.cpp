#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (ll &a : A) {
        cin >> a;
        total += a;
    }
    ll rem = K - total;

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = rem;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            auto it = upper_bound(sortedA.begin(), sortedA.end(), new_votes);
            ll cnt = sortedA.end() - it;

            if (cnt < M) {
                ans = mid;
                high = mid - 1;
            } else {
                ll needed = 0;
                ll pos = it - sortedA.begin();
                ll start = pos;
                ll end = N - (M - 1);
                if (end <= start) {
                    needed = 0;
                } else {
                    needed = (new_votes + 1) * (end - start) - (prefix[end] - prefix[start]);
                }
                if (needed <= rem - mid) {
                    low = mid + 1;
                } else {
                    ans = mid;
                    high = mid - 1;
                }
            }
        }

        cout << ans << " \n"[i == N - 1];
    }

    return 0;
}