#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

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

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    ll remaining = K - prefix[N];

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = sorted_A[i] + mid;
            ll total_used = mid;

            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes);
            int cnt = sorted_A.end() - it;

            if (cnt >= M) {
                low = mid + 1;
                continue;
            }

            int pos = it - sorted_A.begin();
            ll sum = prefix[pos] - prefix[i + 1];
            ll needed = new_votes * (pos - (i + 1)) - sum;
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
        if (res[i] == -1) {
            // Check if already elected
            ll total_votes = A[i] + (K - prefix[N]);
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (A[j] > total_votes) {
                    cnt++;
                }
            }
            if (cnt < M) {
                res[i] = 0;
            }
        }
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}