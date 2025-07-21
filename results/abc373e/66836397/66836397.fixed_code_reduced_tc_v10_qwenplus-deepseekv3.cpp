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

    vector<ll> B = A;
    sort(B.begin(), B.end());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + B[i];
    }

    for (int i = 0; i < N; ++i) {
        ll a_i = A[i];
        ll left = 0, right = rem;
        ll res = -1;

        while (left <= right) {
            ll mid = (left + right) / 2;
            ll new_a_i = a_i + mid;

            ll pos = upper_bound(B.begin(), B.end(), new_a_i) - B.begin();
            ll upper_cnt = N - pos;

            if (upper_cnt < M) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (res != -1) {
            ll new_a_i = a_i + res;
            ll pos = upper_bound(B.begin(), B.end(), new_a_i) - B.begin();
            ll upper_cnt = N - pos;

            if (upper_cnt >= M) {
                res = -1;
            } else {
                ll needed = 0;
                if (pos > N - M) {
                    ll start = N - M;
                    ll can_use = max(0LL, new_a_i - B[start] + 1);
                    needed = can_use * (pos - start) - (prefix[pos] - prefix[start] - (upper_cnt ? a_i : 0));
                }
                if (needed <= rem - res) {
                    res = res;
                } else {
                    res = -1;
                }
            }
        }

        cout << res << " \n"[i == N - 1];
    }

    return 0;
}