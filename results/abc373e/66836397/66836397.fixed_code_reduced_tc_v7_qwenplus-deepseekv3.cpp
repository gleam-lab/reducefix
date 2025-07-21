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
    ll remaining = K - total;

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    vector<ll> res(N);
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll left = 0, right = remaining;
        ll ans = -1;

        while (left <= right) {
            ll mid = left + (right - left) / 2;
            ll new_votes = current + mid;

            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes);
            int pos = it - sorted_A.begin();
            int upper_count = N - pos;

            if (upper_count < M) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (ans != -1) {
            // Now check if the remaining votes can be distributed such that 'ans' is sufficient
            ll new_votes = current + ans;
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes);
            int pos = it - sorted_A.begin();
            int upper_count = N - pos;

            if (upper_count < M) {
                res[i] = ans;
            } else {
                res[i] = -1;
            }
        } else {
            res[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " \n"[i == N - 1];
    }

    return 0;
}