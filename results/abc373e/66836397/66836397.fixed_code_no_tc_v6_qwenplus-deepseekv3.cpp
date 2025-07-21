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

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    for (int i = 0; i < N; ++i) {
        ll a_i = A[i];
        ll low = 0, high = rem;
        ll ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_a_i = a_i + mid;
            ll pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_a_i) - sorted_A.begin();
            ll upper_cnt = N - pos;
            if (upper_cnt < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << " \n"[i == N - 1];
    }

    return 0;
}