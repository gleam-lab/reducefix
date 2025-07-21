#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }
    ll remaining = K - sum;

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix_sum(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    for (ll i = 0; i < N; ++i) {
        ll a_i = A[i];
        ll low = 0, high = remaining, ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_a_i = a_i + mid;

            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_a_i);
            ll upper_cnt = sorted_A.end() - it;
            
            if (upper_cnt < M) {
                ans = mid;
                high = mid - 1;
            } else {
                ll pos = it - sorted_A.begin();
                ll lower_pos = pos - (M - 1);
                if (lower_pos <= 0) {
                    low = mid + 1;
                    continue;
                }
                ll required = new_a_i * (M - 1) - (prefix_sum[pos] - prefix_sum[lower_pos]);
                if (required <= remaining - mid) {
                    low = mid + 1;
                } else {
                    ans = mid;
                    high = mid - 1;
                }
            }
        }
        cout << ans << (i == N - 1 ? "\n" : " ");
    }
    return 0;
}