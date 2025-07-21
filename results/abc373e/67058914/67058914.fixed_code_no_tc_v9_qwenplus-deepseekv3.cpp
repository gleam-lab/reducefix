#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> indices(N);
    for (int i = 0; i < N; ++i) {
        indices[i] = i;
    }

    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return A[i] < A[j];
    });

    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[indices[i]];
    }

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    ll total_used = prefix[N];
    ll remaining = K - total_used;

    vector<ll> res(N);

    for (int i = 0; i < N; ++i) {
        ll low = 0;
        ll high = remaining;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = sorted_A[i] + mid;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_val) - sorted_A.begin();
            int cnt = N - pos;

            if (cnt >= M) {
                low = mid + 1;
                continue;
            }

            ll max_can_assign = remaining - mid;
            ll sum_others = prefix[pos] - prefix[i + 1];
            ll needed = new_val * (pos - (i + 1)) - sum_others;
            if (needed <= max_can_assign) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[indices[i]] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << (res[i] == -1 ? -1 : res[i]) << ' ';
    }

    return 0;
}