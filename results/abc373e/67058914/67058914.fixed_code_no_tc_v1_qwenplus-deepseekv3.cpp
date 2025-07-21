#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return A[i] < A[j];
    });

    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[idx[i]];
    }

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    ll remaining = K - prefix[N];
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll low = 0;
        ll high = remaining + sorted_A[i];
        ll best = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = sorted_A[i] + mid;
            ll total_used = mid;

            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_val) - sorted_A.begin();
            int cnt_below = pos - (i < pos ? 1 : 0);
            int cnt_above = N - pos;

            if (cnt_above >= M) {
                low = mid + 1;
                continue;
            }

            ll needed = 0;
            if (pos < N) {
                ll sum_above = prefix[N] - prefix[pos];
                needed = new_val * cnt_above - sum_above;
                if (needed < 0) needed = 0;
            }

            if (total_used + needed <= remaining) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[idx[i]] = best;
    }

    for (int i = 0; i < N; ++i) {
        cout << (res[i] == -1 ? -1 : max(0LL, res[i])) << ' ';
    }

    return 0;
}