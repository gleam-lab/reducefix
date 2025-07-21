#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (ll &a : A) {
        cin >> a;
        sum += a;
    }
    ll rem = K - sum;

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

            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_a_i);
            ll cnt_greater = sorted_A.end() - it;
            
            if (cnt_greater < M) {
                ans = mid;
                high = mid - 1;
                continue;
            }

            ll pos = it - sorted_A.begin();
            ll start = pos - (M - 1 - cnt_greater);
            if (start <= 0) {
                low = mid + 1;
                continue;
            }

            ll required = new_a_i * (M - cnt_greater - 1) - (prefix[pos] - prefix[pos - (M - cnt_greater - 1)]);
            if (required <= rem - mid) {
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